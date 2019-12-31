/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2017-12-14
# UpdateTime: 2019-12-31
# Info: Qt（C++）调用工业相机Basler的SDK使用示例
# Url:https://shazhenyu.blog.csdn.net/article/details/78844664
# Github:https://github.com/ShaShiDiZhuanLan/Demo_BaslerCamera_Qt
#
#-------------------------------------------------*/
#include "sbaslercameracontrol.h"
#include <QDateTime>
#include <QDebug>

SBaslerCameraControl::SBaslerCameraControl(QObject *parent) : QObject(parent)
{
}

SBaslerCameraControl::~SBaslerCameraControl()
{
}

void SBaslerCameraControl::initSome()
{
    qDebug() << "SBaslerCameraControl: PylonInitialize initSome" ;
    PylonInitialize();
    CTlFactory &TlFactory = CTlFactory::GetInstance();
    TlInfoList_t lstInfo;
    int n = TlFactory.EnumerateTls(lstInfo);

    TlInfoList_t::const_iterator it;
    for ( it = lstInfo.begin(); it != lstInfo.end(); ++it ) {
        qDebug() << "FriendlyName: " << it->GetFriendlyName() << "FullName: " << it->GetFullName();
        qDebug() << "VendorName: " << it->GetVendorName() << "DeviceClass: " << it->GetDeviceClass() ;
    }
    UpdateCameraList();
    emit sigCameraCount(n);
    qDebug() << "SBasler Camera Count: " << n;
}

void SBaslerCameraControl::deleteAll()
{
    //停止采集
    if(m_isOpenAcquire) {
        StopAcquire();
    }
    //关闭摄像头
    CloseCamera();
    //关闭库
    qDebug() << "SBaslerCameraControl deleteAll: PylonTerminate" ;
    PylonTerminate();
    qDebug() << "SBaslerCameraControl deleteAll: Close" ;
}

QStringList SBaslerCameraControl::cameras()
{
    return m_cameralist;
}

void SBaslerCameraControl::UpdateCameraList()
{
    CTlFactory& TLFactory = CTlFactory::GetInstance();
    ITransportLayer * pTl = TLFactory.CreateTl("BaslerGigE");
    DeviceInfoList_t devices;
    int n = pTl->EnumerateDevices(devices);
    CInstantCameraArray cameraArray(devices.size());
    if(n == 0) {
        qDebug() << "Cannot find Any camera!";
        return;
    }
    for (int i=0 ; i<cameraArray.GetSize() ; i++) {
        cameraArray[i].Attach(TLFactory.CreateDevice(devices[i]));
        string sn = cameraArray[i].GetDeviceInfo().GetSerialNumber();
        m_cameralist << QString::fromStdString(sn);
    }
    emit sigCameraUpdate(m_cameralist);
}

void SBaslerCameraControl::CopyToImage(CGrabResultPtr pInBuffer, QImage &OutImage)
{
    try {
        uchar* buff = (uchar*)pInBuffer->GetBuffer();
        int nHeight = pInBuffer->GetHeight();
        int nWidth = pInBuffer->GetWidth();
        if(m_size != QSize(nWidth, nHeight)) {
            m_size = QSize(nWidth, nHeight);
            emit sigSizeChange(m_size);
        }
        QImage imgBuff(buff, nWidth, nHeight, QImage::Format_Indexed8);
        OutImage = imgBuff;
        if(pInBuffer->GetPixelType() == PixelType_Mono8) {
            uchar* pCursor = OutImage.bits();
            if ( OutImage.bytesPerLine() != nWidth ) {
                for ( int y=0; y<nHeight; ++y ) {
                    pCursor = OutImage.scanLine( y );
                    for ( int x=0; x<nWidth; ++x ) {
                        *pCursor =* buff;
                        ++pCursor;
                        ++buff;
                    }
                }
            } else {
                memcpy( OutImage.bits(), buff, nWidth * nHeight );
            }
        }
    } catch (GenICam::GenericException &e) {
//        OutputDebugString(L"CopyToImage\n");
        qDebug() << "CopyToImage Error:" << QString(e.GetDescription());
//        OutputDebugString(LPCWSTR(e.GetDescription()));
    }
}

void SBaslerCameraControl::onTimerGrabImage()
{
    if(m_isOpenAcquire) {
        QImage image;
        GrabImage(image, 5);
        if(!image.isNull()) {
            emit sigCurrentImage(image);
        }
        QTimer::singleShot(5, this, SLOT(onTimerGrabImage()));
    }
}

int SBaslerCameraControl::OpenCamera(QString cameraSN)
{
    try {
        CDeviceInfo cInfo;
        String_t str = String_t(cameraSN.toStdString().c_str());
        cInfo.SetSerialNumber(str);
        m_basler.Attach(CTlFactory::GetInstance().CreateDevice(cInfo));
        m_basler.Open();
        //获取触发模式
        getFeatureTriggerSourceType();
        m_isOpen = true;
    } catch (GenICam::GenericException &e) {
//        OutputDebugString(L"OpenCamera Error\n");
        qDebug() << "OpenCamera Error" << QString(e.GetDescription());
        m_isOpen = false;
        return -2;
    }
    return 0;
}

int SBaslerCameraControl::CloseCamera()
{
    if(!m_isOpen) {
        return -1;
    }
    try {
        if(m_basler.IsOpen()) {
            m_basler.DetachDevice();
            m_basler.Close();
        }
    } catch (GenICam::GenericException &e) {
//        OutputDebugString(LPCWSTR(e.GetDescription()));
        qDebug() << "CloseCamera Error:" << QString(e.GetDescription());
        return -2;
    }
    return 0;
}

void SBaslerCameraControl::setExposureTime(double time)
{
    SetCamera(Type_Basler_ExposureTimeAbs, time);
}

int SBaslerCameraControl::getExposureTime()
{
    return QString::number(GetCamera(Type_Basler_ExposureTimeAbs)).toInt();
}

int SBaslerCameraControl::getExposureTimeMin()
{
    return DOUBLE_MIN;
}

int SBaslerCameraControl::getExposureTimeMax()
{
    return DOUBLE_MAX;
}

void SBaslerCameraControl::setFeatureTriggerSourceType(QString type)
{
    //停止采集
    if(m_isOpenAcquire) {
        StopAcquire();
    }
    if(type == "Freerun") {
        SetCamera(Type_Basler_Freerun);
    } else if(type == "Line1"){
        SetCamera(Type_Basler_Line1);
    }
}

QString SBaslerCameraControl::getFeatureTriggerSourceType()
{
    INodeMap &cameraNodeMap = m_basler.GetNodeMap();
    CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
    ptrTriggerSel->FromString("FrameStart");
    CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
    ptrTrigger->SetIntValue(1);
    CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode ("TriggerSource");

    String_t str = ptrTriggerSource->ToString();
    m_currentMode = QString::fromLocal8Bit(str.c_str());
    return m_currentMode;
}

void SBaslerCameraControl::setFeatureTriggerModeType(bool on)
{
    INodeMap &cameraNodeMap = m_basler.GetNodeMap();
    CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
    ptrTriggerSel->FromString("FrameStart");
    CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
    ptrTrigger->SetIntValue(on?1:0);
}

bool SBaslerCameraControl::getFeatureTriggerModeType()
{
    INodeMap &cameraNodeMap = m_basler.GetNodeMap();
    CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
    ptrTriggerSel->FromString("FrameStart");
    CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
    return ptrTrigger->GetIntValue() == 1;
}

void SBaslerCameraControl::SetCamera(SBaslerCameraControl::SBaslerCameraControl_Type index, double tmpValue)
{
    INodeMap &cameraNodeMap = m_basler.GetNodeMap();
    switch (index) {
    case Type_Basler_Freerun: {
        CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
        ptrTriggerSel->FromString("FrameStart");
        CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
#ifdef Real_Freerun
        ptrTrigger->SetIntValue(0);
#else //Software
        ptrTrigger->SetIntValue(1);
        CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode ("TriggerSource");
        ptrTriggerSource->FromString("Software");
#endif
    } break;
    case Type_Basler_Line1: {
        CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
        ptrTriggerSel->FromString("FrameStart");
        CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
        ptrTrigger->SetIntValue(1);
        CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode ("TriggerSource");
        ptrTriggerSource->FromString("Line1");
    } break;
    case Type_Basler_ExposureTimeAbs: {
        const CFloatPtr exposureTime = cameraNodeMap.GetNode("ExposureTimeAbs");
        exposureTime->SetValue(tmpValue);
    } break;
    case Type_Basler_GainRaw: {
        const CIntegerPtr cameraGen = cameraNodeMap.GetNode("GainRaw");
        cameraGen->SetValue(tmpValue);
    } break;
    case Type_Basler_AcquisitionFrameRateAbs: {
        const CBooleanPtr frameRate = cameraNodeMap.GetNode("AcquisitionFrameRateEnable");
        frameRate->SetValue(TRUE);
        const CFloatPtr frameRateABS = cameraNodeMap.GetNode("AcquisitionFrameRateAbs");
        frameRateABS->SetValue(tmpValue);
    } break;
    case Type_Basler_Width: {
        const CIntegerPtr widthPic = cameraNodeMap.GetNode("Width");
        widthPic->SetValue(tmpValue);
    } break;
    case Type_Basler_Height: {
        const CIntegerPtr heightPic = cameraNodeMap.GetNode("Height");
        heightPic->SetValue(tmpValue);
    } break;
    case Type_Basler_LineSource: {
        CEnumerationPtr  ptrLineSource = cameraNodeMap.GetNode ("LineSource");
        ptrLineSource->SetIntValue(2);
    } break;
    default:
        break;
    }
}

double SBaslerCameraControl::GetCamera(SBaslerCameraControl::SBaslerCameraControl_Type index)
{
    INodeMap &cameraNodeMap = m_basler.GetNodeMap();
    switch (index) {
    case Type_Basler_ExposureTimeAbs: {
        const CFloatPtr exposureTime = cameraNodeMap.GetNode("ExposureTimeAbs");
        return exposureTime->GetValue();
    } break;
    case Type_Basler_GainRaw: {
        const CIntegerPtr cameraGen = cameraNodeMap.GetNode("GainRaw");
        return cameraGen->GetValue();
    } break;
    case Type_Basler_AcquisitionFrameRateAbs: {
        const CBooleanPtr frameRate = cameraNodeMap.GetNode("AcquisitionFrameRateEnable");
        frameRate->SetValue(TRUE);
        const CFloatPtr frameRateABS = cameraNodeMap.GetNode("AcquisitionFrameRateAbs");
        return frameRateABS->GetValue();
    } break;
    case Type_Basler_Width: {
        const CIntegerPtr widthPic = cameraNodeMap.GetNode("Width");
        return widthPic->GetValue();
    } break;
    case Type_Basler_Height: {
        const CIntegerPtr heightPic = cameraNodeMap.GetNode("Height");
        return heightPic->GetValue();
    } break;
    default:
        return -1;
        break;
    }
}

long SBaslerCameraControl::StartAcquire()
{
    m_isOpenAcquire = true;
    try {
        qDebug() << "SBaslerCameraControl StartAcquire" << m_currentMode;
         if(m_currentMode == "Freerun")  {
             m_basler.StartGrabbing(GrabStrategy_LatestImageOnly,GrabLoop_ProvidedByInstantCamera);
         } else if(m_currentMode == "Software") {
             m_basler.StartGrabbing(GrabStrategy_LatestImageOnly);
             onTimerGrabImage();
         } else if(m_currentMode == "Line1") {
             m_basler.StartGrabbing(GrabStrategy_OneByOne);
             onTimerGrabImage();
         } else if(m_currentMode == "Line2") {
             m_basler.StartGrabbing(GrabStrategy_OneByOne);
         }
    } catch (GenICam::GenericException &e) {
//        OutputDebugString(L"StartAcquire error:");
        qDebug() << "StartAcquire Error:" << QString(e.GetDescription());
        return -2;
    }
    return 0;
}

long SBaslerCameraControl::StopAcquire()
{
    m_isOpenAcquire = false;
    qDebug() << "SBaslerCameraControl StopAcquire";
    try {
        if (m_basler.IsGrabbing()) {
            m_basler.StopGrabbing();
        }
    } catch (GenICam::GenericException &e) {
//        OutputDebugString(LPCWSTR(e.GetDescription()));
        qDebug() << "StopAcquire Error:" << QString(e.GetDescription());
        return -2;
    }
    return 0;
}

long SBaslerCameraControl::GrabImage(QImage &image, int timeout)
{
    try  {
        if (!m_basler.IsGrabbing()) {
            StartAcquire();
        }
        CGrabResultPtr ptrGrabResult;
        if(m_currentMode == "Freerun")  {
        } else if(m_currentMode == "Software") {
            if (m_basler.WaitForFrameTriggerReady(1000, TimeoutHandling_Return)) {
                m_basler.ExecuteSoftwareTrigger();
                m_basler.RetrieveResult(timeout, ptrGrabResult,TimeoutHandling_Return);
            }
        } else if(m_currentMode == "Line1") {
            m_basler.RetrieveResult(timeout, ptrGrabResult, TimeoutHandling_Return);
        } else if(m_currentMode == "Line2") {
            m_basler.RetrieveResult(timeout, ptrGrabResult, TimeoutHandling_Return);
        }
        if(ptrGrabResult == NULL) {
            return -5;
        }
        if (ptrGrabResult->GrabSucceeded()) {
            qDebug() << "what: ptrGrabResult GrabSucceeded";
            if (!ptrGrabResult.IsValid()) { OutputDebugString(L"GrabResult not Valid Error\n"); return -1; }
            EPixelType pixelType = ptrGrabResult->GetPixelType();
            switch (pixelType) {
            case PixelType_Mono8: {
                CopyToImage(ptrGrabResult, image);
            } break;
            case PixelType_BayerRG8: { qDebug() << "what: PixelType_BayerRG8"; }  break;
            default:  qDebug() << "what: default"; break;
            }
        } else {
            qDebug() << "Grab Error!!!";
//            OutputDebugString(L"Grab Error!!!");
            return -3;
        }
    } catch (GenICam::GenericException &e) {
//        OutputDebugString(L"GrabImage Error\n");
        qDebug() << "GrabImage Error:" << QString(e.GetDescription());
//        OutputDebugString((e.GetDescription()));
        return -2;
    }  catch(...)  {
        OutputDebugString(L"ZP 11 Shot GetParam Try 12 No know Error\n");
        return -1;
    }
    return 0;
}
