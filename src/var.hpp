/****************************************************************************
*
*  var.hpp
*
*  Create:  Dec 12 2004
*  Update:  Jan 16 2009
*  © Jan-Erik Lärka 2004 - 2005
*
****************************************************************************/
#ifndef VAR_HPP
#define VAR_HPP
//#ifdef __cplusplus
//  #include <iostream>
//#else
  #include <iostream.h>
//#endif
#include <stdlib.h>
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <ctype.h>

#ifndef TRUE
  #define TRUE true
#endif
#ifndef FALSE
  #define FALSE false
#endif

/*#ifndef ULONG_TYPEDEFED
  typedef unsigned long ULONG ;
  #define ULONG_TYPEDEFED
#endif*/

//#ifdef VAR_RX
  #define INCL_REXXSAA
  #include <rexxsaa.h>
  #define __REXXSAA_H_INCLUDED
//#endif

#ifndef __REXXSAA_H_INCLUDED
  typedef struct RXSTRING_type
  {
    ULONG strlength ;
    char* strptr ;
  } RXSTRING;
  typedef RXSTRING *PRXSTRING ;
#endif

#ifdef __cplusplus
  using namespace std;
#endif

enum Calc { Add, Sub, Mult, Div };
enum Strip { Leading, Trailing, Both };

class var {
   private:
      char *string;     // Pointer to array that hold the string.
      int alloc_size;   // Maintained value to indicate size of array.
      bool static_size; // Maintained value to indicate if array use a static size.
   public:
/** Constructor alt. 1
 * var( size, <static size> )
 *
 * This constructor create the new object that can hold
 * a string of specified size. Additionally it's possible
 * to specify if the string/array should be static in size
 * or dynamically resizeable by the class.
 * Parameters:
 *                slength - number of characters (mandatory)
 *                s_size - static size (optional, FALSE by default)
 */
      var( int slength, bool s_size = false ) : static_size( s_size ) {
         if ( slength < 0 ) slength = 0;
         string = new char[ slength + 1 ];
         if( string != NULL ) {
             for( int i = 0; i <= slength; i++ ) string[ i ] = '\0';
             alloc_size = slength;
         }
      };
/** Constructor alt. 2 (Default constructor too)
 * var( <s>, <size>, <static size> )
 *
 * This constructor create the new object that can hold
 * a string of specified size. Additionally it's possible
 * to specify if the string/array should be dynamically
 * resizeable. If no parameters used it act as default
 * constructor and just prepare for futher use.
 * Parameters:
 *                s - string to set at creation (optional)
 *                slength - number of characters (optional)
 *                s_size - static size (optional, FALSE by default)
 */
      var( const char *s = NULL, int slength = 0, bool s_size = false ) : static_size( s_size ) {
         int i = 0, slength2 = 0;
/*         if ( slength < 0 )
            slength2 = slength = -slength;
         else*/
         if ( slength > -1 ) {
             if ( s != NULL ) while ( s[ slength2 ] != '\0' ) slength2++;
             slength = ( slength == 0 ) ? slength2 : slength;
             string = new char[ slength + 1 ];
             if( string != NULL ) {
                 if ( s != NULL ) for( ; i < slength2 && i < slength; i++ ) string[ i ] = s[ i ];
                 for( ; i <= slength; i++ ) string[ i ] = '\0';
                 alloc_size = slength;
             }
         }
      };
/** Copy constructor
 * var( class, <static size> )
 *
 * This copy constructor copy contence so it doesn't point to
 * same address space. Additionally it's possible to specify
 * if the target string/array should be dynamically resizeable.
 * Parameters:
 *                v - variable of class var with string (mandatory)
 *                s_size - static size (optional, FALSE by default)
 */
      var( const var& v, bool s_size = false ) : static_size( s_size ) {
         int slength = v.len();
         string = new char[ slength + 1 ];
         if( string != NULL ) {
             for( int i = 0; i < slength; i++ ) string[ i ] = v.string[ i ];
             string[ slength ] = '\0';
             alloc_size = slength;
         }
      };
/** Destructor
 * ~var()
 *
 * Destructor used to destroy allocated object and clean up memory.
 * Parameters:
 *                none
 */
      ~var() { delete [] string; };

/* Methods (Member functions) for class */
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#define max(a,b)  (((a) > (b)) ? (a) : (b))

//      /*friend*/ int max( int i, int i2 ) const { return ( i > i2 )? i : i2; }; // Handle only 2 params, possible to improve
//      /*friend*/ double max( double d, double d2 ) const { return ( d > d2 )? d : d2; }; // just add default values to more params
//      /*friend*/ double max( int i, double d ) const { return ( d > i )? d : i; }; // and change calculation routine.
//      /*friend*/ double max( double d, int i ) const { return ( i > d )? i : d; };
//      /*friend*/ int min( int i, int i2 ) const { return ( i < i2 )? i : i2; };
//      /*friend*/ double min( double d, double d2 ) const { return ( d < d2 )? d : d2; };
//      /*friend*/ double min( int i, double d ) const { return ( d < i )? d : i; };
//      /*friend*/ double min( double d, int i ) const { return ( i < d )? i : d; };
      bool isAutoResizable() const { return !static_size; }; // Return value indicating wheter the array can be resized
      bool isStaticInSize() const { return static_size; }; // or not.
      int len() const; // Calculate the size of current var (look for '\0').
      int len( const char* ) const; // Calculate the size of string provided (look for '\0').
      int words( const char delimiter = ' ' ) const; // Calculate number of words delimited by character ( ' ' space by default).
      int words( const char* delimiters ) const; // Calculate number of words delimited by one or more characters.
      int allocated() const { return alloc_size; }; // Return size set.
      var& flush(); // Flush the memory by freeing/deleting from memory.
      var& clean(); // Set item in array to '\0'.
      var& reSize( int stat_size = -1, bool stat = false, bool truncate = false ); // Resize array to desired size.
      friend int cmp( const var & , const var &, bool exact = true ); // Compare var with var, mixed case match or not.
      friend int cmp( const char* , const char* , bool exact = true );
      int cmp( const char* , bool exact = true ) const; // Compare with this object, mixed case match or not.
      friend int cmp( const var & , const char, bool exact = true );
      int cmp( const char, bool exact = true ) const;
      int cmp( const var& , bool exact = true ) const; // Compare with this object, mixed case match or not.
      var& cpy( const var & ); // Copy another object of class var to this object.
      var& cpy( const char*, const int );
      var& cpy( const char );
      var& cpy( const int );
      var& cpy( const long );
      var& cpy( const double );
      var copyOf() const {
          var temp( *this );
          return temp;
      };
      friend var cpy( var & , const var & ); // Copy another object of class var to another object of the class var.
      friend var cpy( var & , const char );
      var& cpySub( const var &, const int start = 0, const int stop = -1 ); // Copy another object of class var to this object.
      var& cpySub( const char*, const int start = 0, const int stop = -1, const int size = -1 );
      #ifdef INCL_REXXSAA
        var& set( RXSTRING &rxString ); // Copy string in this object to a rexx string.
        var& set( RXSTRING *rxString ); // Copy string in this object to a rexx string.
        var& flush( RXSTRING &rxString ); // Empty this rexx string.
        var& get( const PRXSTRING ); // Copy rexx string to this object.
      #endif
      var& reverse(); // Reverse the text
      var& cat( const var & ); // Concatenate (join) another class var with this object.
      var& revCat( const var & ); // Concatenate this object with another object of class var.
      var& revCat( const char c ); // Concatenate this object with character in front.
      friend var cat( var & , const var & ); // Concatenate (join) two classes var.
      var& cat( const char ); // Concatenate (join) a character with this object.
      friend var cat( var & , const char );
      var& cat( const int );
      friend var cat( var & , const int );
      var& cat( const double );
      friend var cat( var & , const double );
      var& cat( const long );
      friend var cat( var & , const long );
      var split( const int , int skip = 0 ); // Split this object and return rest, skip over number of characters.
      var split( const var & , bool skip = false ); // Find text and split this object and return rest.
      var split( const char, int start = 0, int n = 0 );
      var split( char* &, const int , int skip = 0 );
      var& remstr( const int , int n = 1 ); // Remove text from object, n number of characters.
      friend var remstr( var & , const int , int n = 1 );
      friend var remstr( char* , const int , int n = 1 );
      var& substr( int , int stop = -1, char pad = ' ' ); // Remove without, stop at end, pad if needed.
      var& substrOf( var &v, int , int stop = -1, char pad = ' ' ) const; // Remove without, stop at end, pad if needed.
      var& between( const var& , const var&, const bool exact = false );
      var& revBetween( const var& , const var&, const bool exact = false );
      var& notBetween( const var& , const var&, const bool exact = false );
      var& subWord( int , int nr_words = -1, const char* delimiters = " " ); // Remove without, number of words, ( " " space is the delimiter ).
      var& lastWord( const char* delimiters = " " ); // Return last part (word), where " " space is the delimiter.
      bool containWord( const var& wrd, const char* delimiters = " ", const char additional = ' ', const bool exact = false );
      double trunc(); //remove and return number from text.
      var& cal( const var& , Calc calc = Add ); // Calculate (if number found) and/or perform action specified.
      var& calRight( const var& , Calc calc = Add ); // Calculate (if number found) and/or perform action specified.
      int boyerMooreSearch( const var & ) const; // Efficient algorithm to search for text with.
      int reverseBoyerMooreSearch( const var & ) const; // Not so efficient algorithm to search for text with.
      friend int boyerMooreSearch( var & , const var & );
      int bruteForceSearch( const char , int start = 0, bool exact = true ) const; // Find character within object.
      friend int bruteForceSearch( var & , const char , int start = 0, bool exact = true );
      int reverseBruteForceSearch( const char , int start = -1, bool exact = true ) const;
      friend int reverseBruteForceSearch( const var & , const char , int start = -1, bool exact = true );
      bool wordBeginsWith( const var&, const char* delimiters = " ", bool exact = true ) const; // Start character of all subwords;
      bool beginsWith( const var&, int start = 0, bool exact = true ) const; // Start with characters.
      bool isWithin( const var& , int start = 0, bool exact = true ) const; // Find characters of object within text.
      bool isWithin( const char* , int start = 0, bool exact = true ) const; // Find characters of object within string.
      int within( const var& , int start = 0, bool exact = true ) const; // Find characters within object.
      int within( const char* , int start = 0, bool exact = true ) const; // Find characters within object.
      int contains( const var& , int start = 0, bool exact = true, bool diff = true ) const; // Find characters within object.
      int contains( const char* , int start = 0, bool exact = true ) const; // Find characters within object.
      int contains( const char , int start = 0, bool exact = true ) const; // Find characters within object.
      int containsWord( const var& , const char delimiter = ' ', bool exact = true ) const; // Find word within object.
      bool onlyContains( const char, int start = 0, bool exact = true ) const; //Find out if character is the only one in string
      int reverseContains( var& , int start = -1, bool exact = true ) const; // Find character from end within object.
      int reverseContains( const char* , int start = 0, bool exact = true ) const; // Find character within object.
      var& left( int pos ); // Keep text left of position in object.
      var& middle( int length ); // Keep text in middle with number of characters in object.
      var& right( int pos ); // Keep text right of position in object.
      var& right( const var & ); // Keep text right of text in class var in object.
      var& leftOf( const var &, const bool exact = false, int startPos = 0 ); // Keep text left of text in class var in object.
      var splitTo( const int , int skip = 0 ); // Keep text after position in object, return beginning.
      var splitTo( const var & , bool skip = false );
      var splitTo( const char, int start = 0, int n = 0 );
      var& toLast( const char ); // Return up to delimiter.
      var& afterLast( const char ); // Return from delimiter.
      var& rightOf( const var &, const bool exact = false, int startPos = 0 ); // Keep text right of text in class var in object.
      var& addRightOf( const var & ); // Reverse concatenation (join).
      var word( int n, const char c = ' ' ) const; // return word delimited by character.
      var& removeText( const var & ); // Remove text from object.
      friend var& removeText( var & , const var & ); // Remove text from another object of class var.
      var& removeChar( const char ); // Remove first occurance of character from object.
      friend var& removeChar( var & , const char );
      var& removeByChar( const var & ); // Remove all occurances of character from object.
      var& translateChar( const char , const char ); // Replace character with another character in object.
      var& translateByChar( const var & , const var & ); // Replace all occurances of character in object.
      var& upper(); // Convert object to upper case.
      var& lower(); // Convert object to lower case.
      var& strip( const char c = ' ', Strip type = Both ); // Strip object ends from character.
      var& stripTrailing( const char c = ' ' ); // Strip object end from character.
      var& insert( var &, int , bool truncate = true ); // Insert text into object.
      var& offset( int ); //Move characters in variable x character steps in direction.
      bool isInteger() const; // Indicate if object contain only integer number(s).
      bool isInteger( const char* ) const; // Indicate if string contain only integer number(s).
      bool isNumeric() const; // Indicate if object contain only number(s).
      bool isNumeric( const char* ) const; // Indicate if string contain only number(s).
      bool isAlpha() const; //Indicate if object contain characters.
      bool isAlpha( const char* ) const; //Indicate if object contain characters.
      bool isBetween( const int, const int, const int ) const; //Indicate if the middle integer is within specified range.
      bool isBetween( const int, const int ) const; //Indicate if the integer representation is within specified range.
      bool isBetween( const char*, const char* ) const; //Indicate if the text representation is within specified range.
      char toChar() { return string[0]; } //return the first character of variable.
      char* toChars() { return string; } //return the variable.
      int toInt() { return atoi( string ); } //return the integer representation of variable.
      float toFloat() { return atof( string ); } //return the float representation of variable.
      ULONG toULong() { return strtoul( string, NULL, 10 ); }; //return the ulong representation of variable.

/* Operations to perform on the class */
      friend ostream& operator << ( ostream& out, const var& v ); // cout etc.
      friend istream& operator >> ( istream& in, const var& v ); // cin etc.
      friend var operator + ( const char* , const var& ); // Join and calculate addition
      friend var operator + ( const char , const var& );
      friend var operator + ( const int , const var& );
      friend var operator + ( const long , const var& );
      friend var operator + ( const double , const var& );
      friend var operator - ( const char* , const var& ); // Remove and calculate subtraction
      friend var operator - ( const char , const var& );
      friend var operator - ( const int , const var& );
      friend var operator - ( const long , const var& );
      friend var operator - ( const double , const var& );
      friend var operator * ( const int , const var& ); // Multiply
      friend var operator * ( const long , const var& );
      friend var operator * ( const double , const var& );
      friend var operator / ( const char* , const var& ); // Split and calculate division
      friend var operator / ( const char , const var& );
      friend var operator / ( const int , const var& );
      friend var operator / ( const long , const var& );
      friend var operator / ( const double , const var& );
      operator char*() { return string; }; // Automatically pretend/appear as char* if needed.
      operator int() { return atoi( string ); }; // Automatically pretend/appear as int if needed.
      operator long() { return atol( string ); }; // Automatically pretend/appear as long if needed.
      operator double() { return atof( string ); }; // Automatically pretend/appear as double if needed.
      operator unsigned long() { return strtoul( string, NULL, 10 ); }; // Automatically appear as ulong if needed.
      //operator bool() { return ( string[ 0 ] != '\0' ); }; // Automatically pretend/appear as bool if needed.
      var& operator = ( const char* ); // Copy.
      var& operator = ( const char );
      var& operator = ( const var& );
      var& operator = ( const int );
      var& operator = ( const long );
      var& operator = ( const double );
      bool operator < ( const char* ) const; // Smaller than (Comparison).
      bool operator < ( const char ) const;
      bool operator < ( const var& ) const;
      bool operator < ( const int ) const;
      bool operator < ( const long ) const;
      bool operator < ( const double ) const;
      bool operator > ( const char* ) const; // Larger than (Comparison).
      bool operator > ( const char ) const;
      bool operator > ( const var& ) const;
      bool operator > ( const int ) const;
      bool operator > ( const long ) const;
      bool operator > ( const double ) const;
      bool operator <= ( const char* ) const; // Smaller-Equal than (Comparison).
      bool operator <= ( const char ) const;
      bool operator <= ( const var& ) const;
      bool operator <= ( const int ) const;
      bool operator <= ( const long ) const;
      bool operator <= ( const double ) const;
      bool operator >= ( const char* ) const; // Larger-Equal than (Comparison).
      bool operator >= ( const char ) const;
      bool operator >= ( const var& ) const;
      bool operator >= ( const int ) const;
      bool operator >= ( const long ) const;
      bool operator >= ( const double ) const;
      bool operator == ( const char* ) const; // Equal to (Comparison).
      bool operator == ( const char ) const;
      bool operator == ( const var& ) const;
      bool operator == ( const int ) const;
      bool operator == ( const long ) const;
      bool operator == ( const double ) const;
      bool operator ^= ( const char* ) const; // Caseless (Comparison). (Nonstandard behaviour for ^=)
      bool operator ^= ( const char ) const;
      bool operator ^= ( const var& ) const;
      bool operator ^= ( const int ) const;
      bool operator ^= ( const long ) const;
      bool operator ^= ( const double ) const;
      bool operator != ( const char* ) const; // Not equal to (Comparison).
      bool operator != ( const char ) const;
      bool operator != ( const var& ) const;
      bool operator != ( const int ) const;
      bool operator != ( const long ) const;
      bool operator != ( const double ) const;
      var& operator += ( const char* ); // Add and summarize (Concatenation and calculation).
      var& operator += ( const char );
      var& operator += ( const var& );
      var& operator += ( const int );
      var& operator += ( const long );
      var& operator += ( const double );
      var& operator -= ( const char* ); // Remove and subtract from (Remove part of string and calculation).
      var& operator -= ( const char );
      var& operator -= ( const var& );
      var& operator -= ( const int );
      var& operator -= ( const long );
      var& operator -= ( const double );
      var& operator *= ( const int ); // Multiply with (Calculation).
      var& operator *= ( const long );
      var& operator *= ( const double );
      var& operator /= ( const char* ); // Split and devide (Split part of and calculation).
      var& operator /= ( const char );
      var& operator /= ( const var& );
      var& operator /= ( const int );
      var& operator /= ( const long );
      var& operator /= ( const double );
      var& operator ++ (); //Higher numeric value
      var& operator -- (); //Lower numeric value
      var operator + ( const char* ) const; // Add and summarize (Concatenation and calculation).
      var operator + ( const char ) const;
      var operator + ( const var& ) const;
      var operator + ( const int ) const;
      var operator + ( const long ) const;
      var operator + ( const double ) const;
      var operator - ( const char* ) const; // Remove and subtract (Remove and calculation).
      var operator - ( const char ) const;
      var operator - ( const var& ) const;
      var operator - ( const int ) const;
      var operator - ( const long ) const;
      var operator - ( const double ) const;
      var operator * ( const int ) const; // Multiply (Calculation).
      var operator * ( const long ) const;
      var operator * ( const double ) const;
      var operator / ( const char* ) const; // Split and devide (Split and calculation).
      var operator / ( const char ) const;
      var operator / ( const var& ) const;
      var operator / ( const int ) const;
      var operator / ( const long ) const;
      var operator / ( const double ) const;
      var& operator ++ ( int ); //Higher numeric value
      var& operator -- ( int ); //Lower numeric value
      char& operator [] ( const int ); // Access item in array specified by integer.
      var& at( const int );
};
#endif
