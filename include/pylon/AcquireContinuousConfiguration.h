//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief An instant camera configuration for free-running continuous acquisition.
    This  instant camera configuration is provided as header-only file. The code
    can be copied and modified for creating own configuration classes.
*/

#ifndef INCLUDED_ACQUIRECONTINUOUSCONFIGURATION_H_7346765
#define INCLUDED_ACQUIRECONTINUOUSCONFIGURATION_H_7346765

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/InstantCamera.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiGeneric
     * @{
     */

    /*!
    \class  CAcquireContinuousConfiguration
    \brief Changes the configuration of the camera to free-running continuous acquisition.

        The \c CAcquireContinuousConfiguration is the default configuration of the Instant Camera class.
        The CAcquireContinuousConfiguration is automatically registered when an Instant Camera object is created.

        This instant camera configuration is provided as header-only file. The code
        can be copied and modified for creating own configuration classes.
    */
    class CAcquireContinuousConfiguration : public CConfigurationEventHandler
    {
    public:
        /// Apply acquire continuous configuration.
        static void ApplyConfiguration( GENAPI_NAMESPACE::INodeMap& nodemap)
        {
            using namespace GENAPI_NAMESPACE;

            //Disable all trigger types.
            {
                // Get required enumerations.
                CEnumerationPtr triggerSelector( nodemap.GetNode("TriggerSelector"));
                CEnumerationPtr triggerMode( nodemap.GetNode("TriggerMode"));

                if (IsAvailable(triggerSelector))
                {
                    // Get all enumeration entries of Trigger Selector.
                    GENAPI_NAMESPACE::NodeList_t triggerSelectorEntries;
                    triggerSelector->GetEntries(triggerSelectorEntries);

                    // Turn Trigger Mode off For all Trigger Selector entries.
                    for (GENAPI_NAMESPACE::NodeList_t::iterator it = triggerSelectorEntries.begin(); it != triggerSelectorEntries.end(); ++it)
                    {
                        // Set Trigger Mode to off if the trigger is available.
                        GENAPI_NAMESPACE::CEnumEntryPtr pEntry(*it);
                        if (IsAvailable(pEntry))
                        {
                            triggerSelector->FromString(pEntry->GetSymbolic());
                            triggerMode->FromString("Off");
                        }
                    }
                }
            }

            //Set acquisition mode.
            CEnumerationPtr(nodemap.GetNode("AcquisitionMode"))->FromString("Continuous");
        }


        //Set basic camera settings.
        virtual void OnOpened( CInstantCamera& camera)
        {
            try
            {
                ApplyConfiguration( camera.GetNodeMap());
            }
            catch (const GenericException& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. Pylon::GenericException caught in OnOpened method msg=%hs", e.what());
            }
            catch (const std::exception& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. std::exception caught in OnOpened method msg=%hs", e.what());
            }
            catch (...)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. Unknown exception caught in OnOpened method.");
            }
        }
    };

    /**
     * @}
     */
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_ACQUIRECONTINUOUSCONFIGURATION_H_7346765 */
