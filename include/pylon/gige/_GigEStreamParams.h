

//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the PylonGigE Stream Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_GigEStreamParams_PARAMS_H
#define Basler_GigEStreamParams_PARAMS_H

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
namespace Basler_GigEStreamParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for Type
    enum TypeEnums
    {
        Type_WindowsFilterDriver,  //!<The Pylon GigE Vision Streaming Filter Driver.
        Type_WindowsIntelPerformanceDriver,  //!<The Pylon GigE Vision Performance Driver for Intel network controllers.
        Type_SocketDriver,  //!<The socket driver.
        Type_NoDriverAvailable   //!<Indicates that no suitable driver is installed.
        
    };

    //! Valid values for Status
    enum StatusEnums
    {
        Status_NotInitialized,  //!<The low level stream grabber is not initialized.
        Status_Closed,  //!<The low level stream grabber is closed.
        Status_Open,  //!<The low level stream grabber is open.
        Status_Locked   //!<The low level stream grabber is locked.
        
    };

    //! Valid values for AccessMode
    enum AccessModeEnums
    {
        AccessMode_NotInitialized,  //!<
        AccessMode_Monitor,  //!<
        AccessMode_Control,  //!<
        AccessMode_Exclusive   //!<
        
    };

    //! Valid values for TransmissionType
    enum TransmissionTypeEnums
    {
        TransmissionType_UseCameraConfig,  //!<The configuration is read from the camera.
        TransmissionType_Unicast,  //!<The stream data is sent to the controlling application.
        TransmissionType_Multicast,  //!<The stream data is sent to multiple devices.
        TransmissionType_LimitedBroadcast,  //!<The stream is sent to all devices in the local LAN, not to devices on the Internet (i.e. behind a router).
        TransmissionType_SubnetDirectedBroadcast   //!<The stream data is sent to all destinations in the subnet.
        
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to the PylonGigE Stream Grabber parameters
    class CGigEStreamParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CGigEStreamParams_Params(void);

            //! Destructor
            ~CGigEStreamParams_Params(void);

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
        
    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Selects the driver type to be used.

        
    
        \b Visibility = Beginner
        
    
    */
    GENAPI_NAMESPACE::IEnumerationT<TypeEnums > &Type;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief The maximum number of buffers that can be used simultaneously.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &MaxNumBuffer;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief The maximum buffer size in bytes that can be registered.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &MaxBufferSize;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Enables or disables the packet resend mechanism.

        
        
        An image frame consists of n numbers of packets. Each packet has a header consisting of a 24-bit packet ID. 
        This packet ID increases with each packet sent, and makes it possible for the receiving end to know if a 
        particular packet has been lost during the transfer. If 'ResendPacketMechanism' is enabled, and the receiving
        end notices a lost packet, it will request the other side (e.g. the camera) to send the lost packet again.
        If enabled, the 'ResendPacketMechanism' can cause delays in the timing because the sending end will resend 
        the lost packet. If disabled, image data packet(s) can get lost which results in an incomplete received frame.
        You have to weigh the disadvantages and advantages for your special application to decide whether to enable 
        or disable this command.<br><br>
        
        Default setting: <i>Enabled</i>
        
        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IBoolean &EnableResend;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Timeout period in milliseconds between two packets within one frame.

        
        
        An image frame consists of n numbers of packets. The packet timeout counting is (re)started
        each time a packet is received. If the timeout expires (e.g. no packet was received 
        during the last 'PacketTimeout' period), the 'Resend Packet Mechanism' is started. 
        For information, see the 'EnableResend' feature.
        
        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &PacketTimeout;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Enables or disables probing of a working large packet size before grabbing.

        
        
        Enables or disables probing of a working large packet size before grabbing.
        Using large packets reduces the overhead for transferring images but
        whether a large packet can be transported depends on the used network hardware
        and its configuration.
        
        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IBoolean &AutoPacketSize;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Size of the sliding receive window in number of frames.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &ReceiveWindowSize;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Resend threshold as percentage of receive window.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &ResendRequestThreshold;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Additional resend batching as percentage of threshold.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &ResendRequestBatching;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Time in milliseconds to wait until a resend request is issued.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &ResendTimeout;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Timeout in milliseconds for missing resend responses.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &ResendRequestResponseTimeout;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Maximum number of resend requests per packet.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &MaximumNumberResendRequests;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief Maximum time in milliseconds to receive all packets of an individual frame.

        
      
      An image frame consists of n numbers of packets. The 'FrameRetention' always starts from the
      point in time the receiving end notices that a packet has been received for a particular frame. 
      If the transmission of packets of a frame is not completed within the 'FrameRetention' time, 
      the corresponding frame is delivered with status 'Failed'.
      
      
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &FrameRetention;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief If enabled, the user can set a custom priority of the receive thread.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IBoolean &ReceiveThreadPriorityOverride;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief The realtime receive thread priority.

        This value sets the absolute thread priority of the receive thread.
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &ReceiveThreadPriority;
    
    //@}
    

    //! \name Root - Interface to the GigE specific stream parameters.
    //@{
    /*!
        \brief The socket buffer size in KB.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &SocketBufferSize;
    
    //@}
    

    //! \name Debug - Shows information for debugging purposes.
    //@{
    /*!
        \brief Shows the current stream grabber status.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IEnumerationT<StatusEnums > &Status;
    
    //@}
    

    //! \name Debug - Shows information for debugging purposes.
    //@{
    /*!
        \brief Camera access mode.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IEnumerationT<AccessModeEnums > &AccessMode;
    
    //@}
    

    //! \name Debug - Shows information for debugging purposes.
    //@{
    /*!
        \brief Specifies whether the Pylon GigE Vision Performance Driver for Intel network controllers is currently available.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &TypeIsWindowsIntelPerformanceDriverAvailable;
    
    //@}
    

    //! \name Debug - Shows information for debugging purposes.
    //@{
    /*!
        \brief Specifies whether the Pylon GigE Vision Streaming Filter Driver is currently available.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &TypeIsWindowsFilterDriverAvailable;
    
    //@}
    

    //! \name Debug - Shows information for debugging purposes.
    //@{
    /*!
        \brief Specifies whether the socket driver is currently available.

        
    
        \b Visibility = Guru
    
    */
    GENAPI_NAMESPACE::IInteger &TypeIsSocketDriverAvailable;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of received frames.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Total_Buffer_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of buffers with at least one failed packet (status != success).

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Failed_Buffer_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of frames lost because there were no buffers queued to the driver.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Buffer_Underrun_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of received packets.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Total_Packet_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of failed packets (status != success).

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Failed_Packet_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of emitted PACKETRESEND commands.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Resend_Request_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Counts the number of packets requested by PACKETRESEND commands.

        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &Statistic_Resend_Packet_Count;
    
    //@}
    

    //! \name IPConfig - Configuration of the stream destination.
    //@{
    /*!
        \brief Controls whether the stream data is sent to a single device or to multiple devices.

        
        
        <ul>
        <li>
            <b>Default (Unicast)</b><br>
            The camera sends stream data to a single controlling application. Other devices cannot
            receive the stream data.
        </li>
        <br>
        <li>
            <b>Broadcast</b><br>
            The camera sends the stream data to all devices on the network. The application which 
            starts/stops the acquisition is called the controlling application. Other applications
            can receive the stream data. These applications are called monitor applications, because 
            they open the camera in read-only mode. This implies that monitor applications cannot 
            change the camera configuration and they cannot start/stop the image acquisition.
            However, monitor applications can request resend requests for lost stream data packets.
            <br><br>
            Attention: Broadcasting the stream data packets uses a high amount of network bandwidth 
                       because the stream data packets are forwarded to all devices attached to the 
                       network, even if they are not interested in receiving stream data.
        </li>
        <br>
        <li>
            <b>Multicast</b><br>
            Multicasting is very similar to broadcasting. The main advantage of multicasting is that 
            multicasting saves network bandwidth, because the image data stream is only sent to those 
            devices that are interested in receiving the data. To achieve this, the camera sends image 
            data streams to members of a multicast group only. A multicast group is defined by an IP 
            address taken from the multicast address range (224.0.0.0 to 239.255.255.255). 
            <br><br>
            Every device that wants to receive a multicast data stream has to be a member of a multicast 
            group. A member of a specific multicast group only receives data destinated for this group.
            Data for other groups is not received. Usually network adapters and switches are able to filter
            the data efficently on hardware level (layer-2 packet filtering). 
            <br><br>
            When multicasting is enabled for pylon, pylon automatically takes care of joining and leaving 
            the multicast groups defined by the destination IP address. Keep in mind that some addresses
            from the multicast address range are reserved for general purposes. The address range from
            239.255.0.0 to 239.255.255.255 is assigned by RFC 2365 as a locally administered address space.
            Use one of these addresses if you are not sure.
            <br><br>
            On protocol level multicasting involves a so-called IGMP message (IGMP = Internet Group Management Protocol).
            To benefit from multicasting, managed network switches should be used. These managed network 
            switches support the IGMP protocol. Managed network switches supporting the IGMP protocol
            will forward multicast packets only if there is a connected device that has joined the
            corresponding multicast group. If the switch does not support the IGMP protocol, multicast
            is equivalent to broadcasting.
            <br><br>
            Recommendation:<br>
            <ul>
                <li>
                    Each camera should stream to a different multicast group.
                </li>
                <li>
                    Streaming to different multicast groups reduces the CPU load and saves network bandwidth 
                    if the network switches supports the IGMP protocol.
                </li>
            </ul>
        </li>
        <br>        
        <li>
            <b>Use camera configuration</b><br>
            This setting is only available if the application has opened the device in monitor mode. If 
            the controlling application has already configured the camera stream channel and has possibly 
            started the acquisition, the monitor application can read all required configuration data 
            from the camera. Additional configuration is not required. This setting can only be used if 
            the controlling application has established the stream channel (by opening a pylon stream 
            grabber object), and the monitor application is started afterwards.
            <br><br>
            Note, when using broadcast and multicast configurations: When there is more than one camera 
            device reachable by one network interface, make sure that for each camera a different port
            number must be assigned. For assigning port numbers, see the 'DestinationPort' feature.
        </li>
        </ul>
        
        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IEnumerationT<TransmissionTypeEnums > &TransmissionType;
    
    //@}
    

    //! \name IPConfig - Configuration of the stream destination.
    //@{
    /*!
        \brief Specifies the destination IP address.

        The camera will sent all stream data to this IP address. For more details see 'TransmissionType' feature.
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IString &DestinationAddr;
    
    //@}
    

    //! \name IPConfig - Configuration of the stream destination.
    //@{
    /*!
        \brief Specifies the destination port number (0 = auto select).

        
        
            The camera will sent all stream data to this port.

            <b>Port configuration:</b>
            <ol>
            <li>
                <b>Unicast</b><br>
                The port is determined automatically.
                Manually choosing a port number might be useful for certain firewall configurations.
            </li>
            <br>
            <li>
                <b>Broadcast & Multicast</b><br>
                For each device reachable by a specific network interface, a unique, unused port number
                must be assigned. Be aware that the suggested default value might be already in use.
                Choose an unused port or 0=autoselect in that case. The controlling application and all 
                monitor applications must use the same port number. There is no autoselect feature
                availbale for monitor applications, i.e., monitor applications must not use the 0 value.
                For monitor applications it is convenient to use the 'UseCameraConfig' value for the 
                'TransmissionType' feature instead. For more details see the 'TransmissionType' feature.
            </li>
            </ol>
        
        
    
        \b Visibility = Expert
    
    */
    GENAPI_NAMESPACE::IInteger &DestinationPort;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CGigEStreamParams_Params(CGigEStreamParams_Params&);

            //! not implemented assignment operator
            CGigEStreamParams_Params& operator=(CGigEStreamParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CGigEStreamParams_Params::CGigEStreamParams_Params(void)
        : Type( *new GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums>() )
        , MaxNumBuffer( *new GENAPI_NAMESPACE::CIntegerRef() )
        , MaxBufferSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , EnableResend( *new GENAPI_NAMESPACE::CBooleanRef() )
        , PacketTimeout( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoPacketSize( *new GENAPI_NAMESPACE::CBooleanRef() )
        , ReceiveWindowSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ResendRequestThreshold( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ResendRequestBatching( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ResendTimeout( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ResendRequestResponseTimeout( *new GENAPI_NAMESPACE::CIntegerRef() )
        , MaximumNumberResendRequests( *new GENAPI_NAMESPACE::CIntegerRef() )
        , FrameRetention( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ReceiveThreadPriorityOverride( *new GENAPI_NAMESPACE::CBooleanRef() )
        , ReceiveThreadPriority( *new GENAPI_NAMESPACE::CIntegerRef() )
        , SocketBufferSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Status( *new GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums>() )
        , AccessMode( *new GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums>() )
        , TypeIsWindowsIntelPerformanceDriverAvailable( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TypeIsWindowsFilterDriverAvailable( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TypeIsSocketDriverAvailable( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Total_Buffer_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Failed_Buffer_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Buffer_Underrun_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Total_Packet_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Failed_Packet_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Resend_Request_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Resend_Packet_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TransmissionType( *new GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums>() )
        , DestinationAddr( *new GENAPI_NAMESPACE::CStringRef() )
        , DestinationPort( *new GENAPI_NAMESPACE::CIntegerRef() )
        
    {
    }

    inline CGigEStreamParams_Params::~CGigEStreamParams_Params(void)
    {
        delete static_cast < GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&MaxNumBuffer );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&MaxBufferSize );
        delete static_cast < GENAPI_NAMESPACE::CBooleanRef*> (&EnableResend );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&PacketTimeout );
        delete static_cast < GENAPI_NAMESPACE::CBooleanRef*> (&AutoPacketSize );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&ReceiveWindowSize );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&ResendRequestThreshold );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&ResendRequestBatching );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&ResendTimeout );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&ResendRequestResponseTimeout );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&MaximumNumberResendRequests );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&FrameRetention );
        delete static_cast < GENAPI_NAMESPACE::CBooleanRef*> (&ReceiveThreadPriorityOverride );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&ReceiveThreadPriority );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&SocketBufferSize );
        delete static_cast < GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status );
        delete static_cast < GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&TypeIsWindowsIntelPerformanceDriverAvailable );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&TypeIsWindowsFilterDriverAvailable );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&TypeIsSocketDriverAvailable );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Buffer_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Buffer_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Buffer_Underrun_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Packet_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Packet_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Resend_Request_Count );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Resend_Packet_Count );
        delete static_cast < GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType );
        delete static_cast < GENAPI_NAMESPACE::CStringRef*> (&DestinationAddr );
        delete static_cast < GENAPI_NAMESPACE::CIntegerRef*> (&DestinationPort );
        
    }

    inline void CGigEStreamParams_Params::_Initialize(GENAPI_NAMESPACE::INodeMap* _Ptr)
    {
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type )->SetReference(_Ptr->GetNode("Type"));
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type )->SetNumEnums(4);
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type )->SetEnumReference( Type_WindowsFilterDriver, "WindowsFilterDriver" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type )->SetEnumReference( Type_WindowsIntelPerformanceDriver, "WindowsIntelPerformanceDriver" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type )->SetEnumReference( Type_SocketDriver, "SocketDriver" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TypeEnums> *> (&Type )->SetEnumReference( Type_NoDriverAvailable, "NoDriverAvailable" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxNumBuffer )->SetReference(_Ptr->GetNode("MaxNumBuffer"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxBufferSize )->SetReference(_Ptr->GetNode("MaxBufferSize"));
    static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&EnableResend )->SetReference(_Ptr->GetNode("EnableResend"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PacketTimeout )->SetReference(_Ptr->GetNode("PacketTimeout"));
    static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&AutoPacketSize )->SetReference(_Ptr->GetNode("AutoPacketSize"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ReceiveWindowSize )->SetReference(_Ptr->GetNode("ReceiveWindowSize"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ResendRequestThreshold )->SetReference(_Ptr->GetNode("ResendRequestThreshold"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ResendRequestBatching )->SetReference(_Ptr->GetNode("ResendRequestBatching"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ResendTimeout )->SetReference(_Ptr->GetNode("ResendTimeout"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ResendRequestResponseTimeout )->SetReference(_Ptr->GetNode("ResendRequestResponseTimeout"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaximumNumberResendRequests )->SetReference(_Ptr->GetNode("MaximumNumberResendRequests"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&FrameRetention )->SetReference(_Ptr->GetNode("FrameRetention"));
    static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&ReceiveThreadPriorityOverride )->SetReference(_Ptr->GetNode("ReceiveThreadPriorityOverride"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ReceiveThreadPriority )->SetReference(_Ptr->GetNode("ReceiveThreadPriority"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&SocketBufferSize )->SetReference(_Ptr->GetNode("SocketBufferSize"));
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status )->SetReference(_Ptr->GetNode("Status"));
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status )->SetNumEnums(4);
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_NotInitialized, "NotInitialized" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Closed, "Closed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Open, "Open" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<StatusEnums> *> (&Status )->SetEnumReference( Status_Locked, "Locked" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode )->SetReference(_Ptr->GetNode("AccessMode"));
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode )->SetNumEnums(4);
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode )->SetEnumReference( AccessMode_NotInitialized, "NotInitialized" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode )->SetEnumReference( AccessMode_Monitor, "Monitor" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode )->SetEnumReference( AccessMode_Control, "Control" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AccessModeEnums> *> (&AccessMode )->SetEnumReference( AccessMode_Exclusive, "Exclusive" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TypeIsWindowsIntelPerformanceDriverAvailable )->SetReference(_Ptr->GetNode("TypeIsWindowsIntelPerformanceDriverAvailable"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TypeIsWindowsFilterDriverAvailable )->SetReference(_Ptr->GetNode("TypeIsWindowsFilterDriverAvailable"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TypeIsSocketDriverAvailable )->SetReference(_Ptr->GetNode("TypeIsSocketDriverAvailable"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Buffer_Count )->SetReference(_Ptr->GetNode("Statistic_Total_Buffer_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Buffer_Count )->SetReference(_Ptr->GetNode("Statistic_Failed_Buffer_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Buffer_Underrun_Count )->SetReference(_Ptr->GetNode("Statistic_Buffer_Underrun_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Packet_Count )->SetReference(_Ptr->GetNode("Statistic_Total_Packet_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Packet_Count )->SetReference(_Ptr->GetNode("Statistic_Failed_Packet_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Resend_Request_Count )->SetReference(_Ptr->GetNode("Statistic_Resend_Request_Count"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Resend_Packet_Count )->SetReference(_Ptr->GetNode("Statistic_Resend_Packet_Count"));
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetReference(_Ptr->GetNode("TransmissionType"));
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetNumEnums(5);
    static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetEnumReference( TransmissionType_UseCameraConfig, "UseCameraConfig" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetEnumReference( TransmissionType_Unicast, "Unicast" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetEnumReference( TransmissionType_Multicast, "Multicast" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetEnumReference( TransmissionType_LimitedBroadcast, "LimitedBroadcast" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TransmissionTypeEnums> *> (&TransmissionType )->SetEnumReference( TransmissionType_SubnetDirectedBroadcast, "SubnetDirectedBroadcast" );        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DestinationAddr )->SetReference(_Ptr->GetNode("DestinationAddr"));
    static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&DestinationPort )->SetReference(_Ptr->GetNode("DestinationPort"));
    
    }

    inline const char* CGigEStreamParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CGigEStreamParams_Params::_GetModelName(void)
    {
        return "GigEStreamParams";
    }

    //! \endcond

} // namespace Basler_GigEStreamParams

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#   endif
#endif

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_GigEStreamParams_PARAMS_H
