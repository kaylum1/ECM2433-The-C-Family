#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msString.h"


msString msSetString (char *inputNewString) {
     /*allocate the memory*/
    msString outputString = (msString)malloc(strlen(inputNewString) + 1); /*replaced outputString with inputNewString*/
    /*check if the memory was allocated correctly*/
    if (outputString == NULL){
        printf("error allocating memory to msSetString");
        fprintf(stderr, "Error allocating memory to msSetString\n");
        msError("Error allocating memory to msSetString");
        free(outputString);
        return NULL;
        /*return inputNewString;*/

    }
    strcpy(outputString, inputNewString);
    /*printf("successful step 1: %s", inputNewString); */

    return outputString;
    free(outputString);
}




/*This function, msGetString, is designed to convert an msString to a standard C string 
 * (null-terminated character array).*/
char *msGetString (msString inputGetString) {
    char * outputGetString = (char *)malloc(strlen(inputGetString) +  1);

    if (outputGetString == NULL){
        printf("error allocating memory to msGetString");
        fprintf(stderr, "error allocating memory to msGetString\n");
        msError("Error allocating memory to msGetString");
        free(outputGetString);
        return NULL;
    }
    strcpy(outputGetString, inputGetString);
    /*printf("successful step  2: %s", outputGetString);*/

    return outputGetString;
    free(outputGetString);

}

/*This function, msCopy, is designed to copy the contents of 
 one msString (the SourceOfCopy) to another msString*/
void msCopy (msString * destinationOfCopy, msString SourceOfCopy){
    *destinationOfCopy = (msString)malloc(strlen(SourceOfCopy)+1);

    if (*destinationOfCopy == NULL){
      printf("error allocating memory to msCopy");
     fprintf(stderr, "error allocating memory to msCopy");
      msError("Error allocating memory to msCopy");
     free(*destinationOfCopy);
        return;

    }
    strcpy(*destinationOfCopy, SourceOfCopy);

    return;
    free(*destinationOfCopy);  /*uncomment thisagain  if there is an error in task 3 or try in differnt location*/

}


void msConcatenate (msString* startOfString, msString endOfString){
    /*thee start pointer points to a valid null-terminated string.
 *     Sufficient memory is allocated for start to hold the concatenated result.   */
    strcat(*startOfString, endOfString);
}


/*This function, msLength, calculates the length of an 
 * msString and returns the result as an intege*/
int msLength (msString count){
    int countString = strlen(count);
    return countString;
}

int msCompare (msString string1, msString string2){
    if (strcmp(string1, string2) == 0){
        return 0;
    } else {
        return 1;
    }
}

int msCompareString (msString string1, char * string2){

    if (strcmp(string1, string2) == 0){
        return 0;
    } else {
        return 1;
    }
}

static void msError (char * ouputError){
    fprintf(stderr, "this is the error message %s", ouputError);
    exit(EXIT_FAILURE);
}

