#ifndef RXIMGDATA_HPP
#define RXIMGDATA_HPP
#include <iostream>

/* own replacement for string.h */
#include "var.hpp"

/*********************************************************************/
/* Possible selections                                               */
/*********************************************************************/
#define PAL_BW          0
#define PAL_VGA         1
#define PAL_8           2
#define PAL_4G          3
#define PAL_784         4
#define PAL_666         5
#define PAL_444         6
#define PAL_8G          7
#define PAL_TRIPEL      8
#define PAL_1BPP        9
#define PAL_4BPP       10
#define PAL_8BPP       11
#define PAL_RGB        12
#define PAL_FREQ       13
#define PAL_MCUT       14
#define ERRDIFF        0x4000
#define HALFTONE       0x2000

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct FILTER_NAME_TABLE_DEF
    {
        var name;   /* filter name */
        GBM_SCALE_FILTER filter; /* filter type */
    };

    static const int GBM_SCALE_FILTER_SIMPLE = 0;

    static FILTER_NAME_TABLE_DEF FILTER_NAME_TABLE [] =
    { //{ "simple"         , GBM_SCALE_FILTER_SIMPLE },
        { "nearestneighbor", GBM_SCALE_FILTER_NEARESTNEIGHBOR },
        { "bilinear"       , GBM_SCALE_FILTER_BILINEAR        },
        { "bell"           , GBM_SCALE_FILTER_BELL            },
        { "bspline"        , GBM_SCALE_FILTER_BSPLINE         },
        { "mitchell"       , GBM_SCALE_FILTER_MITCHELL        },
        { "lanczos"        , GBM_SCALE_FILTER_LANCZOS         },
        { "blackman"       , GBM_SCALE_FILTER_BLACKMAN        },
        { "catmullrom"     , GBM_SCALE_FILTER_CATMULLROM      },
        { "quadratic"      , GBM_SCALE_FILTER_QUADRATIC       },
        { "gaussian"       , GBM_SCALE_FILTER_GAUSSIAN        },
        { "kaiser"         , GBM_SCALE_FILTER_KAISER          }
    };

    const int FILTER_NAME_TABLE_LENGTH = sizeof( FILTER_NAME_TABLE ) / sizeof( FILTER_NAME_TABLE[0] );

    static gbm_u8 mask[] = { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };

    typedef struct { var name; int pal; int tgt_bpp; } MAPPING;

    static MAPPING map2pal [] =
    {
        { "BW", PAL_BW, 1 },
        { "VGA", PAL_VGA, 4 },
        { "8B", PAL_8, 4 },
        { "4G", PAL_4G, 4 },
        { "7x8x4", PAL_784, 8 },
        { "6x6x6", PAL_666, 8 },
        { "4x4x4", PAL_444, 8 },
        { "8G", PAL_8G, 8 },
        { "TRIPEL", PAL_TRIPEL, 8 },
        { "1BPP", PAL_1BPP, 1 },
        { "4BPP", PAL_4BPP, 4 },
        { "8BPP", PAL_8BPP, 8 },
        { "RGB", PAL_RGB, 24 },
        { "FREQ", PAL_FREQ, 8 },
        { "MCUT", PAL_MCUT, 8 }
    };

    const int N_MAPPING = sizeof( map2pal ) / sizeof( map2pal[0] );

    typedef struct {
        int    width, height, filterIndex;
        int    ncols, pal, tgt_bpp, ht_mode;
        gbm_u8 rgb[3];
        var    palFile;
    } COLORMODE;

    typedef struct {
        var    fileName, opts;
        int    fd, ft, stride;
        BYTE   *data;
    } IMAGEDATA;

#ifdef __cplusplus
}
#endif

HWND title2Hwnd( var *window, BOOL similar = FALSE )
{
    if( window->cmp( "DESKTOP", FALSE ) == 0 )
        return HWND_DESKTOP;
    else if( window->cmp( "CURRENT", FALSE ) == 0 )
        return WinQueryFocus( HWND_DESKTOP );
    else if( window->cmp( "FOCUS", FALSE ) == 0 ) {
        POINTL   tmp_ptl;
        WinQueryPointerPos( HWND_DESKTOP, &tmp_ptl );
        return WinWindowFromPoint ( HWND_DESKTOP, &tmp_ptl, FALSE );
    } else {
        int      MEMPOOL   = 40000;      /* Size of local memory pool area */
        HAB      hab       = NULLHANDLE;
        ULONG    cbItems   = 0, i,       /* Number of items in list */
                 ulBufSize = 0;          /* Size of buffer for information */
        PVOID    pvBase    = NULL;       /* Pointer to local memory pool */
        PSWBLOCK pswblk    = NULL;       /* Pointer to information returned */

        /* Allocate a large block of memory (uncommitted) and make it available for suballocation. This allows the system to commit memory only when it is actually needed.       */
        if( DosAllocMem( &pvBase, MEMPOOL, PAG_READ | PAG_WRITE ) != NO_ERROR ) return NULL;
        if( DosSubSetMem( pvBase, DOSSUB_INIT | DOSSUB_SPARSE_OBJ, MEMPOOL ) != NO_ERROR ) return NULL;

        /* Determine the number of items in the list and calculate the size of the buffer needed.                          */
        cbItems = WinQuerySwitchList( hab, NULL, 0 );
        ulBufSize = ( cbItems * sizeof( SWENTRY ) ) + sizeof( HSWITCH );

        /* Allocate the buffer from our memory pool */
        if( DosSubAllocMem( pvBase, (PVOID *) &pswblk, ulBufSize ) != NO_ERROR ) return NULL;

        /* Call WinQuerySwitchList again to fill our buffer with information */
        cbItems = WinQuerySwitchList( hab, pswblk, ulBufSize );

        PSWENTRY pswentry = pswblk->aswentry; /* pointer to current entry         */
        for ( i = 0; i < pswblk->cswentry; i++, pswentry++ )
        {
            if ( window->cmp( pswentry->swctl.szSwtitle, FALSE ) == 0 )
                return pswentry->swctl.hwnd;
        }
        if ( similar )
        {
            for ( ; i > -1; i--, pswentry-- )
                if ( window->isWithin( pswentry->swctl.szSwtitle, 0, FALSE ) > 0 )
                    return pswentry->swctl.hwnd;
            HENUM henum;
            HWND hwndNext;
            BOOL  fSuccess;
            SHORT sRetLen;
            SHORT sLength = 40;
            char  pchBuffer[40];
            for ( i = 0; i < pswblk->cswentry; i++, pswentry++ )
            {
                henum = WinBeginEnumWindows( pswentry->swctl.hwnd );
                while ( ( hwndNext = WinGetNextWindow( henum ) ) != NULLHANDLE ) {
                    sRetLen = WinQueryClassName( hwndNext, sLength, pchBuffer );
                    if ( window->isWithin( pchBuffer, 0, FALSE ) == 0 )
                    {
                        fSuccess = WinEndEnumWindows ( henum );
                        return hwndNext;
                    }
                }
                fSuccess = WinEndEnumWindows ( henum );
            }
        }
    }
    return NULL;
}

BOOL isBetween( int pre, int test, int post ) {
    return pre < test & test < post;
}

BOOL isFromTo( int pre, int test, int post ) {
    return pre <= test & test <= post;
}

BOOL QueryExist( var &fName ) {

    HFILE  hfFileHandle   = 0L;     /* Handle for file being manipulated */
    ULONG ulAction        = 0;      /* Action taken by DosOpen */

    int rc = DosOpen( fName,                    /* File path name */
                     &hfFileHandle,                  /* File handle */
                     &ulAction,                      /* Action taken */
                     0L,                           /* File primary allocation */
                     0L,    /* File attribute */
                     OPEN_ACTION_FAIL_IF_NEW |
                     OPEN_ACTION_OPEN_IF_EXISTS,  /* Open an existing file only   */
                     OPEN_FLAGS_NOINHERIT | OPEN_ACCESS_READONLY |
                     OPEN_SHARE_DENYNONE,
                     0L );
    if ( rc == 0 )
        rc = DosClose( hfFileHandle );      /* Close the file  (check rc in real life) */

    return ( ulAction == FILE_EXISTED );                            /* No extended attribute */
}

static int getFilterIndex( var &s, const struct FILTER_NAME_TABLE_DEF *table, const int tableLength )
{
    for ( int n = 0; n < tableLength; n++ )
        if ( s.containWord( table[ n ].name ) )
            return n;

    return GBM_SCALE_FILTER_SIMPLE;
}

static BOOL isGrayscalePalette( const GBMRGB *gbmrgb, const int entries )
{
    if ( ( entries > 0 ) && ( entries <= 0x100 ) )
    {
        for ( int i = 0; i < entries; i++ )
            if ( ( gbmrgb[i].r != gbmrgb[i].g ) || ( gbmrgb[i].r != gbmrgb[i].b ) || ( gbmrgb[i].g != gbmrgb[i].b ) )
                return FALSE;
        return TRUE;
    }
    return FALSE;
}

static BOOL expandTo24Bit( GBM *gbm, GBMRGB *gbmrgb, BYTE **ppbData, int *dataLen )
{
    int stride = ( ( gbm->w * gbm->bpp + 31 ) / 32 ) * 4;
    int new_stride = ( ( gbm->w * 3 + 3 ) & ~3 );
    int bytes, y;
    BYTE *pbDataNew;

    if ( gbm->bpp == 24 )
        return TRUE;

    bytes = new_stride * gbm->h;

    pbDataNew = ( BYTE * )gbmmem_malloc( bytes );
    if ( pbDataNew == NULL )
        return FALSE;

    for ( y = 0; y < gbm -> h; y++ )
    {
        BYTE *src = *ppbData + y * stride;
        BYTE *dest = pbDataNew + y * new_stride;
        int   x;

        switch ( gbm -> bpp )
        {
        case 1:
            {
                BYTE  c;
                for ( x = 0; x < gbm -> w; x++ )
                {
                    if ( ( x & 7 ) == 0 )
                        c = *src++;
                    else
                        c <<= 1;

                    *dest++ = gbmrgb [(c & 0x80) != 0].b;
                    *dest++ = gbmrgb [(c & 0x80) != 0].g;
                    *dest++ = gbmrgb [(c & 0x80) != 0].r;
                }
            }
            break;

        case 4:
            for ( x = 0; x + 1 < gbm -> w; x += 2 )
            {
                BYTE c = *src++;

                *dest++ = gbmrgb [c >> 4].b;
                *dest++ = gbmrgb [c >> 4].g;
                *dest++ = gbmrgb [c >> 4].r;
                *dest++ = gbmrgb [c & 15].b;
                *dest++ = gbmrgb [c & 15].g;
                *dest++ = gbmrgb [c & 15].r;
            }

            if ( x < gbm -> w )
            {
                BYTE c = *src;

                *dest++ = gbmrgb [c >> 4].b;
                *dest++ = gbmrgb [c >> 4].g;
                *dest++ = gbmrgb [c >> 4].r;
            }
            break;

        case 8:
            for ( x = 0; x < gbm -> w; x++ )
            {
                BYTE c = *src++;

                *dest++ = gbmrgb [c].b;
                *dest++ = gbmrgb [c].g;
                *dest++ = gbmrgb [c].r;
            }
            break;
        }
    }

    gbmmem_free( *ppbData );
    *ppbData = pbDataNew;
    *dataLen = bytes;

    gbm->bpp = 24;

    return TRUE;
}

static void to_grey_pal( GBMRGB *gbmrgb )
{
    for ( int i = 0; i < 0x100; i++ )
        gbmrgb[i].r = gbmrgb[i].g = gbmrgb[i].b = (gbm_u8) i;
}

static void to_grey( GBM *gbm, const gbm_u8 *src_data, gbm_u8 *dest_data )
{
    int src_stride  = ( ( gbm->w * 3 + 3 ) & ~3 );
    int dest_stride = ( ( gbm->w     + 3 ) & ~3 );

    for ( int y = 0; y < gbm->h; y++ )
    {
        const gbm_u8 *src  = src_data;
        gbm_u8 *dest = dest_data;

        for ( int x = 0; x < gbm->w; x++ )
        {
            gbm_u8 b = *src++;
            gbm_u8 g = *src++;
            gbm_u8 r = *src++;

            *dest++ = (gbm_u8) ( ( (gbm_u16) r * 77U + (gbm_u16) g * 150U + (gbm_u16) b * 29U ) >> 8 );
        }

        src_data  += src_stride;
        dest_data += dest_stride;
    }
    gbm->bpp = 8;
}

static void tripel_pal( GBMRGB *gbmrgb )
{
    memset( gbmrgb, 0, 0x100 * sizeof( GBMRGB ) );

    for ( int i = 0; i < 0x40; i++ )
    {
        gbmrgb[i].r = (gbm_u8) ( i << 2 );
        gbmrgb[i + 0x40].g = (gbm_u8) ( i << 2 );
        gbmrgb[i + 0x80].b = (gbm_u8) ( i << 2 );
    }
}

static void tripel( GBM *gbm, const gbm_u8 *src_data, gbm_u8 *dest_data )
{
    int src_stride  = ( ( gbm->w * 3 + 3 ) & ~3 );
    int dest_stride = ( ( gbm->w     + 3 ) & ~3 );

    for ( int y = 0; y < gbm->h; y++ )
    {
        const gbm_u8 *src  = src_data;
        gbm_u8 *dest = dest_data;

        for ( int x = 0; x < gbm->w; x++ )
        {
            gbm_u8 b = *src++;
            gbm_u8 g = *src++;
            gbm_u8 r = *src++;

            switch ( ( x + y ) % 3 )
            {
            case 0:     *dest++ = (gbm_u8)         ( r >> 2 ) ; break;
            case 1:     *dest++ = (gbm_u8) ( 0x40 + ( g >> 2 ) ); break;
            case 2:     *dest++ = (gbm_u8) ( 0x80 + ( b >> 2 ) ); break;
            }
        }

        src_data  += src_stride;
        dest_data += dest_stride;
    }
    gbm->bpp = 8;
}

static BOOL evaluateColors( COLORMODE *c_mode, var &color )
{
    int i, count = 0;

    for( i = 0; i < 3; i++ ) {
        if( color.copyOf().substr( i * 2, 1 ).isNumeric() ) {
            if( isFromTo( 0, ( c_mode->ncols = color.copyOf().substr( i * 2, 1 ).toInt() ), 8 ) ) {
                count++;
                c_mode->rgb[ i ] = mask[ c_mode->ncols ];
            } else
                c_mode->rgb[ i ] = mask[ 0 ];
        } else
            c_mode->rgb[ i ] = mask[ 0 ];
    }

    if ( ( c_mode->ncols = color.copyOf().substr( 5 ).toInt() ) != 0 ) {
        c_mode->ncols = max( 1, min( 256, c_mode->ncols ) );
        c_mode->pal = PAL_FREQ;
        c_mode->tgt_bpp = 8;
    } else if ( count == 3 ) {
        c_mode->pal = PAL_RGB;
        c_mode->tgt_bpp = 24;
    } else if ( color.words() > 0 ) {
        for ( i = N_MAPPING - 1; i > -1; i-- ) {
            if( color.containWord( map2pal[ i ].name ) ) {
                c_mode->pal = map2pal[ i ].pal;
                c_mode->tgt_bpp = map2pal[ i ].tgt_bpp;
                break;
            }
        }
        if ( c_mode->pal == -1 )
            if ( isBetween( 0, ( c_mode->ncols = color.toInt() ), 257 ) ) {
                c_mode->pal = PAL_MCUT;
                c_mode->tgt_bpp = 8;
            }
        if ( color.containWord( "ERRDIFF" ) )
            c_mode->pal |= ERRDIFF;
        else if ( color.containWord( "HALFTONE" ) ) {
            c_mode->pal |= HALFTONE;
            c_mode->ht_mode = color.rightOf( "HALFTONE" ).toInt();
        }
    }


    return ( c_mode->pal != -1 );
}

static int openFile( GBM *gbm, IMAGEDATA *imagedata ) {

    int rc;

    if ( Gbm_guess_filetype( imagedata->fileName, &imagedata->ft ) != GBM_ERR_OK )
        return 11;

    if ( ( imagedata->fd = Gbm_io_open( imagedata->fileName, GBM_O_RDONLY ) ) == -1 )
        return 5;

    if ( ( rc = Gbm_read_header( imagedata->fileName, imagedata->fd, imagedata->ft, gbm, imagedata->opts ) ) != GBM_ERR_OK )
    {
        Gbm_io_close( imagedata->fd );
        return rc;
    }

    return 0;
}


static int get_pal( GBMRGB *gbmrgb, COLORMODE *c_mode )
{
    IMAGEDATA idata;
    GBM gbm;
    int rc, i;

    idata.fileName = c_mode->palFile;

    if ( ( rc = openFile( &gbm, &idata ) ) == 0 )
    {
        if ( gbm.bpp > 8 )
            rc = 1;
        else if ( gbm.bpp > c_mode->tgt_bpp )
            rc = 2;
        else {
            /* Pre-initialise palette with medium grey */
            for ( i = 0; i < ( 1 << c_mode->tgt_bpp ); i++ )
                gbmrgb[i].r =
                gbmrgb[i].g =
                gbmrgb[i].b = 0x80;

            if ( ( rc = gbm_read_palette( idata.fd, idata.ft, &gbm, gbmrgb ) ) != GBM_ERR_OK )
                rc = 3;
        }
        gbm_io_close( idata.fd );
    }
    if ( rc == 0 )
        c_mode->ncols = ( 1 << gbm.bpp );
    return rc;
}

static int calculateSize( GBM *gbm, COLORMODE *c_mode, BOOL aspect )
{
    if ( aspect && ( c_mode->width > 0 ) && ( c_mode->height > 0 ) )
    {
        if ( ( ( float ) c_mode->width / gbm->w ) <= ( ( float ) c_mode->height / gbm->h ) )
            c_mode->height = ( gbm->h * c_mode->width ) / gbm->w;
        else
            c_mode->width = ( gbm->w * c_mode->height ) / gbm->h;
    }
    else
    {
        if ( c_mode->width < 1 )
        {
            if ( aspect )
                c_mode->width = ( gbm->w * c_mode->height ) / gbm->h;
            else
                c_mode->width = gbm->w;
        }
        if ( c_mode->height < 1 )
        {
            if ( aspect )
                c_mode->height = ( gbm->h * c_mode->width ) / gbm->w;
            else
                c_mode->height = gbm->h;
        }
    }

    if ( c_mode->width < 0 || c_mode->height < 0 )
        return 384;

    return 0;
}

static BOOL allocImageData( GBM *gbm, IMAGEDATA *imagedata )
{
    imagedata->stride = ( ( ( gbm->w * gbm->bpp + 31 ) / 32 ) * 4 );

    if ( ( imagedata->data = ( BYTE * )gbmmem_malloc( imagedata->stride * gbm->h ) ) == NULL )
    {
        gbmmem_free( imagedata->data );
        Gbm_io_close( imagedata->fd );
        return FALSE;
    }

    return TRUE;
}

static int readFile( GBM *gbm, GBMRGB *gbmrgb, IMAGEDATA *imagedata )
{
    int rc;

    if ( ( rc = Gbm_read_palette( imagedata->fd, imagedata->ft, gbm, gbmrgb ) ) != GBM_ERR_OK )
    {
        Gbm_io_close( imagedata->fd );
        return 22;
    }

    if ( !allocImageData( gbm, imagedata ) )
        return 8;

    if ( ( rc = Gbm_read_data( imagedata->fd, imagedata->ft, gbm, imagedata->data ) ) != GBM_ERR_OK )
    {
        gbmmem_free( imagedata->data );
        Gbm_io_close( imagedata->fd );
        return 30;
    }

    return 0;
}

static int writeFile( GBM *gbm, GBMRGB *gbmrgb, IMAGEDATA *imagedata )
{
    int      flag, rc;
    GBMFT    gbmft;

    if ( Gbm_guess_filetype( imagedata->fileName, &imagedata->ft ) != GBM_ERR_OK )
        return 11;

    if ( ( imagedata->fd = Gbm_io_create( imagedata->fileName, GBM_O_WRONLY ) ) == -1 )
    {
        gbmmem_free( imagedata->data );
        return 29;
    }

    Gbm_query_filetype( imagedata->ft, &gbmft );

    switch ( gbm->bpp )
    {
    case 64:   flag = GBM_FT_W64;  break;
    case 48:   flag = GBM_FT_W48;  break;
    case 32:   flag = GBM_FT_W32;  break;
    case 24:   flag = GBM_FT_W24;  break;
    case 8:    flag = GBM_FT_W8;   break;
    case 4:    flag = GBM_FT_W4;   break;
    case 1:    flag = GBM_FT_W1;   break;
    default:   flag = 0;           break;
    }

    if ( ( gbmft.flags & flag ) == 0 )
    {
        Gbm_io_close( imagedata->fd );
        return 120;
    }

    if ( ( rc = Gbm_write( imagedata->fileName, imagedata->fd, imagedata->ft, gbm, gbmrgb, imagedata->data, imagedata->opts ) ) != GBM_ERR_OK )
    {
        Gbm_io_close( imagedata->fd );
        gbmmem_free( imagedata->data );
        return 29;
    }

    Gbm_io_close( imagedata->fd );
    gbmmem_free( imagedata->data );

    return 0;

}

static BOOL reduceColors( GBM *gbm, GBMRGB *gbmrgb, BYTE *data, COLORMODE *c_mode )
{
    BOOL ok = TRUE;

    switch ( c_mode->pal )
    {
    case PAL_BW:
        gbm_trunc_pal_BW( gbmrgb );
        gbm_trunc_BW( gbm, data, data );
        break;
    case PAL_4G:
        gbm_trunc_pal_4G( gbmrgb );
        gbm_trunc_4G( gbm, data, data );
        break;
    case PAL_8:
        gbm_trunc_pal_8( gbmrgb );
        gbm_trunc_8( gbm, data, data );
        break;
    case PAL_VGA:
        gbm_trunc_pal_VGA( gbmrgb );
        gbm_trunc_VGA( gbm, data, data );
        break;
    case PAL_784:
        gbm_trunc_pal_7R8G4B( gbmrgb );
        gbm_trunc_7R8G4B( gbm, data, data );
        break;
    case PAL_666:
        gbm_trunc_pal_6R6G6B( gbmrgb );
        gbm_trunc_6R6G6B( gbm, data, data );
        break;
    case PAL_444:
        gbm_trunc_pal_4R4G4B( gbmrgb );
        gbm_trunc_4R4G4B( gbm, data, data );
        break;
    case PAL_8G:
        to_grey_pal( gbmrgb );
        to_grey( gbm, data, data );
        break;
    case PAL_TRIPEL:
        tripel_pal( gbmrgb );
        tripel( gbm, data, data );
        break;
    case PAL_1BPP:
        if( get_pal( gbmrgb, c_mode ) == 0 )
            gbm_trunc_1bpp( gbm, data, data, gbmrgb, c_mode->ncols );
        break;
    case PAL_4BPP:
        if( get_pal( gbmrgb, c_mode ) == 0 )
            gbm_trunc_4bpp( gbm, data, data, gbmrgb, c_mode->ncols );
        break;
    case PAL_8BPP:
        if( get_pal( gbmrgb, c_mode ) == 0 )
            gbm_trunc_8bpp( gbm, data, data, gbmrgb, c_mode->ncols );
        break;
    case PAL_FREQ:
        memset( gbmrgb, 0, sizeof( gbmrgb ) );
        ok = gbm_hist( gbm, data, gbmrgb, data, c_mode->ncols, c_mode->rgb[0], c_mode->rgb[1], c_mode->rgb[2] );
        break;
    case PAL_RGB:
        gbm_trunc_24( gbm, data, data, c_mode->rgb[0], c_mode->rgb[1], c_mode->rgb[2] );
        break;
    case PAL_MCUT:
        ok = gbm_mcut( gbm, data, gbmrgb, data, c_mode->ncols );
        break;
    case PAL_BW | ERRDIFF:
        gbm_errdiff_pal_BW( gbmrgb );
        ok = gbm_errdiff_BW( gbm, data, data );
        break;
    case PAL_4G | ERRDIFF:
        gbm_errdiff_pal_4G( gbmrgb );
        ok = gbm_errdiff_4G( gbm, data, data );
        break;
    case PAL_8 | ERRDIFF:
        gbm_errdiff_pal_8( gbmrgb );
        ok = gbm_errdiff_8( gbm, data, data );
        break;
    case PAL_VGA | ERRDIFF:
        gbm_errdiff_pal_VGA( gbmrgb );
        ok = gbm_errdiff_VGA( gbm, data, data );
        break;
    case PAL_784 | ERRDIFF:
        gbm_errdiff_pal_7R8G4B( gbmrgb );
        ok = gbm_errdiff_7R8G4B( gbm, data, data );
        break;
    case PAL_666 | ERRDIFF:
        gbm_errdiff_pal_6R6G6B( gbmrgb );
        ok = gbm_errdiff_6R6G6B( gbm, data, data );
        break;
    case PAL_444 | ERRDIFF:
        gbm_errdiff_pal_4R4G4B( gbmrgb );
        ok = gbm_errdiff_4R4G4B( gbm, data, data );
        break;
    case PAL_RGB | ERRDIFF:
        ok = gbm_errdiff_24( gbm, data, data, c_mode->rgb[0], c_mode->rgb[1], c_mode->rgb[2] );
        break;
    case PAL_784 | HALFTONE:
        gbm_ht_pal_7R8G4B( gbmrgb );
        gbm_ht_7R8G4B_2x2( gbm, data, data );
        break;
    case PAL_666 | HALFTONE:
        gbm_ht_pal_6R6G6B( gbmrgb );
        gbm_ht_6R6G6B_2x2( gbm, data, data );
        break;
    case PAL_444 | HALFTONE:
        gbm_ht_pal_4R4G4B( gbmrgb );
        gbm_ht_4R4G4B_2x2( gbm, data, data );
        break;
    case PAL_8 | HALFTONE:
        gbm_ht_pal_8( gbmrgb );
        switch ( c_mode->ht_mode )
        {
        default:
        case 0: gbm_ht_8_3x3( gbm, data, data ); break;
        case 1: gbm_ht_8_2x2( gbm, data, data ); break;
        }
        break;
    case PAL_VGA | HALFTONE:
        gbm_ht_pal_VGA( gbmrgb );
        switch ( c_mode->ht_mode )
        {
        default:
        case 0: gbm_ht_VGA_3x3( gbm, data, data ); break;
        case 1: gbm_ht_VGA_2x2( gbm, data, data ); break;
        }
        break;
    case PAL_RGB | HALFTONE:
        gbm_ht_24_2x2( gbm, data, data, c_mode->rgb[0], c_mode->rgb[1], c_mode->rgb[2] );
        break;
    default:
        break;
    }

    if ( ok && c_mode->pal != -1 )
        gbm->bpp = c_mode->tgt_bpp;

    return ok;
}
#endif
