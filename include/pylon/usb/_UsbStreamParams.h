

//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the PylonUsb Stream Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_UsbStreamParams_PARAMS_H
#define Basler_UsbStreamParams_PARAMS_H

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>

// common node types
#include <GenApi/IBoolean.h>
#include <GenApi/ICategory.h>
#include <GenApi/ICommand.h>
#include <GenApi/IEnumeration.h>
#include <GenApi/IEnumEntry.h>
#include <GenApi/IFloat.h>
#include <GenApi/IInteger.h>
#include <GenApi/IString.h>
#include <GenApi/IRegister.h>

#ifdef __GNUC__
#   undef GCC_VERSION
#   define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#   undef GCC_DIAGNOSTIC_AWARE
#   define GCC_DIAGNOSTIC_AWARE          (GCC_VERSION >= 40200)
#   undef GCC_DIAGNOSTIC_PUSH_POP_AWARE
#   define GCC_DIAGNOSTIC_PUSH_POP_AWARE (GCC_VERSION >= 40600)
#else
#   undef GCC_DIAGNOSTIC_AWARE
#   define GCC_DIAGNOSTIC_AWARE 0
#endif

#ifdef __GNUC__
    // GCC_DIAGNOSTIC_AWARE ensures that the internal deprecated warnings can be ignored by gcc.
    // As a result older gcc will not generate warnings about really used deprecated features.
#   if GCC_DIAGNOSTIC_AWARE
#       define GENAPI_DEPRECATED_FEATURE __attribute__((deprecated))
#   else
#       define GENAPI_DEPRECATED_FEATURE
#   endif
#elif defined(_MSC_VER)
#   define GENAPI_DEPRECATED_FEATURE __declspec(deprecated)
#else
#   define GENAPI_DEPRECATED_FEATURE
#endif

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic push
#   endif
#   pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif


//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UsbStreamParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for Status
    enum StatusEnums
    {
        Status_Closed,  //!<The low level stream grabber is closed.
        Status_Open,  //!<The low level stream grabber is open.
        Status_Grabbing   //!<The low level stream grabber is grabbing.
        
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to the PylonUsb Stream Grabber parameters
    class CUsbStreamParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUsbStreamParams_Params(void);

            //! Destructor
            ~CUsbStreamParams_Params(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

            //! Return the vendor of the camera
            const char* _GetVendorName(void);

            //! Returns the camera model name
            const char* _GetModelName(void);
        
        //! \endcond

    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        
    //! \name Root - Interface to the USB-specific stream parameters.
    //@{
    /*!
        \brief The maximum number of buffers that can be used simultaneously.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &MaxNumBuffer;
    
    //@}
    

    //! \name Root - Interface to the USB-specific stream parameters.
    //@{
    /*!
        \brief The maximum buffer size in bytes that can be registered.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &MaxBufferSize;
    
    //@}
    

    //! \name Root - Interface to the USB-specific stream parameters.
    //@{
    /*!
        \brief Controls the maximum size of USB transfers.

        
        
        The default value is appropriate for most applications. 
        Reducing the value may cause a higher CPU load. USB host adapter drivers may require 
        to decrease the value in case the application fails to receive the image stream. The maximum value 
        for the Maximum Transfer Size depends on the operating system version and may be limited by the host adapter drivers.
        
        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &MaxTransferSize;
    
    //@}
    

    //! \name Root - Interface to the USB-specific stream parameters.
    //@{
    /*!
        \brief The maximum number of requests to be enqueued to the driver.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &NumMaxQueuedUrbs;
    
    //@}
    

    //! \name Root - Interface to the USB-specific stream parameters.
    //@{
    /*!
        \brief The priority of the thread that handles USB requests of the stream interface.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &TransferLoopThreadPriority;
    
    //@}
    

    //! \name Root - Interface to the USB-specific stream parameters.
    //@{
    /*!
        \brief Timeout in ms for payload and trailer transfers.

        
    Timeout in ms for payload and trailer transfers.
    
    
        \b Visibility = Invisible
    
    */
    GENAPI_NAMESPACE::IInteger &TransferTimeout;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The total count of processed buffers.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Total_Buffer_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The count of buffers that returned with an error status.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Failed_Buffer_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The status code of the last failed buffer.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Last_Failed_Buffer_Status;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The message text of the status code of the last failed buffer.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IString &Statistic_Last_Failed_Buffer_Status_Text;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The count of bad or missed frames between successfully grabbed images.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Missed_Frame_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The count of stream resynchronizations.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Resynchronization_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The last grabbed block ID.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Last_Block_Id;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUsbStreamParams_Params(CUsbStreamParams_Params&);

            //! not implemented assignment operator
            CUsbStreamParams_Params& operator=(CUsbStreamParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CUsbStreamParams_Params::CUsbStreamParams_Params(void)
        : MaxNumBuffer( *new GENAPI_NAMESPACE::CIntegerRef() )
        , MaxBufferSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , MaxTransferSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , NumMaxQueuedUrbs( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TransferLoopThreadPriority( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TransferTimeout( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Total_Buffer_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Failed_Buffer_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Last_Failed_Buffer_Status( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Last_Failed_Buffer_Status_Text( *new GENAPI_NAMESPACE::CStringRef() )
        , Statistic_Missed_Frame_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Resynchronization_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Last_Block_Id( *new GENAPI_NAMESPACE::CIntegerRef() )
        
    {
    }

    inline CUsbStreamParams_Params::~CUsbStreamParams_Params(void)
    {
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&MaxNumBuffer );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&MaxBufferSize );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&MaxTransferSize );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&NumMaxQueuedUrbs );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&TransferLoopThreadPriority );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&TransferTimeout );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Buffer_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Buffer_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Failed_Buffer_Status );
        delete static_cast < GENAPI_NAMESPACE::CStringRef*> (&Statistic_Last_Failed_Buffer_Status_Text );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Missed_Frame_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Resynchronization_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Block_Id );
        
    }

    inline void CUsbStreamParams_Params::_Initialize(GENAPI_NAMESPACE::INodeMap* _Ptr)
    {
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxNumBuffer )->SetReference(_Ptr->GetNode("MaxNumBuffer"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxBufferSize )->SetReference(_Ptr->GetNode("MaxBufferSize"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxTransferSize )->SetReference(_Ptr->GetNode("MaxTransferSize"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&NumMaxQueuedUrbs )->SetReference(_Ptr->GetNode("NumMaxQueuedUrbs"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TransferLoopThreadPriority )->SetReference(_Ptr->GetNode("TransferLoopThreadPriority"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TransferTimeout )->SetReference(_Ptr->GetNode("TransferTimeout"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Buffer_Count )->SetReference(_Ptr->GetNode("Statistic_Total_Buffer_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Buffer_Count )->SetReference(_Ptr->GetNode("Statistic_Failed_Buffer_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Failed_Buffer_Status )->SetReference(_Ptr->GetNode("Statistic_Last_Failed_Buffer_Status"));
    static_cast<GENAPI_NAMESPACE::CStringRef*> (&Statistic_Last_Failed_Buffer_Status_Text )->SetReference(_Ptr->GetNode("Statistic_Last_Failed_Buffer_Status_Text"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Missed_Frame_Count )->SetReference(_Ptr->GetNode("Statistic_Missed_Frame_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Resynchronization_Count )->SetReference(_Ptr->GetNode("Statistic_Resynchronization_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Block_Id )->SetReference(_Ptr->GetNode("Statistic_Last_Block_Id"));
    
    }

    inline const char* CUsbStreamParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CUsbStreamParams_Params::_GetModelName(void)
    {
        return "UsbStreamParams";
    }

    //! \endcond

} // namespace Basler_UsbStreamParams

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#   endif
#endif

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_UsbStreamParams_PARAMS_H
