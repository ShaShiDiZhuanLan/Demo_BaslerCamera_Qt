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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_control = new SBaslerCameraControl(this);
    m_control->initSome();
    connect(m_control, &SBaslerCameraControl::sigCurrentImage, [=](QImage img){
        QPixmap pix = QPixmap::fromImage(img).transformed(m_matrix);
        ui->label->setPixmap(pix);
        ui->widget_pic->setFixedSize(pix.size());
    });
    connect(m_control, &SBaslerCameraControl::sigSizeChange, [=](QSize size){
        // 默认大小641,494
        ui->label_size->setText(QString("\345\260\272\345\257\270:%0*%1").arg(QString::number(size.width())).arg(QString::number(size.height()))); // 尺寸
        ui->widget_pic->setFixedSize(size);
    });
    m_control->OpenCamera(m_control->cameras().first());
}

MainWindow::~MainWindow()
{
    m_control->deleteAll();
    delete ui;
}

void MainWindow::on_pushButton_getExTime_clicked()
{
    ui->label_exTime->setText(QString::number(m_control->getExposureTime()));
}

void MainWindow::on_pushButton_SetExTime_clicked()
{
    m_control->setExposureTime(ui->lineEdit_exTime->text().toDouble());
}

void MainWindow::on_pushButton_SetMode_clicked()
{
    m_control->setFeatureTriggerSourceType(ui->lineEdit_SetMode->text());
}

void MainWindow::on_pushButton_GetMode_clicked()
{
    ui->label_Mode->setText(m_control->getFeatureTriggerSourceType());
}

void MainWindow::on_pushButton_CFMode_clicked()
{
    ui->label_CFMode->setText(m_control->getFeatureTriggerModeType()?"Open":"Close");
}

void MainWindow::on_comboBox_CFMode_activated(int index)
{
    m_control->setFeatureTriggerModeType(index == 0);
}

void MainWindow::on_pushButton_Start_clicked()
{
    if(ui->pushButton_Start->text() == "\345\274\200\345\247\213\351\207\207\351\233\206") {// 开始采集
        m_control->StartAcquire();
        ui->pushButton_Start->setText("\347\273\223\346\235\237\351\207\207\351\233\206");// 结束采集
    } else {
        m_control->StopAcquire();
        ui->pushButton_Start->setText("\345\274\200\345\247\213\351\207\207\351\233\206");// 开始采集
    }
}

void MainWindow::on_pushButtonRotate_clicked()
{
    m_matrix.rotate(90);
}
