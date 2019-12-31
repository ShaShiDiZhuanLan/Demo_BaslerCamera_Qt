





//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to image format converter parameters.
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_ImageFormatConverterParams_PARAMS_H
#define Basler_ImageFormatConverterParams_PARAMS_H

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
namespace Basler_ImageFormatConverterParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for MonoConversionMethod
    enum MonoConversionMethodEnums
    {
        MonoConversionMethod_Gamma,     //!<Gamma conversion is used to convert from input to output format.
        MonoConversionMethod_Truncate   //!<Image data is shifted when using this conversion method.
        
    };

    //! Valid values for OutputOrientation
    enum OutputOrientationEnums
    {
        OutputOrientation_Unchanged, //!<The orientation of the image is not changed.
        OutputOrientation_TopDown,   //!<The first row of the image is located at the start of the image buffer.
        OutputOrientation_BottomUp   //!<The last row of the image is located at the start of the image buffer.
        
    };

    //! Valid values for InconvertibleEdgeHandling
    enum InconvertibleEdgeHandlingEnums
    {
        InconvertibleEdgeHandling_SetZero,  //!<Rows and columns that cannot be converted are set to zero.
        InconvertibleEdgeHandling_Clip,     //!<Rows and columns that cannot be converted are removed from the output image.
        InconvertibleEdgeHandling_Extend    //!<Rows and columns that cannot be converted are extrapolated from the image.
    };

    //! Valid values for OutputBitAlignment
    enum OutputBitAlignmentEnums
    {
        OutputBitAlignment_LsbAligned,  //!<The data is aligned at the least significant bit.
        OutputBitAlignment_MsbAligned   //!<The data is aligned at the most significant bit.
        
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to image format converter parameters.
    class CImageFormatConverterParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CImageFormatConverterParams_Params(void);

            //! Destructor
            ~CImageFormatConverterParams_Params(void);

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
        
    //! \name MonoConversion - Parameters for converting monochrome images.
    //@{
    /*!
        \brief Sets the conversion method for monochrome images.

        Sets the conversion method for monochrome images.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<MonoConversionMethodEnums > &MonoConversionMethod;
    
    //@}
    

    //! \name MonoConversion - Parameters for converting monochrome images.
    //@{
    /*!
        \brief Sets the gamma value for converting monochrome images.

        Sets the gamma value for converting monochrome images.	The image data is converted using a lookup table. The values of the lookup table are computed using the following formula: valueOut = min((((valueIn ^ Gamma) / (valueInMax ^ Gamma)) * valueOutMax), valueOutMax).
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IFloat &Gamma;
    
    //@}
    

    //! \name MonoConversion - Parameters for converting monochrome images.
    //@{
    /*!
        \brief Sets the value for additional shifting when converting monochrome images in Truncate mode.

        Sets the value for additional shifting when converting monochrome images in Truncate mode. The image data is converted using a lookup table if the parameter value differs from zero. Shifted values exceeding the maximum output value boundary are set to the maximum allowed value. Negative values are treated as right shifted values.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &AdditionalLeftShift;
    
    //@}
    

    //! \name Root - Image Format Converter parameters.
    //@{
    /*!
        \brief The number of additional data bytes at the end of each line.

        The number of additional data bytes at the end of each line. These bytes are set to zero during the conversion.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IInteger &OutputPaddingX;
    
    //@}
    

    //! \name Root - Image Format Converter parameters.
    //@{
    /*!
        \brief Defines the vertical orientation of the output image in memory.

        Defines the vertical orientation of the output image in memory.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<OutputOrientationEnums > &OutputOrientation;
    
    //@}
    

    //! \name Root - Image Format Converter parameters.
    //@{
    /*!
        \brief Sets the handling for rows and columns that cannot be converted.

        Sets the handling for rows and columns that cannot be converted.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<InconvertibleEdgeHandlingEnums > &InconvertibleEdgeHandling;
    
    //@}
    

    //! \name Root - Image Format Converter parameters.
    //@{
    /*!
        \brief Controls the alignment of the bits in the target pixel type.

        Controls the alignment of the bits in the target pixel type if the target value has more bits than the source value.
    
        \b Visibility = Beginner
        
    
    */
    GenApi::IEnumerationT<OutputBitAlignmentEnums > &OutputBitAlignment;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CImageFormatConverterParams_Params(CImageFormatConverterParams_Params&);

            //! not implemented assignment operator
            CImageFormatConverterParams_Params& operator=(CImageFormatConverterParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CImageFormatConverterParams_Params::CImageFormatConverterParams_Params(void)
        : MonoConversionMethod( *new GenApi::CEnumerationTRef<MonoConversionMethodEnums>() )
        , Gamma( *new GenApi::CFloatRef() )
        , AdditionalLeftShift( *new GenApi::CIntegerRef() )
        , OutputPaddingX( *new GenApi::CIntegerRef() )
        , OutputOrientation( *new GenApi::CEnumerationTRef<OutputOrientationEnums>() )
        , InconvertibleEdgeHandling( *new GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums>() )
        , OutputBitAlignment( *new GenApi::CEnumerationTRef<OutputBitAlignmentEnums>() )
        
    {
    }

    inline CImageFormatConverterParams_Params::~CImageFormatConverterParams_Params(void)
    {
        delete static_cast < GenApi::CEnumerationTRef<MonoConversionMethodEnums> *> (&MonoConversionMethod );
        delete static_cast < GenApi::CFloatRef*> (&Gamma );
        delete static_cast < GenApi::CIntegerRef*> (&AdditionalLeftShift );
        delete static_cast < GenApi::CIntegerRef*> (&OutputPaddingX );
        delete static_cast < GenApi::CEnumerationTRef<OutputOrientationEnums> *> (&OutputOrientation );
        delete static_cast < GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums> *> (&InconvertibleEdgeHandling );
        delete static_cast < GenApi::CEnumerationTRef<OutputBitAlignmentEnums> *> (&OutputBitAlignment );
        
    }

    inline void CImageFormatConverterParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CEnumerationTRef<MonoConversionMethodEnums> *> (&MonoConversionMethod )->SetReference(_Ptr->GetNode("MonoConversionMethod"));
        static_cast<GenApi::CEnumerationTRef<MonoConversionMethodEnums> *> (&MonoConversionMethod )->SetNumEnums(2);
        static_cast<GenApi::CEnumerationTRef<MonoConversionMethodEnums> *> (&MonoConversionMethod )->SetEnumReference( MonoConversionMethod_Gamma, "Gamma" );        static_cast<GenApi::CEnumerationTRef<MonoConversionMethodEnums> *> (&MonoConversionMethod )->SetEnumReference( MonoConversionMethod_Truncate, "Truncate" );        static_cast<GenApi::CFloatRef*> (&Gamma )->SetReference(_Ptr->GetNode("Gamma"));
        static_cast<GenApi::CIntegerRef*> (&AdditionalLeftShift )->SetReference(_Ptr->GetNode("AdditionalLeftShift"));
        static_cast<GenApi::CIntegerRef*> (&OutputPaddingX )->SetReference(_Ptr->GetNode("OutputPaddingX"));
        static_cast<GenApi::CEnumerationTRef<OutputOrientationEnums> *> (&OutputOrientation )->SetReference(_Ptr->GetNode("OutputOrientation"));
        static_cast<GenApi::CEnumerationTRef<OutputOrientationEnums> *> (&OutputOrientation )->SetNumEnums(3);
        static_cast<GenApi::CEnumerationTRef<OutputOrientationEnums> *> (&OutputOrientation )->SetEnumReference( OutputOrientation_Unchanged, "Unchanged" );        static_cast<GenApi::CEnumerationTRef<OutputOrientationEnums> *> (&OutputOrientation )->SetEnumReference( OutputOrientation_TopDown, "TopDown" );        static_cast<GenApi::CEnumerationTRef<OutputOrientationEnums> *> (&OutputOrientation )->SetEnumReference( OutputOrientation_BottomUp, "BottomUp" );        static_cast<GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums> *> (&InconvertibleEdgeHandling )->SetReference(_Ptr->GetNode("InconvertibleEdgeHandling"));
        static_cast<GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums> *> (&InconvertibleEdgeHandling )->SetNumEnums(3);
        static_cast<GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums> *> (&InconvertibleEdgeHandling )->SetEnumReference( InconvertibleEdgeHandling_SetZero, "SetZero" );
        static_cast<GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums> *> (&InconvertibleEdgeHandling)->SetEnumReference(InconvertibleEdgeHandling_Clip, "Clip");
        static_cast<GenApi::CEnumerationTRef<InconvertibleEdgeHandlingEnums> *> (&InconvertibleEdgeHandling)->SetEnumReference(InconvertibleEdgeHandling_Extend, "Extend");
        static_cast<GenApi::CEnumerationTRef<OutputBitAlignmentEnums> *> (&OutputBitAlignment)->SetReference(_Ptr->GetNode("OutputBitAlignment"));
        static_cast<GenApi::CEnumerationTRef<OutputBitAlignmentEnums> *> (&OutputBitAlignment )->SetNumEnums(2);
        static_cast<GenApi::CEnumerationTRef<OutputBitAlignmentEnums> *> (&OutputBitAlignment )->SetEnumReference( OutputBitAlignment_LsbAligned, "LsbAligned" );        static_cast<GenApi::CEnumerationTRef<OutputBitAlignmentEnums> *> (&OutputBitAlignment )->SetEnumReference( OutputBitAlignment_MsbAligned, "MsbAligned" );        
    }

    inline const char* CImageFormatConverterParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CImageFormatConverterParams_Params::_GetModelName(void)
    {
        return "ImageFormatConverterParams";
    }

    //! \endcond

} // namespace Basler_ImageFormatConverterParams

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_ImageFormatConverterParams_PARAMS_H
