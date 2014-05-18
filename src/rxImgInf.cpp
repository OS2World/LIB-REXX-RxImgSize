/* rxImgSize */

#define  INCL_DOS
#define  INCL_REXXSAA
#define  __REXXSAA_H_INCLUDED
#define  VAR_RX
#define INCL_PM
#define INCL_DOSERRORS   /* DOS error values */
#include <os2.h>

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "gbm.h"
#include "gbmmem.h"
#include "gbmscale.h"
#include "gbmtrunc.h"
#include "gbmerr.h"
#include "gbmht.h"
#include "gbmhist.h"
#include "gbmmcut.h"

/* own replacement for string.h */
#include "var.hpp"
#include "RxImgData.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#include <rexxsaa.h>


    /*********************************************************************/
    /* .DLL version                                                 */
    /*********************************************************************/
#define IMG_VERSION_REXX     "1.03"

    /*********************************************************************/
    /* Numeric Return calls                                              */
    /*********************************************************************/
#define  INVALID_ROUTINE 40            /* Raise Rexx error           */
#define  VALID_ROUTINE    0            /* Successful completion      */

    /*********************************************************************/
    /*  Declare all exported functions as REXX functions.                */
    /*********************************************************************/
    APIRET APIENTRY __export rxImgLoadFuncs( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr );
    APIRET APIENTRY __export rxImgDropFuncs( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr );

    APIRET APIENTRY __export rxImgVersion( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr );
    APIRET APIENTRY __export rxImgReSize( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr );
    APIRET APIENTRY __export rxImgCapture( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr );

#ifdef __cplusplus
}
#endif

/*********************************************************************/
/* RxFncTable                                                        */
/*   Array of names of the dll functions.                            */
/*   This list is used for registration and deregistration.          */
/*********************************************************************/

static PSZ RxFncTable[] =
{
    "rxImgLoadFuncs",
    "rxImgDropFuncs",
    "rxImgVersion",
    "rxImgReSize",
    "rxImgCapture"
};


/*********************************************************************/
/* Function:  rxImgVersion                                           */
/*                                                                   */
/* Syntax:    version = rxImgVersion()                               */
/*                                                                   */
/* Return:    Version number: "major.minor"                          */
/*********************************************************************/

APIRET APIENTRY __export rxImgVersion( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr )
{
    var version, opts;
    int i;

    if ( numargs > 0 )
        if ( args[0].strptr != NULL )
            opts.cpy( args[0].strptr );

    if ( numargs == 0 ) {
        Gbm_init();
        version.cat( "rxImgSize: version " ).cat( IMG_VERSION_REXX ).cat( ", GBM: version " ).cat( ( Gbm_version() / 100.0 ) );
        Gbm_deinit();
    } else if ( opts.wordBeginsWith( "R", " ", FALSE ) ) {
            version.cpy( IMG_VERSION_REXX );
    } else if ( opts.wordBeginsWith( "G", " ", FALSE ) ) {
        Gbm_init();
        version.cpy( ( Gbm_version() / 100.0 ) );
        Gbm_deinit();
    } else if ( opts.wordBeginsWith( "F", " ", FALSE ) ) {
        for ( i = 0; i < FILTER_NAME_TABLE_LENGTH - 1; i++ ) version.cat( FILTER_NAME_TABLE[ i ].name ).cat( ", " );
        version.cat( FILTER_NAME_TABLE[ i ].name );
    } else if ( opts.wordBeginsWith( "P", " ", FALSE ) ) {
        for ( i = 0; i < N_MAPPING - 1; i++ ) version.cat( map2pal[ i ].name ).cat( ", " );
        version.cat( map2pal[ i ].name );
    } else if ( opts.wordBeginsWith( "E", " ", FALSE ) ) {
        version.cpy( "ASPECT, ERRDIFF, HALFTONE" );
    }

    version.set( retstr );

    return VALID_ROUTINE;  /* no error on call */
}

/********************************************************************************/
/* Function:  rxImgReSize                                                       */
/*                                                                              */
/* Syntax:    rc = rxImgReSize( srcfName, tgtfName, w, h, opt, opt_out )        */
/*                                                                              */
/* Params:    string  in - Path and Name of file to resize                      */
/*                                                                              */
/*( optional )string  in - Path and Name of file to save to                     */
/*                         source by default                                    */
/*                                                                              */
/*( optional )string  in - Width of target file                                 */
/*                                                                              */
/*( optional )string  in - Height of target file                                */
/*                                                                              */
/*( optional )string  in - Scaling options and or write options                 */
/*                         To keep aspect ratio use "aspect"                    */
/*                         Quality scaling using one of the algorithms          */
/*                         "simple" ( default ), "nearestneighbor", "bilinear", */
/*                         "bell", "bspline",  "mitchell", "lanczos"            */
/*                         Se documentation for each image format               */
/*                                                                              */
/*( optional )string  in - File with palette for 1bpp, 4bpp & 8bpp              */
/*                                                                              */
/* Return:    "0" ( successful ) or a number indicating the error               */
/* Note:      Image info will be returned when the only parameter is a valid    */
/*            source file name in the form "width height bitmap_pixel_depth"    */
/*                                                                              */
/********************************************************************************/

APIRET APIENTRY __export rxImgReSize( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr )
{

    var retval;
    int rc;

    if ( numargs < 1 )
    {
        retval.cpy( "Syntax:  rc = rxImgReSize( Source_path_and_filename[, <Target_path_and_filename>[, <New_image_width>[, <New_image_height>[, <Options> ] ] ] ] )\n" );
        retval.cat( "\nExample: rc = rxImgReSize( 'C:\OS2\BITMAP\GMARBLE.BMP',, 120 )" );
        return VALID_ROUTINE;
    }

    IMAGEDATA source, target;

    BOOL  aspect = FALSE;
    BOOL  qualityScalingEnabled = FALSE;
    BOOL  isGrayscale = FALSE;
    GBM      gbm;
    GBMRGB   gbmrgb[0x100];

    COLORMODE c_mode;
    c_mode.width = -1;
    c_mode.height = -1;
    c_mode.tgt_bpp = -1;
    c_mode.filterIndex = -1;
    c_mode.ncols = 0;
    c_mode.pal = -1;
    c_mode.tgt_bpp = -1;
    c_mode.ht_mode = 0;

    if ( numargs > 0 )
        if ( args[0].strptr != NULL )
            source.fileName.cpy( args[0].strptr );

    if ( !QueryExist( source.fileName ) )
    {
        retval.cpy( "2" ).set( retstr );
        return VALID_ROUTINE;
    }

    if ( numargs > 1 )
        if ( args[1].strptr != NULL )
            target.fileName.cpy( args[1].strptr );
        else target.fileName.cpy( source.fileName );
    else target.fileName.cpy( source.fileName );

    if ( numargs > 2 )
        if ( args[2].strptr != NULL )
            c_mode.width = atoi( args[2].strptr );

    if ( numargs > 3 )
        if ( args[3].strptr != NULL )
            c_mode.height = atoi( args[3].strptr );

    if ( numargs > 4 )
        if ( args[4].strptr != NULL ) {
            aspect = ( target.opts.cpy( args[4].strptr ).containWord( "ASPECT" ) );
            c_mode.filterIndex = getFilterIndex( target.opts, FILTER_NAME_TABLE, FILTER_NAME_TABLE_LENGTH );
        }

    if ( numargs > 5 )
        if ( args[5].strptr != NULL )
            c_mode.palFile.cpy( args[5].strptr );

    if ( c_mode.filterIndex == -1 )
        c_mode.filterIndex = GBM_SCALE_FILTER_SIMPLE;

    if ( ( c_mode.width > 0 && c_mode.height < 1 ) || ( c_mode.width < 1 && c_mode.height > 0 ) ) /* Preserve aspect ratio unless otherwise stated */
        aspect = TRUE;

    if ( c_mode.filterIndex != GBM_SCALE_FILTER_SIMPLE )
        qualityScalingEnabled = TRUE;

    Gbm_init();

    if ( ( rc = openFile( &gbm, &source ) ) != 0 )
    {
        Gbm_deinit();
        retval.cpy( rc ).set( retstr );
        return VALID_ROUTINE;
    }

    if ( numargs == 1 )
    {
        retval.cpy( gbm.w ).cat( " " ).cat( gbm.h ).cat( " " ).cat( gbm.bpp ).set( retstr );
        Gbm_io_close( source.fd );
        Gbm_deinit();
        return VALID_ROUTINE;
    }

    /* check for color depth supported by algorithms */
    switch ( gbm.bpp )
    {
    case 64:
    case 48:
    case 32:
    case 24:
    case 8:
    case 4:
    case 1:
        break;
    default:
        {
            Gbm_io_close( source.fd );
            retval.cpy( "11" ).set( retstr );
            Gbm_deinit();
            return VALID_ROUTINE;
        }
    }

    if ( ( rc = calculateSize( &gbm, &c_mode, aspect ) ) != 0 )
    {
        Gbm_io_close( source.fd );
        Gbm_deinit();
        retval.cpy( rc ).set( retstr );
        return VALID_ROUTINE;
    }

    if ( ( rc = readFile( &gbm, gbmrgb, &source ) ) != 0 )
    {
        Gbm_io_close( source.fd );
        Gbm_deinit();
        retval.cpy( rc ).set( retstr );
        return VALID_ROUTINE;
    }

    Gbm_io_close( source.fd );

    c_mode.tgt_bpp = gbm.bpp;

    if ( qualityScalingEnabled )
    {
        if ( gbm.bpp <= 8 )
            isGrayscale = isGrayscalePalette( gbmrgb, 1 << gbm.bpp );

        if ( ( gbm.bpp <= 8 ) && ( !isGrayscale ) )
        {
            /* convert to 24bpp */
            if ( !expandTo24Bit( &gbm, gbmrgb, &source.data, &source.stride ) )
            {
                retval.cpy( "22" ).set( retstr );
                return VALID_ROUTINE;
            }
            c_mode.tgt_bpp = 24;
        }
        if ( isGrayscale )
            c_mode.tgt_bpp = 8;
    }

    evaluateColors( &c_mode, target.opts );

    if ( c_mode.width != gbm.w || c_mode.height != gbm.h ) {
        //target.stride = ( ( ( c_mode.width * ( qualityScalingEnabled ? gbm.bpp : c_mode.tgt_bpp ) + 31 ) / 32 ) * 4 );
        target.stride = ( ( ( c_mode.width * gbm.bpp + 31 ) / 32 ) * 4 );
        if ( ( target.data = ( BYTE * )gbmmem_malloc( target.stride * c_mode.height ) ) == NULL )
        {
            gbmmem_free( source.data );
            Gbm_deinit();
            retval.cpy( "8" ).set( retstr );
            return VALID_ROUTINE;
        }

        if ( qualityScalingEnabled )
        {
            if ( isGrayscale )
                rc = gbm_quality_scale_gray( source.data , gbm.w, gbm.h, gbm.bpp, gbmrgb,
                                            target.data, c_mode.width, c_mode.height, gbmrgb,
                                            FILTER_NAME_TABLE[ c_mode.filterIndex ].filter );
            else
                rc = gbm_quality_scale_bgra( source.data , gbm.w, gbm.h,
                                            target.data, c_mode.width, c_mode.height, gbm.bpp,
                                            FILTER_NAME_TABLE[ c_mode.filterIndex ].filter );
        } else {
            //rc = gbm_simple_scale( source.data, gbm.w, gbm.h, target.data, c_mode.width, c_mode.height, c_mode.tgt_bpp );
            rc = gbm_simple_scale( source.data, gbm.w, gbm.h, target.data, c_mode.width, c_mode.height, gbm.bpp );
            //gbm.bpp = c_mode.tgt_bpp;
            //c_mode.pal = -1;
        }
        gbm.h = c_mode.height;
        gbm.w = c_mode.width;
        gbmmem_free( source.data );
    } else {
        if ( c_mode.pal != -1 )
            expandTo24Bit( &gbm, gbmrgb, &source.data, &source.stride );
        target.data = source.data;
    }

    if ( rc != GBM_ERR_OK )
    {
        gbmmem_free( target.data );
        Gbm_deinit();
        retval.cpy( "13" ).set( retstr );
        return VALID_ROUTINE;
    }
    if ( c_mode.pal != -1 ) {
        if ( !reduceColors( &gbm, gbmrgb, target.data, &c_mode ) ) {
            gbmmem_free( target.data );
            Gbm_deinit();
            retval.cpy( "11" ).set( retstr );
            return VALID_ROUTINE;
        }
    }

    rc = writeFile( &gbm, gbmrgb, &target );

    Gbm_deinit();
    retval.cpy( rc ).set( retstr );
    return VALID_ROUTINE;  /* no error on call */
}


/*********************************************************************/
/* Function:  rxImgCapture                                           */
/*                                                                   */
/* Syntax:    CALL rxImgCapture 'Desktop', 1, 1, 240, 320, 'myfile.png' */
/*                                   <left>, <bottom>, <right>, <top>*/
/*            CALL rxImgCapture 'Desktop', 'Interior', 'C:\Myfile.bmp' */
/*            CALL rxImgCapture 'Desktop', 'Window' (Default)        */
/*            CALL rxImgCapture 'MyAppWindow'                        */
/*            CALL rxImgCapture 'Current'                            */
/*            CALL rxImgCapture 'Select', 'Clipboard' (Future) */
/*                                                                   */
/* Return:    0 on success, other on failure                             */
/*********************************************************************/

APIRET APIENTRY __export rxImgCapture( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr )
{
    HWND hwndFocus;
    HAB hab;
    var window, opts, retval;
    static PSZ pszData[4] = { "Display", NULL, NULL, NULL };
    SIZEL   sizlPage = {0, 0};
    POINTL  aptl[3];
    LONG    alData[2];
    SWP     swp;
    SHORT   sWidth, sHeight;
    BOOL    coords = FALSE;
    IMAGEDATA source, target;

    BOOL  aspect = FALSE;
    BOOL  qualityScalingEnabled = FALSE;
    BOOL  isGrayscale = FALSE;

    COLORMODE c_mode;
    c_mode.width = -1;
    c_mode.height = -1;
    c_mode.filterIndex = -1;
    c_mode.ncols = 0;
    c_mode.pal = -1;
    c_mode.tgt_bpp = -1;
    c_mode.ht_mode = 0;

    if ( numargs > 0 )
    {
        if ( args[0].strptr != NULL )
            window.cpy( args[0].strptr ).upper();
    } else {
        fprintf( stderr, "Syntax:  rc = rxImgCapture( Window_name[, <Left_coordinate>[, <Bottom_coordinate>[, <Right_coordinate>[, <Top_coordinate>[, <Save_as_path_filename> ] ] ] ] ] )\n" );
        fprintf( stderr, "         rc = rxImgCapture( Window_name[, 'INTERIOR'[, <Save_as_path_filename> ] ] )\n" );
        fprintf( stderr, "         rc = rxImgCapture( Window_name[, 'WINDOW'[, <Save_as_path_filename> ] ] )\n" );
        fprintf( stderr, "         rc = rxImgCapture( 'SELECT'[, <Save_as_path_filename> ] ) ***Future Improvement not implemented***\n\n" );
        fprintf( stderr, "Example: rc = rxImgCapture( 'DESKTOP', 10l, 10b, 20r, 30t, 'C:\Dektop.png' )\n" );
        fprintf( stderr, "         rc = rxImgCapture( 'EPM', 10x, 10y, 20w, 30h, 'C:\Enhanced_Editor_EPM.png' )\n" );
        retval.cpy( "22" ).set( retstr );
        return VALID_ROUTINE;
    }

    if( ( hwndFocus = title2Hwnd( &window, TRUE ) ) == NULL )
    {
        retval.cpy( window ).cat( " not found." ).set( retstr );
        return VALID_ROUTINE;
    }

    if ( numargs > 1 ) {
        if ( args[1].strptr != NULL )
            if( retval.cpy( args[1].strptr ).cmp( "INTERIOR", FALSE ) == 0 )
            {
                HWND hwndOld;
                hwndOld = hwndFocus;
                if( !( hwndFocus = WinWindowFromID( hwndOld, FID_CLIENT ) ) )
                    if( !( hwndFocus = WinQueryWindow( hwndOld, QW_BOTTOM ) ) )
                        hwndFocus = hwndOld;
            }
        WinQueryWindowPos( hwndFocus, &swp );
        swp.x = 0;
        swp.y = 0;
        int currpos = 0, charpos = -5, value, box[4] = { 0, 0, 0, 0 };
        for( int i = 1; i < numargs; i++ )
        {
            if ( args[ i ].strptr != NULL )
            {
                if( retval.cpy( args[ i ].strptr ).isInteger() )
                {
                    value = (int)retval.cpy( args[ i ].strptr ).strip().trunc();
                    if ( retval.len() > 0 ) {
                        if ( ( charpos = retval.within( "xywh", 0, FALSE ) ) == -1 )
                            if ( ( charpos = retval.within( "lbrt", 0, FALSE ) ) == -1 )
                            {
                                for( ; box[ currpos ] == 1; currpos++ )
                                    charpos = currpos;
                                if( retval.cmp( "%" ) == 0 )
                                    charpos = abs( charpos ) + 4;
                                if ( currpos > 3 )
                                    charpos = 8; // to many parameters with numbers!
                            } else
                                charpos = -1 - charpos;
                    } else
                        for( ; currpos < 4 && box[currpos] == 1; currpos++ )
                            charpos = currpos;
                } else
                    charpos = 8;

                switch ( charpos )
                {
                case -4:
                    swp.cy = max( 0, swp.cy - value );
                    box[3] = 1;
                    break;
                case -3:
                    swp.cx = max( 0, swp.cx - value );
                    box[2] = 1;
                    break;
                case -2:
                    swp.y += value;
                    swp.cy = max( 0, swp.cy - value );
                    box[1] = 1;
                    break;
                case -1:
                    swp.x += value;
                    swp.cx = max( 0, swp.cx - value );
                    box[0] = 1;
                    break;
                case 0:
                    swp.x += max( 0, value );
                    box[0] = 1;
                    break;
                case 1:
                    swp.y += max( 0, value );
                    box[1] = 1;
                    break;
                case 2:
                    swp.cx += max( 0, value );
                    box[2] = 1;
                    break;
                case 3:
                    swp.cy += max( 0, value );
                    box[3] = 1;
                    break;
                case 4:
                    swp.x = ( swp.cx * min( 100, value ) ) / 100;
                    swp.cx = max( 0, swp.cx - swp.x );
                    box[0] = 1;
                    break;
                case 5:
                    swp.y = ( swp.cy * min( 100, value ) ) / 100;
                    swp.cy = max( 0, swp.cy - swp.y );
                    box[1] = 1;
                    break;
                case 6:
                    swp.x = ( swp.cx * min( 100, 100 - value ) ) / 100;
                    swp.cx = max( 0, swp.cx - swp.x );
                    box[2] = 1;
                    break;
                case 7:
                    swp.y = ( swp.cy * min( 100, 100 - value ) ) / 100;
                    swp.cy = max( 0, swp.cy - swp.y );
                    box[3] = 1;
                    break;
                }
            }
        }
    }

    if ( args[ numargs - 1 ].strptr != NULL && numargs > 1 )
        target.fileName.cpy( args[ numargs - 1 ].strptr );
    else
        target.fileName.cpy( "temporary.bmp" );
    if( target.fileName.cmp( '.' ) != 1 )
        target.fileName.cat( ".bmp" );

    /* create the memory device context and presentation space so they are compatible with the screen device context and presentation space */
    HDC hdcMem = DevOpenDC( hab, OD_MEMORY, "*", 4, PDEVOPENDATA( pszData ), 0 );
    HPS hpsMem = GpiCreatePS( hab, hdcMem, &sizlPage, PU_PELS | GPIT_MICRO | GPIA_ASSOC | GPIF_DEFAULT );

    // determine the device's plane/bit-count format
    GpiQueryDeviceBitmapFormats( hpsMem, 2, alData );

    BITMAPINFO2 bmp;
    HBITMAP hbmNew, hbmOld;

    /* load the BITMAPINFOHEADER2 and BITMAPINFO2 structures. The sWidth and sHeight fields specify the width and height of the destination rect. */
    bmp.cbFix           = sizeof( BITMAPINFOHEADER2 );
    bmp.cx              = swp.cx;
    bmp.cy              = swp.cy;
    bmp.cPlanes         = alData[0];
    bmp.cBitCount       = min( 24, alData[1] );

    bmp.ulCompression   = BCA_UNCOMP;
    bmp.cxResolution    = 0;
    bmp.cyResolution    = 0;
    bmp.cclrUsed        = 0;
    bmp.cclrImportant   = 0;

    bmp.usUnits         = BRU_METRIC;
    bmp.usReserved      = 0;
    bmp.usRecording     = BRA_BOTTOMUP;
    bmp.usRendering     = BRH_NOTHALFTONED;
    bmp.cSize1          = 0;
    bmp.cSize2          = 0;
    bmp.ulColorEncoding = BCE_RGB;
    bmp.ulIdentifier    = 0;

    // create a bitmap that is compatible with the display
    if( ( hbmNew = GpiCreateBitmap( hpsMem, (BITMAPINFOHEADER2 *)&bmp, 0L, NULL, NULL ) ) == NULL )
    {
        retval.cpy( "12" ).set( retstr );
        return VALID_ROUTINE;
    }

    // associate the bitmap and the memory presentation space
    hbmOld = GpiSetBitmap( hpsMem, hbmNew );

    /* Copy the screen to the bitmap. */
    aptl[0].x = 0;
    aptl[0].y = 0;
    aptl[1].x = swp.cx;
    aptl[1].y = swp.cy;
    aptl[2].x = swp.x;
    aptl[2].y = swp.y;

    HPS hpsTemp;

    if( WinIsWindow( hab, hwndFocus ) || ( hwndFocus == HWND_DESKTOP ) )
        hpsTemp = WinGetPS( hwndFocus );
    else
    {
        GpiDeleteBitmap( hbmNew );
        DevCloseDC( hdcMem );
        return VALID_ROUTINE;
    }

    GpiBitBlt( hpsMem, hpsTemp, 3L, aptl, ROP_SRCCOPY, BBO_IGNORE );

    int    rc;
    GBMFT  gbmft;
    GBM    gbm;
    GBMRGB gbmrgb[0x100];

    /* processing */
    Gbm_init();

    gbm.w = swp.cx;
    gbm.h = swp.cy;
    gbm.bpp = bmp.cBitCount;

    if( !allocImageData( &gbm, &target ) )
        rc = 8;

    GpiQueryBitmapBits( hpsMem, 0L, (LONG) bmp.cy, target.data, &bmp );

    rc = writeFile( &gbm, gbmrgb, &target );

    Gbm_deinit();

    // re-associate the previous bitmap and the memory presentation space
    GpiSetBitmap( hpsMem, hbmOld );

    GpiDeleteBitmap( hbmNew );
    WinReleasePS( hpsTemp );
    GpiAssociate( hpsMem, (HDC)NULL );
    GpiDestroyPS( hpsMem );
    DevCloseDC( hdcMem );

    retval.cpy( rc ).set( retstr );

    return VALID_ROUTINE;  /* no error on call */
}

/*********************************************************************/
/* Function:  rxImgLoadFuncs                                         */
/*                                                                   */
/* Syntax:    call rxImgLoadFuncs                                    */
/*                                                                   */
/* Params:    none                                                   */
/*                                                                   */
/* Return:    null string                                            */
/*********************************************************************/

APIRET APIENTRY __export rxImgLoadFuncs( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr )
{
    retstr->strlength = 0; /* return a null string result */

    for ( int i = 0; i < sizeof( RxFncTable ) / sizeof( PSZ ); i++ )
        RexxRegisterFunctionDll( RxFncTable[i], "RXIMGSZE", RxFncTable[i] );

    return VALID_ROUTINE;  /* no error on call */
}

/*********************************************************************/
/* Function:  rxImgDropFuncs                                         */
/*                                                                   */
/* Syntax:    call rxImgDropFuncs                                    */
/*                                                                   */
/* Params:    none                                                   */
/*                                                                   */
/* Return:    null string                                            */
/*********************************************************************/

APIRET APIENTRY __export rxImgDropFuncs( char* name, ULONG numargs, RXSTRING args[], char* queuename, RXSTRING *retstr )
{

    retstr->strlength = 0;           /* return a null string result*/

    for ( int i = 0; i < sizeof( RxFncTable ) / sizeof( PSZ ); i++ )
        RexxDeregisterFunction( RxFncTable[i] );

    return VALID_ROUTINE;  /* no error on call */
}
