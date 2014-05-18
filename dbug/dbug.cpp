#define INCL_REXXSAA
#include <rexxsaa.h>
#include <iostream.h>

int main(int args, char *argn[]) {
  LONG      return_code;                 /* interpreter return code    */
  RXSTRING  argv[1];                     /* program argument string    */
  RXSTRING  retstr;                      /* program return value       */
  SHORT     rc;                          /* converted return code      */
  CHAR      return_buffer[250];          /* returned buffer            */
                                     /* build the argument string  */
  CHAR      retval[1];
  retval[0] = '\0';

  if( args > 2 ) {
    MAKERXSTRING( argv[0], argn[1], strlen( argn[1] ) );
  } else {
    MAKERXSTRING( argv[0], retval, strlen( retval ) );
  }
                                       /* set up default return      */
  MAKERXSTRING(retstr, return_buffer, sizeof(return_buffer));
  return_code = RexxStart(args,           /* one argument               */
                          argv,        /* argument array             */
                          argn[1], /* REXX procedure name        */
                          NULL,        /* use disk version           */
                          NULL,    /* default address name       */
                          RXCOMMAND,   /* calling as a subcommand    */
                          NULL,        /* no exits used              */
                          &rc,         /* converted return code      */
                          &retstr);    /* returned result            */
                                       /* process return value       */
                                       /* need to return storage?    */
  if (RXSTRPTR(retstr) != return_buffer)
    DosFreeMem(RXSTRPTR(retstr));      /* release the RXSTRING       */

  return 0;
}
