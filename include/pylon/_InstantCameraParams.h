





//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to instant camera parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_InstantCameraParams_PARAMS_H
#define Basler_InstantCameraParams_PARAMS_H

#ifdef __GNUC__
#define GENAPI_DEPRECATED_FEATURE __attribute__((deprecated))
#elif defined(_MSC_VER)
#define GENAPI_DEPRECATED_FEATURE __declspec(deprecated)
#else
#define GENAPI_DEPRECATED_FEATURE
#endif

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


//! The namespace containing the device's control interface and related enumeration types
namespace Basler_InstantCameraParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    

    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to instant camera parameters
    class CInstantCameraParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CInstantCameraParams_Params(void);

            //! Destructor
            ~CInstantCameraParams_Params(void);

            //! Initializes the references
            void _Initialize(GenApi::INodeMap*);

            //! Return the vendor of the camera
            const char* _GetVendorName(void);

            //! Returns the camera model name
            const char* _GetModelName(void);
        
        //! \endcond

    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        
    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The maximum number of buffers that are allocated and used for grabbing.

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &MaxNumBuffer;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The maximum number of buffers that are queued in the stream grabber input queue.

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &MaxNumQueuedBuffer;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The maximum number of grab results available at any time during a grab session. This value can be limited to save resources. Furthermore, it can be used to check that the grab results are returned correctly.

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &MaxNumGrabResults;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief Enables/disables the use of a chunk node map for each grab result. Grab result chunk node maps can be disabled to save resources.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &ChunkNodeMapsEnable;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief If larger than 0, a static chunk node map pool is used instead of dynamic chunk node map creation.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &StaticChunkNodeMapPoolSize;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief Enables/disables the grabbing of camera events while images are grabbed. Is writable when the camera object is closed.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IBoolean &GrabCameraEvents;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The camera object is set to monitor mode when enabled, e.g. when using the GigE multicast feature. Is writable when the camera object is closed.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &MonitorModeActive;
    
    //@}
    

    //! \name InternalGrabEngineThread - Parameters of the internal grab engine thread.
    //@{
    /*!
        \brief If enabled, the user can set a custom priority for the internal grab engine thread operating the stream grabber. Otherwise the priority defaults to 25.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &InternalGrabEngineThreadPriorityOverride;
    
    //@}
    

    //! \name InternalGrabEngineThread - Parameters of the internal grab engine thread.
    //@{
    /*!
        \brief The internal grab engine thread priority.

        This value sets the absolute thread priority for the internal grab engine thread operating the stream grabber.
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &InternalGrabEngineThreadPriority;
    
    //@}
    

    //! \name GrabLoopThread - Parameters of the optional grab loop  thread.
    //@{
    /*!
        \brief If enabled, the user can set a custom timeout for the grab loop thread's call to RetrieveResult. RetrieveResult is configured to throw an exception on timeout, which will stop the grab session.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &GrabLoopThreadUseTimeout;
    
    //@}
    

    //! \name GrabLoopThread - Parameters of the optional grab loop  thread.
    //@{
    /*!
        \brief A custom timeout for the grab loop thread's call to RetrieveResult. RetrieveResult is configured to throw an exception on timeout, which will stop the grab session.

        
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &GrabLoopThreadTimeout;
    
    //@}
    

    //! \name GrabLoopThread - Parameters of the optional grab loop  thread.
    //@{
    /*!
        \brief If enabled, the user can set a custom priority for the grab loop thread. Otherwise, the priority of the newly created thread is not changed.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IBoolean &GrabLoopThreadPriorityOverride;
    
    //@}
    

    //! \name GrabLoopThread - Parameters of the optional grab loop  thread.
    //@{
    /*!
        \brief The grab loop thread priority.

        This value sets the absolute thread priority for the grab loop thread.
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &GrabLoopThreadPriority;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The number of buffers queued at Low Level API stream grabber.

        
        
            This is the number of buffers that are queued for grabbing in the stream grabber.
            The number is influenced by the number of available free buffers and the
            maximum number of buffers that can be queued.
            See also the MaxNumBuffer and MaxNumQueuedBuffer parameters.

            This parameter can be used to check whether the number of buffers ready for grabbing
            is stable, which means that the image processing is fast enough to keep up with the
            rate of incoming images when using the GrabStrategy_OneByOne grab strategy.
        
        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &NumQueuedBuffers;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The number of grab result buffers in the output queue that are ready for retrieval.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &NumReadyBuffers;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The number of empty buffers that are not used for grabbing yet.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &NumEmptyBuffers;
    
    //@}
    

    //! \name Root - Instant camera parameters.
    //@{
    /*!
        \brief The size of the grab result buffer output queue.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &OutputQueueSize;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CInstantCameraParams_Params(CInstantCameraParams_Params&);

            //! not implemented assignment operator
            CInstantCameraParams_Params& operator=(CInstantCameraParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CInstantCameraParams_Params::CInstantCameraParams_Params(void)
        : MaxNumBuffer( *new GenApi::CIntegerRef() )
        , MaxNumQueuedBuffer( *new GenApi::CIntegerRef() )
        , MaxNumGrabResults( *new GenApi::CIntegerRef() )
        , ChunkNodeMapsEnable( *new GenApi::CBooleanRef() )
        , StaticChunkNodeMapPoolSize( *new GenApi::CIntegerRef() )
        , GrabCameraEvents( *new GenApi::CBooleanRef() )
        , MonitorModeActive( *new GenApi::CBooleanRef() )
        , InternalGrabEngineThreadPriorityOverride( *new GenApi::CBooleanRef() )
        , InternalGrabEngineThreadPriority( *new GenApi::CIntegerRef() )
        , GrabLoopThreadUseTimeout( *new GenApi::CBooleanRef() )
        , GrabLoopThreadTimeout( *new GenApi::CIntegerRef() )
        , GrabLoopThreadPriorityOverride( *new GenApi::CBooleanRef() )
        , GrabLoopThreadPriority( *new GenApi::CIntegerRef() )
        , NumQueuedBuffers( *new GenApi::CIntegerRef() )
        , NumReadyBuffers( *new GenApi::CIntegerRef() )
        , NumEmptyBuffers( *new GenApi::CIntegerRef() )
        , OutputQueueSize( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CInstantCameraParams_Params::~CInstantCameraParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&MaxNumBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&MaxNumQueuedBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&MaxNumGrabResults );
        delete static_cast < GenApi::CBooleanRef*> (&ChunkNodeMapsEnable );
        delete static_cast < GenApi::CIntegerRef*> (&StaticChunkNodeMapPoolSize );
        delete static_cast < GenApi::CBooleanRef*> (&GrabCameraEvents );
        delete static_cast < GenApi::CBooleanRef*> (&MonitorModeActive );
        delete static_cast < GenApi::CBooleanRef*> (&InternalGrabEngineThreadPriorityOverride );
        delete static_cast < GenApi::CIntegerRef*> (&InternalGrabEngineThreadPriority );
        delete static_cast < GenApi::CBooleanRef*> (&GrabLoopThreadUseTimeout );
        delete static_cast < GenApi::CIntegerRef*> (&GrabLoopThreadTimeout );
        delete static_cast < GenApi::CBooleanRef*> (&GrabLoopThreadPriorityOverride );
        delete static_cast < GenApi::CIntegerRef*> (&GrabLoopThreadPriority );
        delete static_cast < GenApi::CIntegerRef*> (&NumQueuedBuffers );
        delete static_cast < GenApi::CIntegerRef*> (&NumReadyBuffers );
        delete static_cast < GenApi::CIntegerRef*> (&NumEmptyBuffers );
        delete static_cast < GenApi::CIntegerRef*> (&OutputQueueSize );
        
    }

    inline void CInstantCameraParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&MaxNumBuffer )->SetReference(_Ptr->GetNode("MaxNumBuffer"));
    static_cast<GenApi::CIntegerRef*> (&MaxNumQueuedBuffer )->SetReference(_Ptr->GetNode("MaxNumQueuedBuffer"));
    static_cast<GenApi::CIntegerRef*> (&MaxNumGrabResults )->SetReference(_Ptr->GetNode("MaxNumGrabResults"));
    static_cast<GenApi::CBooleanRef*> (&ChunkNodeMapsEnable )->SetReference(_Ptr->GetNode("ChunkNodeMapsEnable"));
    static_cast<GenApi::CIntegerRef*> (&StaticChunkNodeMapPoolSize )->SetReference(_Ptr->GetNode("StaticChunkNodeMapPoolSize"));
    static_cast<GenApi::CBooleanRef*> (&GrabCameraEvents )->SetReference(_Ptr->GetNode("GrabCameraEvents"));
    static_cast<GenApi::CBooleanRef*> (&MonitorModeActive )->SetReference(_Ptr->GetNode("MonitorModeActive"));
    static_cast<GenApi::CBooleanRef*> (&InternalGrabEngineThreadPriorityOverride )->SetReference(_Ptr->GetNode("InternalGrabEngineThreadPriorityOverride"));
    static_cast<GenApi::CIntegerRef*> (&InternalGrabEngineThreadPriority )->SetReference(_Ptr->GetNode("InternalGrabEngineThreadPriority"));
    static_cast<GenApi::CBooleanRef*> (&GrabLoopThreadUseTimeout )->SetReference(_Ptr->GetNode("GrabLoopThreadUseTimeout"));
    static_cast<GenApi::CIntegerRef*> (&GrabLoopThreadTimeout )->SetReference(_Ptr->GetNode("GrabLoopThreadTimeout"));
    static_cast<GenApi::CBooleanRef*> (&GrabLoopThreadPriorityOverride )->SetReference(_Ptr->GetNode("GrabLoopThreadPriorityOverride"));
    static_cast<GenApi::CIntegerRef*> (&GrabLoopThreadPriority )->SetReference(_Ptr->GetNode("GrabLoopThreadPriority"));
    static_cast<GenApi::CIntegerRef*> (&NumQueuedBuffers )->SetReference(_Ptr->GetNode("NumQueuedBuffers"));
    static_cast<GenApi::CIntegerRef*> (&NumReadyBuffers )->SetReference(_Ptr->GetNode("NumReadyBuffers"));
    static_cast<GenApi::CIntegerRef*> (&NumEmptyBuffers )->SetReference(_Ptr->GetNode("NumEmptyBuffers"));
    static_cast<GenApi::CIntegerRef*> (&OutputQueueSize )->SetReference(_Ptr->GetNode("OutputQueueSize"));
    
    }

    inline const char* CInstantCameraParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CInstantCameraParams_Params::_GetModelName(void)
    {
        return "InstantCameraParams";
    }

    //! \endcond

} // namespace Basler_InstantCameraParams

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_InstantCameraParams_PARAMS_H
