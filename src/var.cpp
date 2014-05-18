/****************************************************************************
*
*  var.cpp
*
*  Create:  Dec 12 2004
*  Update:  Sep 23 2005
*  © Jan-Erik Lärka 2004 - 2005
*
****************************************************************************/
#pragma inline_depth 0;
#include "var.hpp"


int var :: len() const {
   int slength = 0;
   char *p = string;
   while( *p ) { p++; slength++; }
   return slength; // Return number of characters
}

int var :: len( const char* s1 ) const {
   int slength = 0;
   const char *p = s1;
   while( *p ) { p++; slength++; }
   return slength; // Return number of characters
}

int var :: words( const char delimiter ) const { //Return number of words in string delimited by a character ( ' ' space by default )
   int words = 0;
/*   for ( int i = 1; i < alloc_size & string[ i ] != '\0'; i++ )
      if ( string[ i - 1 ] != delimiter & string[ i ] == delimiter ) words++;
*/
   const char *p = string;
   while( *p ) {
      if ( p[0] == delimiter )
         words++;
      p++;
   }
   p--;
   if( p[0] != delimiter && p[0] != '\0' )
      words++;
   return words;
}

int var :: words( const char* delimiters ) const { //Return number of words in string delimited by a one or more characters ( " " space by default )
   int words = 0, i = 0, j = 0, strlen = len( delimiters );
   for( ; i < alloc_size & string[ i ] != '\0'; words++ ) { // Word count
      for( ; i < alloc_size & string[ i ] != '\0' & j < strlen; i++ ) // Spaces
         for( j = 0; string[ i ] != delimiters[ j ] & j < strlen; j++ ); // Delimiters
      for( ; i < alloc_size & string[ i ] != '\0' & j == strlen; i++ ) // Text to form Word
         for( j = 0; string[ i ] != delimiters[ j ] & j < strlen; j++ ); // Delimiters
   }
   return words;
}

var& var :: flush() {
    if( !static_size ) {
        delete [] string; // Delete string
        alloc_size = 0; // Reset size allocated
        string = new char[ alloc_size + 1 ]; // Create a new string specified by size
    }
    return clean(); // Return reference to this object
}

var& var :: clean() {
    if( string != NULL )
        for( int i = 0; i <= alloc_size /*&& string[ i ] != '\0'*/; i++ ) string[ i ] = '\0'; // Overwrite with '\0'
    return ( *this ); // Return reference to this object
}

var& var :: reSize( int stat_size, bool stat, bool truncate ) {
   int i = 0, slength = len();
   static_size = stat;
   alloc_size = ( stat_size > -1 ) ? truncate ? min( stat_size, slength ) : max( stat_size, slength ) : slength;
   // Determine size to allocate
   if( !static_size )
   {
      char* temp = new char[ alloc_size + 1 ]; // Create a temporary string
      if( temp != NULL ) {
         for( i = 0; i < min( slength, alloc_size ); i++ ) temp[ i ] = string[ i ]; // Copy parts of string to temp storage
         delete [] string; // Delete string
         string = temp;
      }
   } else i = slength;
   for( ; i <= alloc_size; i++ ) string[ i ] = '\0'; // Fill remaining part of string with '\0'
   return ( *this ); // Return reference to this object
}

int cmp( const var &v, const var &v2, bool exact ) {
   return v.cmp( v2.string, exact ); // Reuse method (member function)
}

int cmp( const char* s1, const char* s2, bool exact ) {
   var temp( s1 ); // Create a temporary copy
   return temp.cmp( s2, exact ); // Reuse method (member function)
}

int var :: cmp( const char* s2, bool exact ) const {
   long s1_long = atof( string ), s2_long = atof( s2 ); // Convert strings to long
//   if ( ( s1_long != 0 || string[0] == '0' )  && ( s2_long != 0  || s2[0] == '0' ) ) return s1_long - s2_long;
   // If both are valid numbers, compare them
   int slength = 0, stop = min( alloc_size, len( s2 ) ); // Calculate length of string
   if ( exact ) // If we want non-caseless match
     while ( string[ slength ] == s2[ slength ] && slength < stop ) slength++; // While equal
   else
     while ( toupper( string[ slength ] ) == toupper( s2[ slength ] ) && slength < stop ) slength++; // While equal
   return ( slength == 0 )?1:( slength == stop )?0:( ( int )( string[ slength ] ) > ( int )( s2[ slength ] ) )?slength:-slength; // Determine if they are equal or where they differ.
   // Equal
   // Ascii code number.
   // s2 larger than string
}

int cmp( const var &v, const char c, bool exact ) {
   return v.cmp( c, exact ); // Reuse method (member function)
}

int var :: cmp( const char c, bool exact ) const {
   if ( string[ 0 ] == '\0' || c == '\0' ) return 0; // If string start with or character equals '\0'
   if ( exact ) // If we want non-caseless match
     if ( ( int )( string[ 0 ] ) > ( int )( c ) ) return 1; // Larger
     else if ( ( int )( string[ 0 ] ) == ( int )( c ) ) return 0; // Equal
     else return -1; // Smaller
   else if ( toupper( string[ 0 ] ) > toupper( c ) ) return 1; // Larger
   else if ( toupper( string[ 0 ] ) == toupper( c ) ) return 0; // Equal
   else return -1; // Smaller
}

int var :: cmp( const var &v, bool exact ) const {
   return cmp( v.string, exact ); // Reuse method (member function)
}


var cpy( var &v, const var &v2 ) { //Copy string to another
   return v.cpySub( v2 ); // Reuse method (member function)
}

var& var :: cpy( const var &v2 ) { //Copy string to another
   return cpySub( v2.string, 0, -1, static_size ? v2.allocated() : v2.len() );
}

var& var :: cpy( const char* s, const int size  ) { //Copy string to another
   return cpySub( s, 0, -1, size );
}

var cpy( var &v, const char c ) { //Copy character to string
   return v.cpy( c );
}

var& var :: cpy( const char c ) { //Copy character to string
   alloc_size = ( static_size ) ? alloc_size : 1;
   if ( !static_size ) {
      delete [] string;
      string = new char[ alloc_size + 1 ];
   }
   if( string != NULL ) {
       string[ 0 ] = c;
       for( int i = 1; i <= alloc_size; i++ ) string[ i ] = '\0';
   }
   return ( *this );
}

var& var :: cpy( const int i ) { //Copy integer to string
   char temp[35];
   itoa( i, temp, 10 );
   return cpy( temp );
}

var& var :: cpy( const long l ) { //Copy long to string
   char temp[35];
   ltoa( l, temp, 10 );
   return cpy( temp );
}

var& var :: cpy( const double d ) { //Copy double/float to string
   char temp[35];
   gcvt( d, 10, temp );
   return cpy( temp );
}

var& var :: cpySub( const var &v2, const int start, const int stop  ) { //Copy parts of a string to another
   return cpySub( v2.string, start, stop, v2.allocated() );
}

var& var :: cpySub( const char* s, const int start, const int stop, const int size  ) { //Copy parts of a string to another
   alloc_size = static_size ? alloc_size : size < 0 ? len( s ) : size;
   int i = 0, to_start = min( max( 0, start ), alloc_size );
   int to_stop = min( max( to_start, stop < 0 ? len( s ) : stop ), alloc_size );
   if( to_start != to_stop ) {
      if ( !static_size ) {
         delete [] string;
         string = new char[ alloc_size + 1 ];
      }
      if( string != NULL ) {
         for( ; i <= to_stop - to_start; i++ ) string[ i ] = s[ to_start + i ];
         for( ; i <= alloc_size; i++ ) string[ i ] = '\0';
      }
   } else if( to_stop == 0 )
      return flush();
   return ( *this );
}
//#ifdef VAR_RX
var& var :: set( RXSTRING &rxString ) {
   rxString.strptr = string;
   rxString.strlength = alloc_size;
   return ( *this );
}

var& var :: set( RXSTRING *rxString ) {
   strcpy( rxString->strptr, string );
   rxString->strlength = static_size ? len(): alloc_size;
   return ( *this );
}

var& var :: flush( RXSTRING &rxString ) {
   rxString.strptr = 0;
   rxString.strlength = 0;
   return ( *this );
}

var& var :: get( PRXSTRING rxString ) {
    if( rxString->strptr && rxString->strlength )
        cpy( rxString->strptr, rxString->strlength );
    return ( *this );
}
//#endif

var& var :: reverse() {
   char temp;
   char *p, *p2;

   p = string;
   p2 = string;
   while( *p ) p++;
   while( p > p2 ) {
      p--;
      temp = *p;
      *p = *p2;
      *p2 = temp;
      p2++;
   }
   return ( *this );
}

var& var :: cat( const var &v2 ) { //Join two strings
   int s2length = ( v2.isAutoResizable() ) ? v2.allocated() : v2.len(), i = 0;
   if ( !static_size ) {
      char* temp = new char[ alloc_size + s2length + 1 ];
      for ( ; i < alloc_size; i++  ) temp[ i ] = string[ i ];
      delete [] string;
      string = temp;
      alloc_size += s2length;
   } else i = len();
   for ( int j = 0; j < s2length && i < alloc_size; i++, j++ ) string[ i ] = v2.string[ j ];
   for( ; i <= alloc_size; i++  ) string[ i ] = '\0';
   return ( *this );
}

var& var :: revCat( const var &v2 ) { //Join two strings
   int s2length = ( v2.isAutoResizable() ) ? v2.allocated() : v2.len(), slength = static_size ? len() : alloc_size, i = 0;
   char* temp = new char[ slength + s2length + 1 ];
   for ( ; i < slength && i + s2length < alloc_size; i++ ) temp[ i + s2length ] = string[ i ];
   if ( !static_size ) {
      delete [] string;
      string = temp;
      alloc_size = slength + s2length;
   } else {
      for( i = s2length; i < slength && i + s2length < alloc_size; i++ ) string[ i ] = temp[ i ];
      delete [] temp;
   }
   for( ; i <= alloc_size; i++ ) string[ i ] = '\0';
   for( i = 0; i < s2length; i++ ) string[ i ] = v2.string[ i ];
   return ( *this );
}

var& var :: revCat( const char c ) { //Join two strings
   int i = 0, start_pos = min( alloc_size, len() );
   if ( !static_size ) {
      char* temp = new char[ alloc_size + 2 ];
      for ( ; i < alloc_size; i++ ) temp[ i + 1 ] = string[ i ];
      alloc_size++;
      delete [] string;
      string = temp;
   } else
      for ( i = start_pos; i > 0; i-- ) string[ i ] = string[ i - 1 ];
   string[ 0 ] = c;
   for( i = start_pos; i <= alloc_size; i++  ) string[ i ] = '\0';
   return ( *this );
}


var cat( var &v, const var &v2 ) { //Join two strings
   return v.cat( v2 );
}

var& var :: cat( const char c ) { //Join string and character
   int i = 0;
   if ( !static_size ) {
      char* temp = new char[ alloc_size + 2 ];
      for ( ; i < alloc_size; i++ ) temp[ i ] = string[ i ];
      alloc_size++;
      delete [] string;
      string = temp;
   } else
      i = len();
   string[ i++ ] = c;
   for( ; i <= alloc_size; i++  ) string[ i ] = '\0';
   return ( *this );
}

var cat( var &v, const char c ) { //Join string and character
   return v.cat( c );
}

var& var :: cat( const int i2 ) { //Join string and number
   char num[ 35 ];
   itoa( i2, num, 10 );
   return cat( num );
}

var cat( var &v1, const int i2 ) { //Join string and number
   return v1.cat( i2 );
}

var& var :: cat( const double d2 ) { //Join string and number
   char num[ 35 ];
   gcvt( d2, 10, num );
   return cat( num );
}

var cat( var &v1, const double d2 ) { //Join string and number
   return v1.cat( d2 );
}

var& var :: cat( const long l2 ) { //Join string and number
   char num[ 35 ];
   ltoa( l2, num, 10 );
   return cat( num );
}

var cat( var &v1, const long l2 ) { //Join string and number
   return v1.cat( l2 );
}

var var :: split( const int pos, int skip ) { //Split and return string( s )
   var retval;
   retval.cpySub( string, abs( pos ) + abs( skip ), -1, static_size ? len() : alloc_size );
   substr( 0, abs( pos ) );
   return retval;
}

var var :: split( const var &needle, bool skip ) {
   int slength, pos = boyerMooreSearch( needle );
   if ( skip )
      slength = needle.isAutoResizable() ? needle.allocated() : needle.len();
   else
      slength = 0;

   if ( pos == -1 )
      return NULL;
   else
      return split( pos, slength );
}

var var :: split( const char needle, int start, int n ) {
   int pos = bruteForceSearch( needle, start );
   if ( pos == -1 )
      return ( *this );
   else
      return split( pos, n );
}

var var :: split( char* &s1, const int pos, int skip ) { //Split and return string( s )
   var retval;
   retval.cpySub( s1, abs( pos ) + abs( skip ), -1, -1 );
   cpySub( s1, 0, abs( pos ), -1 );
   return retval;
}

var& var :: remstr( const int pos, int n ) { //Remove ( middle ) and return resulting string
   return cpySub( string, 0, pos, -1 ).cat( cpySub( string, abs( pos ) + abs( n ), -1, -1 ) );
}

var remstr( var &v, const int pos, int n ) { //Remove ( middle ) and return resulting string
   return v.remstr( pos, n );
}

var remstr( char* s1, const int pos, int n ) { //Remove ( middle ) and return resulting string
   var temp( s1 );
   return temp.remstr( pos, n );
}

var& var :: substr( int start, int stop, char pad ) { //Return part of string
   stop = ( stop < 0 ) ? alloc_size : stop;
   if ( start > stop ) {
      int t_num = start;
      start = stop;
      stop = t_num;
   }
   start = min( abs( start ), alloc_size );
   int n = min( abs( stop - start ), alloc_size - start );
   int i = 0;
   char* temp = new char[ n + 1 ];
   if( temp != NULL )
   {
      for ( ; i < n; i++ ) temp[ i ] = string[ i + start ];
      if ( !static_size )
      {
         delete [] string;
         alloc_size = n;
         string = temp;
      } else {
         for ( i = 0; i < n; i++ ) string[ i ] = temp[ i ];
         delete [] temp;
      }
      for ( ; i < min( stop, alloc_size ); i++ ) string[ i ] = pad;
      for ( ; i < alloc_size + 1; i++  ) string[ i ] = '\0';
   }
   return ( *this );
}

var& var :: substrOf( var &v, int start, int stop, char pad ) const { //Return part of string
   return v.substr( start, stop, pad );
}

var& var :: between( const var& after, const var& before, const bool exact ) { //Return part of string
    return rightOf( after, exact ).leftOf( before, exact );
}

var& var :: revBetween( const var& after, const var& before, const bool exact ) { //Return part of string
   int pos, endpos;
   var haystack( *this ), startNeedle( after ), endNeedle( before );
   endNeedle.reverse();
   if( !exact ) {
       pos = haystack.upper().boyerMooreSearch( startNeedle.upper() );
       endpos = haystack.reverse().boyerMooreSearch( endNeedle.upper() );
   } else {
       pos = boyerMooreSearch( after );
       endpos = haystack.reverse().boyerMooreSearch( endNeedle );
   }

   if ( pos == -1 && endpos == -1 )
      return (*this);
   pos = ( pos == -1 ) ? 0: pos + after.len();
   endpos = ( static_size ? len() : alloc_size ) - ( endpos > -1 ? endpos : 0 ) - before.len();
   return substr( pos, endpos, '\0' );
}

var& var :: notBetween( const var& from, const var& until, const bool exact ) { //Return part of string
    if( boyerMooreSearch( from ) > -1 ) {
        var temp( split( from, exact ) );
        return cat( temp.rightOf( until, exact ) );
    } else
        return ( *this );
}

var& var :: subWord( int start_word, int nr_words, const char* delimiters ) { //Return part (word) of string
   int word, a, b, i = 0, j = 0, k = 0, strlen = len( delimiters ), word_count = ( nr_words < 0 ) ? words( delimiters ) : abs( nr_words + start_word );

   for( word = 0; word < start_word & i < alloc_size; word++ ) { // Word count
      for( i = k; i < alloc_size & string[ i ] != '\0' & j < strlen; i++ ) // Spaces
         for( j = 0; string[ i ] != delimiters[ j ] & j < strlen; j++ ); // Delimiters
      for( k = i + 1; k < alloc_size & string[ k ] != '\0' & j == strlen; k++ ) // Text to form Word
         for( j = 0; string[ k ] != delimiters[ j ] & j < strlen; j++ ); // Delimiters
   }
   for( a = b = k; word < word_count & a < alloc_size; word++ ) { // Word count
      for( a = b; a < alloc_size & string[ a ] != '\0' & j < strlen; a++ ) // Spaces
         for( j = 0; string[ a ] != delimiters[ j ] & j < strlen; j++ ); // Delimiters
      for( b = a + 1; b < alloc_size & string[ b ] != '\0' & j == strlen; b++ ) // Text to form Word
         for( j = 0; string[ b ] != delimiters[ j ] & j < strlen; j++ ); // Delimiters
   }
   return substr( max( a - 1 , 0 ), max( ( b == 0 ) ? alloc_size : b - ( b < alloc_size ), 0 ) );
   //return substr( max( i - 1 , 0 ), max( ( b == 0 ) ? alloc_size : b - ( b < alloc_size ), 0 ) );
}

var& var :: lastWord( const char* delimiters ) { //Return the last part (word) of string
    int wrds = words( delimiters );
    if( wrds > 1 )
        return subWord( wrds, 1, delimiters );
    else
        return ( *this );
}

bool var :: containWord( const var& wrd, const char* delimiters, const char additional, const bool exact ) {
    int wrds = words();
    for( int i = 0; i < wrds; i++ )
        if( copyOf().subWord( i, 1, delimiters ).strip( additional ).cmp( wrd, exact ) == 0 ) return TRUE;
    return FALSE;
}

double var :: trunc() {
   if ( isNumeric() ) {
      double s1num = atof( string );
      var s1pre( 35 );
      gcvt( s1num, 10, s1pre ); //Double to string
      substr( s1pre.reSize().len() );
      return s1num;
   }
   return 0;
}

var& var :: cal( const var& s2, Calc calc ) {
   if ( isNumeric() && s2.isNumeric() ) {
      double s1num = atof( string ), s2num = atof( s2.string );
      var s1pre( 35 ), s1post( 35 ), s2pre( 35 );
      gcvt( s1num, 10, s1pre ); //Double to string
      gcvt( s2num, 10, s2pre ); //Double to string
      s1pre.reSize();
      s2pre.reSize();
      switch ( calc ) {
      case Sub:
         s1num -= s2num;
         break;
      case Div:
         if ( s2num > 0 )
            s1num /= s2num;
         break;
      case Mult:
         s1num *= s2num;
         break;
      default:
        s1num += s2num;
        break;
      } /* endswitch */
      gcvt( s1num, 10, s1post );
      s1post.reSize();
      if ( !isAlpha() && s2.isAlpha() ) {
        cpy( s1post ).cat( s2.copyOf().substr( s2pre.alloc_size ) );
      } else if ( isAlpha() && !s2.isAlpha() ) {
        cpy( s1post.cat( rightOf( s1pre ) ) );
      } else
        substr( s1pre.allocated() ).revCat( s1post ).cat( s2.copyOf().substr( s2pre.alloc_size ) );
   } else {
      if ( calc == Sub ) removeText( s2 );
      else if ( calc == Div ) split( s2, false );
      else if ( calc == Add ) cat( s2 );
   } /* else if */
   return ( *this );
}

var& var :: calRight( const var& s2, Calc calc ) {
   int pos = reverseContains( "0123456789" );
   if ( pos > 0 && s2.isNumeric() ) {
      double s1num = atof( copyOf().right( max( alloc_size - pos, 0 ) ) ), s2num = atof( s2.string );
      var s1pre( 35 ), s1post( 35 ), s2pre( 35 );
      gcvt( s1num, 10, s1pre ); //Double to string
      gcvt( s2num, 10, s2pre ); //Double to string
      s1pre.reSize();
      s2pre.reSize();
      switch ( calc ) {
      case Sub:
         s1num -= s2num;
         break;
      case Div:
         s1num /= s2num;
         break;
      case Mult:
         s1num *= s2num;
         break;
      default:
        s1num += s2num;
        break;
      } /* endswitch */
      gcvt( s1num, 10, s1post );
      s1post.reSize();
      if ( pos + 1 < alloc_size )
         left( pos + 1 );
      cat( s1post );
   } else {
      if ( calc == Sub ) removeText( s2 );
      else if ( calc == Div ) split( s2, false );
      else if ( calc == Add ) cat( s2 );
   } /* else if */
   return ( *this );
}


int var :: boyerMooreSearch( const var &needle ) const {
  int i, j;
  int skip[256];
  int M = needle.isAutoResizable()?needle.allocated():needle.len();

  for ( i = 0; i < 256; ++i ) skip[ i ] = M;
  for ( i = 0; i < M; ++i ) skip[ needle.string[ i ] ] = M - 1 - i;

  for ( i = j = M - 1; j >= 0; --i, --j )
    while ( string[ i ] != needle.string[ j ] ) {
      i += max( M - j, skip[ string[ i ] ] );
      if ( i >= alloc_size ) return -1;
      j = M - 1;
    }
  return i + 1;
}

int var :: reverseBoyerMooreSearch( const var &needle ) const {
    var haystack( *this ), v( needle );
    return haystack.reverse().boyerMooreSearch( v.reverse() );
}

int boyerMooreSearch( var &haystack, const var &needle ) {
   return haystack.boyerMooreSearch( needle );
}

int var :: bruteForceSearch( const char needle, int start, bool exact ) const {
   int i = ( start < 0 ) ? 0 : min( start, alloc_size );
   if ( exact )
     for( ; i < alloc_size; i++ ) if( string[ i ] == needle ) return i;
   else
     for( ; i < alloc_size; i++ ) if( toupper( string[ i ] ) == toupper( needle ) ) return i;
   return -1;
}

int bruteForceSearch( var &haystack, const char needle, int start, bool exact ) {
   return haystack.bruteForceSearch( needle, start, exact );
}

int var :: reverseBruteForceSearch( const char needle, int start, bool exact ) const {
   int i = ( start < 0 ) ? alloc_size : min( start, alloc_size );
   if ( exact )
     for( ; i > -1; i-- ) if( string[ i ] == needle ) return i;
   else
     for( ; i > -1; i-- ) if( toupper( string[ i ] ) == toupper( needle ) ) return i;
   return -1;
}

int reverseBruteForceSearch( const var &haystack, const char needle, int start, bool exact ) {
   return haystack.reverseBruteForceSearch( needle, start, exact );
}

bool var :: wordBeginsWith( const var &tablei, const char* delimiters, bool exact ) const {
   int count = words( delimiters );
   var temp = copyOf();
   for( int i = 0; i < count; i++ ) {
      if( temp.subWord( 0, 1, delimiters ).beginsWith( tablei, 0, exact ) ) return TRUE;
   }
   return FALSE;
}

bool var :: beginsWith( const var &tablei, int start, bool exact ) const {
   int i = ( start < 0 ) ? 0 : min( start, alloc_size );
   for( ; i < alloc_size && i < tablei.allocated() ; i++ ) {
     if( exact ) {
       if( string[ i ] != tablei.string[ i ] ) goto done;
     } else {
       if( toupper( string[ i ] ) != toupper( tablei.string[ i ] ) ) goto done;
     }
   }
   done:
   return ( i >= ( start + tablei.len() ) );
}


int var :: containsWord( const var &tablei, char delimiter, bool exact ) const {
    int pos;
    if( exact )
        pos = boyerMooreSearch( tablei.copyOf().strip() );
    else
        pos = boyerMooreSearch( tablei.copyOf().strip().upper() );
    if( pos > -1 ) {
        if( tablei.len() == len() ) return pos;
        if( pos > 0 ) {
            if( string[ pos - 1 ] == delimiter ) {
                if( pos + tablei.len() == len() ) return pos; //Ending
                else if( string[ pos + tablei.len() + 1 ] == delimiter ) return pos; //Space after
            }
        }
    }
    return -1;
}

bool var :: isWithin( const var &tablei, int start, bool exact ) const {
  return tablei.contains( string, start, exact ) != -1;
}

bool var :: isWithin( const char *tablei, int start, bool exact ) const {
  var table( tablei );
  return table.contains( string, start, exact ) != -1;
}

int var :: within( const var &tablei, int start, bool exact ) const {
   return contains( tablei, start, exact, false );
}

int var :: within( const char *tablei, int start, bool exact ) const {
  var table( tablei );
  return table.contains( string, start, exact, false );
}

int var :: contains( const var &tablei, int start, bool exact, bool diff ) const {
   int j, i = ( start < 0 ) ? 0 : min( start, alloc_size ) - 1;
   restart:
   for( i++; i < alloc_size; ) {
       for( j = 0; j < tablei.allocated(); j++ ) {
           if( exact ) {
               if( string[ i + j ] != tablei.string[ j ] ) goto restart;
           } else {
               if( toupper( string[ i + j ] ) != toupper( tablei.string[ j ] ) ) goto restart;
           }
       }
       return diff ? j : i;
   }
   return -1;
}

int var :: contains( const char* tablei, int start, bool exact ) const {
  var table( tablei );
  return contains( table, start, exact );
}

int var :: contains( const char tablei, int start, bool exact ) const {
  var table;
  return contains( table.cpy( tablei ), start, exact );
}

bool var :: onlyContains( const char needle, int start, bool exact ) const {
   int i = ( start < 0 ) ? 0 : min( start, alloc_size );
   for( ; i < alloc_size; i++ )
      if ( exact ) {
         if( string[ i ] != needle ) return false;
      } else if ( toupper( string[ i ] ) != toupper( needle ) ) return false;
   return true;
}

int var :: reverseContains( var &tablei, int start, bool exact ) const {
   int j, i = ( start > 0 ) ? min( start, alloc_size ) : alloc_size;
   found:
   i--;
   for( ; i > -1; ) {
      for( j = 0; j < tablei.allocated(); j++ ) {
         if ( exact ) {
            if( string[ i ] == tablei[ j ] ) goto found;
         } else {
            if( toupper( string[ i ] ) == toupper( tablei[ j ] ) ) goto found;
         }
      }
      return i;
    }
    return -1;
}

int var :: reverseContains( const char* tablei, int start, bool exact ) const {
  var table( tablei );
  return reverseContains( table, start, exact );
}

var& var :: left( int pos ) {
   return substr( 0, pos, '\0' );
}

var& var :: middle( int length ) {
   return remstr( ( alloc_size - length ) / 2, length );
}

var& var :: right( int pos ) {
   return substr( min( alloc_size, abs( alloc_size - pos ) ), -1, '\0' );
}

var& var :: right( const var &v ) {
   int pos = boyerMooreSearch( v ); // "this" implied
   if ( pos == -1 )
      return ( *this );
   else
     return substr( pos, -1, '\0' );
}

var& var :: leftOf( const var &v, const bool exact, int startPos ) {
   int pos;
   if( startPos > 0 || !exact ) {
       var haystack( *this );
       if( startPos > 0 )
           haystack.substr( startPos );
       if( exact )
           pos = haystack.boyerMooreSearch( v );
       else {
           var needle( v );
           pos = haystack.upper().boyerMooreSearch( needle.upper() );
       }
   } else pos = boyerMooreSearch( v );

   if ( pos == -1 )
      return (*this);
   else
      return substr( startPos, pos, '\0' );
}

var var :: splitTo( const int pos, int skip ) { //Split and return string( s )
   var retval;
   retval.cpySub( string, 0, abs( pos ), static_size ? len() : alloc_size );
   substr( abs( pos ) + abs( skip ), -1, static_size ? len() : alloc_size );
   return retval;
}

var var :: splitTo( const var &needle, bool skip ) {
   int slength, pos = boyerMooreSearch( needle );
   if ( pos == -1 )
      return ( *this );
   else if ( skip )
      slength = needle.isAutoResizable()?needle.allocated():needle.len();
   else
      slength = 0;
   return splitTo( pos, slength );
}

var var :: splitTo( const char needle, int start, int n ) {
   int pos = bruteForceSearch( needle, start );
   if ( pos == -1 )
      return ( *this );
   else
      return splitTo( pos, n );
}

var& var :: toLast( const char needle ) {
   int pos = reverseBruteForceSearch( needle );
   if ( pos == -1 )
      return ( *this );
   else
      return substr( 0, pos + 1, '\0' );
}

var& var :: afterLast( const char needle ) {
   int pos = reverseBruteForceSearch( needle );
   if ( pos == -1 )
      return ( *this );
   else
      return substr( pos + 1, alloc_size, '\0' );
}

var& var :: rightOf( const var &v, const bool exact, int startPos ) {
   int pos;
   if( startPos > 0 || !exact ) {
       var haystack( *this );
       if( startPos > 0 )
           haystack.substr( startPos );
       if( exact )
           pos = haystack.boyerMooreSearch( v );
       else {
           var needle( v );
           pos = haystack.upper().boyerMooreSearch( needle.upper() );
       }
   } else pos = boyerMooreSearch( v );

   if ( pos == -1 )
      return ( *this );
   else
      return substr( startPos + pos + ( v.isAutoResizable()?v.allocated():v.len() ), -1, '\0' );
}

var& var :: addRightOf( const var &v2 ) { //Join two strings
   return revCat( v2 );
}

var var :: word( int n, const char c ) const {
   int startpos = 0, stoppos;
   for( int i = 0; i < n && startpos < alloc_size; i++  ) startpos = bruteForceSearch( c, startpos );
   stoppos = ( startpos > -1 )?bruteForceSearch( c, startpos ):-1;
   return copyOf().substr( startpos > -1 ? startpos : 0, ( stoppos > -1 ) ? stoppos : alloc_size );
}

var& var :: removeText( const var &needle ) {
   int slength = needle.isAutoResizable()?needle.allocated():needle.len(), pos = boyerMooreSearch( needle );
   if ( pos == -1 )
      return ( *this );
   else
      return remstr( pos, slength );
}

var& removeText( var &haystack, const var &needle ) {
   return haystack.removeText( needle );
}

var& var :: removeChar( const char needle ) {
   int pos = bruteForceSearch( needle );
   pos = ( pos < 0 )?alloc_size:pos;
   for ( ; pos < alloc_size; pos++  ) {
      remstr( pos, 1 );
      pos = bruteForceSearch( needle, pos ) - 1;
      pos = ( pos < 0 )?alloc_size:pos;
   } /* endfor */
   return ( *this );
}

var& removeChar( var &haystack, const char needle ) {
   return haystack.removeChar( needle );
}

var& var :: removeByChar( const var &needle ) {
   for ( int i = 0; i < needle.alloc_size; i++  ) removeChar( needle.string[ i ] );
   return ( *this );
}

var& var :: translateChar( const char from, const char to ) {
   int pos = bruteForceSearch( from );
   pos = ( pos < 0 )?alloc_size:pos;
   for ( ; pos < alloc_size; pos++  ) {
/*      if ( to == '\0' ) remstr( pos, 1 );
      else*/ this[ pos ] = to;
      pos = bruteForceSearch( from, pos ) - 1;
      pos = ( pos < 0 )?alloc_size:pos;
   } /* endfor */
   return ( *this );
}

var& var :: translateByChar( const var &from, const var &to ) {
   int i = 0, pos = 0, flength = from.alloc_size, slength = min( flength, to.alloc_size ); //From larger...remove other, to larger...ignore
   for ( ; i < slength; i++  ) translateChar( from.string[ i ], to.string[ i ] );
   for ( ; i < flength; i++  ) translateChar( from.string[ i ], '\0' );
   return ( *this );
}

var& var :: upper( ) {
   for ( int i = 0; i < alloc_size; i++ )
      string[ i ] = toupper( string[ i ] );
   return ( *this );
}

var& var :: lower( ) {
   for ( int i = 0; i < alloc_size; i++ )
      string[ i ] = tolower( string[ i ] );
   return ( *this );
}

var& var :: strip( const char c, Strip type ) {
   int start = 0, stop = alloc_size;
   if ( type != Trailing ) {
      while( string[ start ] == c && start < alloc_size )
         start++;
   }
   if ( type != Leading ) {
      while( string[ stop - 1 ] == c && 0 < stop )
         stop--;
   }
   return substr( start, stop );
}

var& var :: stripTrailing( const char c ) {
   int stop = static_size ? len() : alloc_size;
   while( string[ --stop ] == c && 0 < stop ) {
      if ( static_size ) string[ stop ] = '\0';
   }
   if ( static_size ) return ( *this );
   else return substr( 0, stop + 1 );
}

var& var :: insert( var &v, int pos, bool truncate ) {
   int i = 0, v_pos = abs( pos ), slength = static_size?len():alloc_size, vlength = v.isAutoResizable()?v.allocated():v.len();
   alloc_size += ( static_size && ( truncate || slength + vlength <= alloc_size ) )?0:slength;
   char* temp = new char[ alloc_size + 1 ];
   if( temp != NULL ) {
       for( i = 0; i < v_pos; i++ ) temp[ i ] = string[ i ];
       for( ; i < v_pos + vlength; i++ ) temp[ i ] = v[ i - v_pos ];
       for( ; i <= alloc_size; i++ ) temp[ i ] = string[ i - vlength ];
   }
   delete [] string;
   string = new char[ alloc_size + 1 ];
   if( string != NULL )
       for( i = 0; i < alloc_size; i++ ) string[ i ] = temp[ i ];
   delete [] temp;
   return ( *this );
}

var& var :: offset( int off ) {
   int slength = static_size?len():alloc_size;
   for( int i = 0; i < slength; i++ )
      if ( isBetween( -1 - off, string[ i ], 256 - off ) )
        string[ i ] = string[ i ] + off;
   return ( *this );
}

bool var :: isInteger() const {
   int int_num = atoi( string );
   return ( ( int_num != 0 ) || ( string[0] == '0' && int_num == 0 ) );
}

bool var :: isInteger( const char* s1 ) const {
   int int_num = atoi( s1 );
   return ( ( int_num != 0 ) || ( s1[0] == '0' && int_num == 0 ) );
}

bool var :: isNumeric() const {
   if ( string[0] == '0' ) return TRUE;
   return atof( string ) != 0;
}

bool var :: isNumeric( const char* s1 ) const {
   if ( s1[0] == '0' ) return TRUE;
   return atof( s1 ) != 0;
}

bool var :: isAlpha() const {
   double num = atof( string );
   var temp( 35 );
   gcvt( num, 10, temp );
   temp.reSize();
   return ( temp.alloc_size < alloc_size );
}

bool var :: isAlpha( const char* s1 ) const {
   double num = atof( s1 );
   var temp( 35 );
   gcvt( num, 10, temp );
   temp.reSize();
   return ( temp.alloc_size < len( s1 ) );
}

bool var :: isBetween( const int pre, const int test, const int post ) const {
  return pre < test & test < post;
}

bool var :: isBetween( const int pre, const int post ) const {
  int test = atoi( string );
  return pre < test & test < post;
}

bool var :: isBetween( const char* pre, const char* post ) const {
  return cmp( pre ) > 0 & cmp( post ) < 0;
}

/***** operator *****/
ostream& operator << ( ostream& out, const var& v ) {
   out << v.string;
   return out;
}

istream& operator >> ( istream& in, const var& v ) {
   in >> v.string;
   return in;
}

var operator + ( const char* s1, const var& v ) {
   var temp( s1 );
   temp += v;
   return temp;
}

var operator + ( const char c, const var& v ) {
    var temp( 2 );
    temp[ 0 ] = c;
    temp[ 1 ] = '\0';
    return temp.cal( v, Add );
}

var operator + ( const int i, const var& v ) {
   var temp( 17 );
   itoa( i, temp, 10 );
   temp.reSize();
   return temp.cal( v, Add );
}

var operator + ( const long l, const var& v ) {
   var temp( 17 );
   ltoa( l, temp, 10 );
   temp.reSize();
   return temp.cal( v, Add );
}

var operator + ( const double d, const var& v ) {
   var temp( 35 );
   gcvt( d, 10, temp );
   temp.reSize();
   return temp.cal( v, Add );
}

var operator - ( const char* s1, const var& v ) {
   var temp( s1 );
   temp -= v;
   return temp;
}

var operator - ( const char c, const var& v ) {
    var temp( 2 );
    temp[ 0 ] = c;
    temp[ 1 ] = '\0';
    return temp.cal( v, Sub );
}

var operator - ( const int i, const var& v ) {
   var temp( 17 );
   itoa( i, temp, 10 );
   temp.reSize();
   return temp.cal( v, Sub );
}

var operator - ( const long l, const var& v ) {
   var temp( 17 );
   ltoa( l, temp, 10 );
   temp.reSize();
   return temp.cal( v, Sub );
}

var operator - ( const double d, const var& v ) {
   var temp( 35 );
   gcvt( d, 10, temp );
   temp.reSize();
   return temp.cal( v, Sub );
}

var operator * ( const int i, const var& v ) {
   var temp( 17 );
   itoa( i, temp, 10 );
   temp.reSize();
   return temp.cal( v, Mult );
}

var operator * ( const long l, const var& v ) {
   var temp( 17 );
   ltoa( l, temp, 10 );
   temp.reSize();
   return temp.cal( v, Mult );
}

var operator * ( const double d, const var& v ) {
   var temp( 35 );
   gcvt( d, 10, temp );
   temp.reSize();
   return temp.cal( v, Mult );
}

var operator / ( const char* s1, const var& v ) {
   var temp( s1 );
   temp /= v;
   return temp;
}

var operator / ( const char c, const var& v ) {
    var temp( 2 );
    temp[ 0 ] = c;
    temp[ 1 ] = '\0';
    return temp.cal( v, Div );
}

var operator / ( const int i, const var& v ) {
   var temp( 17 );
   itoa( i, temp, 10 );
   temp.reSize();
   return temp.cal( v, Div );
}

var operator / ( const long l, const var& v ) {
   var temp( 17 );
   ltoa( l, temp, 10 );
   temp.reSize();
   return temp.cal( v, Div );
}

var operator / ( const double d, const var& v ) {
   var temp( 35 );
   gcvt( d, 10, temp );
   temp.reSize();
   return temp.cal( v, Div );
}

var& var :: operator = ( const char* s2 ) {
   return cpy( s2 );
}

var& var :: operator = ( const char c ) {
   return cpy( c );
}

var& var :: operator = ( const var& v ) {
   return cpy( v );
}

var& var :: operator = ( const int i ) {
   return cpy( i );
}

var& var :: operator = ( const long l ) {
   return cpy( l );
}

var& var :: operator = ( const double d ) {
   return cpy( d );
}

bool var :: operator < ( const char* s2 ) const {
   return cmp( s2 ) < 0;
}

bool var :: operator < ( const char c ) const {
   return cmp( c ) < 0;
}

bool var :: operator < ( const var& v ) const {
   return cmp( v.string ) < 0;
}

bool var :: operator < ( const int i ) const {
   char num[ 17 ];
   itoa( i, num, 10 );
   return cmp( num ) < 0;
}

bool var :: operator < ( const long l ) const {
   char num[ 35 ];
   ltoa( l, num, 10 );
   return cmp( num ) < 0;
}

bool var :: operator < ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return cmp( num ) < 0;
}

bool var :: operator > ( const char* s2 ) const {
   return cmp( s2 ) > 0;
}

bool var :: operator > ( const char c ) const {
   return cmp( c ) > 0;
}

bool var :: operator > ( const var& v ) const {
   return cmp( v.string ) > 0;
}

bool var :: operator > ( const int i ) const {
   char num[ 17 ];
   itoa( i, num, 10 );
   return cmp( num ) > 0;
}

bool var :: operator > ( const long l ) const {
   char num[ 35 ];
   ltoa( l, num, 10 );
   return cmp( num ) > 0;
}

bool var :: operator > ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return cmp( num ) > 0;
}

bool var :: operator <= ( const char* s2 ) const {
   return !( cmp( s2 ) > 0 );
}

bool var :: operator <= ( const char c ) const {
   return !( cmp( c ) > 0 );
}

bool var :: operator <= ( const var& v ) const {
   return !( cmp( v.string ) > 0 );
}

bool var :: operator <= ( const int i ) const {
   char num[ 17 ];
   itoa( i, num, 10 );
   return !( cmp( num ) > 0 );
}

bool var :: operator <= ( const long l ) const {
   char num[ 35 ];
   ltoa( l, num, 10 );
   return !( cmp( num ) > 0 );
}

bool var :: operator <= ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return !( cmp( num ) > 0 );
}

bool var :: operator >= ( const char* s2 ) const {
   return !( cmp( s2 ) < 0 );
}

bool var :: operator >= ( const char c ) const {
   return !( cmp( c ) < 0 );
}

bool var :: operator >= ( const var& v ) const {
   return !( cmp( v.string ) < 0 );
}

bool var :: operator >= ( const int i ) const {
   char num[ 17 ];
   itoa( i, num, 10 );
   return !( cmp( num ) < 0 );
}

bool var :: operator >= ( const long l ) const {
   char num[ 35 ];
   ltoa( l, num, 10 );
   return !( cmp( num ) < 0 );
}

bool var :: operator >= ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return !( cmp( num ) < 0 );
}

bool var :: operator == ( const char* s2 ) const {
   return ( cmp( s2 ) == 0 );
}

bool var :: operator == ( const char c ) const {
   return ( cmp( ( char* )c ) == 0 );
}

bool var :: operator == ( const var& v ) const {
   return ( cmp( v.string ) == 0 );
}

bool var :: operator == ( const int i ) const {
   char num[ 17 ];
   itoa( i, num, 10 );
   return ( cmp( num ) == 0 );
}

bool var :: operator == ( const long l ) const {
   char num[ 35 ];
   ltoa( l, num, 10 );
   return ( cmp( num ) == 0 );
}

bool var :: operator == ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return ( cmp( num ) == 0 );
}

bool var :: operator ^= ( const char* s2 ) const {
   return ( cmp( s2, false ) == 0 );
}

bool var :: operator ^= ( const char c ) const {
   return ( cmp( c, false ) == 0 );
}

bool var :: operator ^= ( const var& v ) const {
   return ( cmp( v.string, false ) == 0 );
}

bool var :: operator ^= ( const int i ) const {
   char num[ 17 ];
   itoa( i, num, 10 );
   return ( cmp( num, false ) == 0 );
}

bool var :: operator ^= ( const long l ) const {
   char num[ 35 ];
   ltoa( l, num, 10 );
   return ( cmp( num, false ) == 0 );
}

bool var :: operator ^= ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return ( cmp( num, false ) == 0 );
}

bool var :: operator != ( const char* s2 ) const {
   return ( cmp( s2 ) != 0 );
}

bool var :: operator != ( const char s2 ) const {
   return ( cmp( s2 ) != 0 );
}

bool var :: operator != ( const var& v ) const {
   return ( cmp( v.string ) != 0 );
}

bool var :: operator != ( const int i ) const {
   return ( cmp( i ) != 0 );
}

bool var :: operator != ( const long l ) const {
   char num[ 17 ];
   ltoa( l, num, 10 );
   return ( cmp( num ) != 0 );
}

bool var :: operator != ( const double d ) const {
   char num[ 35 ];
   gcvt( d, 10, num );
   return ( cmp( num ) != 0 );
}

var& var :: operator  += ( const char* s2 ) {
   cal( s2, Add );
   return ( *this );
}

var& var :: operator  += ( const char c ) {
   cal( ( char * )c, Add );
   return ( *this );
}

var& var :: operator  += ( const var& v ) {
   cal( v, Add );
   return ( *this );
}

var& var :: operator  += ( const int i ) {
   var num( 17 );
   itoa( i, num, 10 );
   cal( num, Add );
   return ( *this );
}

var& var :: operator  += ( const long l ) {
   var num( 35 );
   ltoa( l, num, 10 );
   cal( num, Add );
   return ( *this );
}

var& var :: operator  += ( const double d ) {
   var num( 35 );
   gcvt( d, 10, num );
   cal( num, Add );
   return ( *this );
}

var& var :: operator -= ( const char* s2 ) {
   cal( s2, Sub );
   return ( *this );
}

var& var :: operator -= ( const char c ) {
   cal( ( char * )c, Sub );
   return ( *this );
}

var& var :: operator -= ( const var& v ) {
   cal( v, Sub );
   return ( *this );
}

var& var :: operator -= ( const int i ) {
   var num( 17 );
   itoa( i, num, 10 );
   cal( num, Sub );
   return ( *this );
}

var& var :: operator -= ( const long l ) {
   var num( 35 );
   ltoa( l, num, 10 );
   cal( num, Sub );
   return ( *this );
}

var& var :: operator -= ( const double d ) {
   var num( 35 );
   gcvt( d, 10, num );
   cal( num, Sub );
   return ( *this );
}

var& var :: operator *= ( const int i ) {
   var num( 17 );
   itoa( i, num, 10 );
   cal( num, Mult );
   return ( *this );
}

var& var :: operator *= ( const long l ) {
   var num( 35 );
   ltoa( l, num, 10 );
   cal( num, Mult );
   return ( *this );
}

var& var :: operator *= ( const double d ) {
   var num( 35 );
   gcvt( d, 10, num );
   cal( num, Mult );
   return ( *this );
}

var& var :: operator /= ( const char* s2 ) {
   cal( s2, Div );
   return ( *this );
}

var& var :: operator /= ( const char c ) {
   cal( ( char * )c, Div );
   return ( *this );
}

var& var :: operator /= ( const var& v ) {
   cal( v, Div );
   return ( *this );
}

var& var :: operator /= ( const int i ) {
   var num( 17 );
   itoa( i, num, 10 );
   cal( num, Div );
   return ( *this );
}

var& var :: operator /= ( const long l ) {
   var num( 35 );
   ltoa( l, num, 10 );
   cal( num, Div );
   return ( *this );
}

var& var :: operator /= ( const double d ) {
   var num( 35 );
   gcvt( d, 10, num );
   cal( num, Div );
   return ( *this );
}

var& var :: operator ++ () {
   return cal( "1", Add );
}

var& var :: operator -- () {
   return cal( "1", Sub );
}

var var :: operator + ( const char* s2 ) const {
   var temp( *this );
   temp += s2;
   return temp;
}

var var :: operator + ( const char c ) const {
   var temp( *this );
   temp += c;
   return temp;
}

var var :: operator + ( const var& v ) const {
   var temp( *this );
   temp += v;
   return temp;
}

var var :: operator + ( const int i ) const {
   var temp( *this );
   temp += i;
   return temp;
}

var var :: operator + ( const long l ) const {
   var temp( *this );
   temp += l;
   return temp;
}

var var :: operator + ( const double d ) const {
   var temp( *this );
   temp += d;
   return temp;
}

var var :: operator - ( const char* s2 ) const {
   var temp( *this );
   temp -= s2;
   return temp;
}

var var :: operator - ( const char c ) const {
   var temp( *this );
   temp -= c;
   return temp;
}

var var :: operator - ( const var& v ) const {
   var temp( *this );
   temp -= v;
   return temp;
}

var var :: operator - ( const int i ) const {
   var temp( *this );
   temp -= i;
   return temp;
}

var var :: operator - ( const long l ) const {
   var temp( *this );
   temp -= l;
   return temp;
}

var var :: operator - ( const double d ) const {
   var temp( *this );
   temp -= d;
   return temp;
}

var var :: operator * ( const int i ) const {
   var temp( *this );
   temp *= i;
   return temp;
}

var var :: operator * ( const long l ) const {
   var temp( *this );
   temp *= l;
   return temp;
}

var var :: operator * ( const double d ) const {
   var temp( *this );
   temp *= d;
   return temp;
}

var var :: operator / ( const char* s2 ) const {
   var temp( *this );
   temp /= s2;
   return temp;
}

var var :: operator / ( const char c ) const {
   var temp( *this );
   temp /= c;
   return temp;
}

var var :: operator / ( const var& v ) const {
   var temp( *this );
   temp /= v;
   return temp;
}

var var :: operator / ( const int i ) const {
   var temp( *this );
   temp /= i;
   return temp;
}

var var :: operator / ( const long l ) const {
   var temp( *this );
   temp /= l;
   return temp;
}

var var :: operator / ( const double d ) const {
   var temp( *this );
   temp /= d;
   return temp;
}

var& var :: operator ++ ( int ) { //Postfix
   return calRight( "1", Add );
}

var& var :: operator -- ( int ) { //Postfix
   return calRight( "1", Sub );
}

char& var :: operator [] ( const int i ) { // Safe, but missleading when i > alloc_size.
   return string[ alloc_size > 0 ? abs( i ) % alloc_size : 0 ];
}

var& var :: at( const int i ) { // Safe, but missleading when i > alloc_size.
   var temp( *this );
   return temp.substr( alloc_size > 0 ? abs( i ) % alloc_size : 0, 1 );
}
