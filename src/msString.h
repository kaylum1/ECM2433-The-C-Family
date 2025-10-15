#ifndef __MSSTRING__
#define __MSSTRING__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void * msString;

extern msString  msSetString     (char *);
/*accepts a standard C string as an input and returns a new msString.*/
extern char     *msGetString     (msString);
/*accepts an msString as an input and returns a standard C string.*/
extern void      msCopy          (msString *, msString);
/*accepts two inputs, a pointer to an msString (the destination) and an msString (the source), and copies the source value to the destination.*/
extern void      msConcatenate   (msString *, msString);
 /*accepts two inputs, a pointer to an msString (the destination) and an msString (the source), and concatenates the source value onto the end of the destination.*/
extern int       msLength        (msString);
/*accepts an msString as an input and returns an integer value that is the number of characters in the string.*/
extern int       msCompare       (msString, msString); /*accepts two msString values as inputs and returns 0 (zero) if they are identical, or 1 if they are not.*/
extern int       msCompareString (msString, char *); /*accepts an msString value and a standard C string value as inputs and returns 0 (zero) if the characters making up the strings are the same, or 1 if they are not.*/
static void      msError         (char *); /*accepts a standard C string as input, outputs it as an error message to the user and then exits the program. This function can be called by any of the other msString functions when an error occurs.*/

#endif