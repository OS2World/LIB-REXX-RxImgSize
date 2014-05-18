/* Testing rxImgSze.dll */

SAY DIRECTORY()

/* Load the library */
CALL RxFuncAdd 'rxImgLoadFuncs', 'rxImgSze', 'rxImgLoadFuncs'

SAY DIRECTORY()

CALL rxImgLoadFuncs

MKDIR images

SAY '>'rxImgVersion()'<'
SAY '>'rxImgVersion( 'r' )'<'
SAY '>'rxImgVersion( 'G' )'<'
SAY '>'rxImgVersion( 'F' )'<'
SAY '>'rxImgVersion( 'P' )'<'

SAY rxImgCapture( 'RxImgSize', 'images\example0.bmp' )

SAY rxImgReSize( 'images\example0.bmp' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example1.jpg', 100 )

SAY rxImgReSize( 'images\example0.bmp', 'images\example1.bmp', 120 )

SAY rxImgReSize( 'images\example0.bmp', 'images\example2.bmp', 120, 120, 'BW' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example3.bmp',, 120 )

SAY rxImgReSize( 'images\example3.bmp',,, 1370, '256' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example4.bmp' )

SAY rxImgReSize( 'images\example4.bmp',,210,'aspect' )

SAY rxImgReSize( 'images\example1.bmp','images\example5.jpg', 1000, 1000, 'laNcZos' )

SAY rxImgReSize( 'images\example3.bmp','images\example6.jpg', 2000, 2000,'asPeCt neAresTneighBor' )

SAY rxImgReSize( 'images\example0.bmp','images\example7.bmp', 3000, 3000, 'laNcZos' )

SAY rxImgCapture( 'Desktop', 'images\example.bmp' )

SAY rxImgCapture( 'editor', 'interior', 'images\example8.bmp' )

SAY rxImgCapture( 'editor', 'interior', '7l', '35b', 'images\example9.bmp' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example10.png',, 350 , 'blackman 6x6x6' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example11.png', 125, 250, 'catmullrom vga' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example12.bmp', 500,, 'kaiser' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example13.bmp', 300,, '7x8x4 quadratic' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example14.bmp', 800,, '8 gaussian' )

SAY rxImgReSize( 'images\example0.bmp', 'images\example15.bmp', 550,, '9x6x4 bilinear' )

/* Unload the libarary */
CALL rxImgDropFuncs