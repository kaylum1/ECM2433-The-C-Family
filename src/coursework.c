#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "msString.h" 

/*TASK 1 pre work*/
void printBytes(void *ptr, int numBytes) {
    unsigned char *bytePtr = (unsigned char *)ptr; /* Treat ptr as pointer to unsigned char*/
    int i;
    printf("Bytes at address %p:\n", ptr);
    for (i = 0; i < numBytes; i++) {

        printf("00%d : %u \n", i, bytePtr[i]); /* Print the decimal value of each byte*/
    }
    printf("\n");
}


/*TASK 2 pre work*/
/*exmaple of revewse a string function*/
void reverseString(char *str) {
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
void addTxt(char *file) {
    size_t len = strlen(file);
    if (len <  4 || strcmp(&file[len -  4], ".txt") !=  0) {
        strcat(file, ".txt");
    }
}


int main(int  argc, char  **argv ) {
/*TASK1*/
    printf("this is the start of task 1\n");
    /*test code #1 to check if task 1 works*/
    printf("test 1\n");
    int x = 10;
    printBytes(&x, sizeof(x)); /* Print the bytes of x*/

    /*test #2*/
    printf("test 2\n");
    char str[] = "Hello23";
    printBytes(str, sizeof(str)); /* Print the bytes of str */
    printf("end of task 1\n");
    /*return 0;*/

    printf("\n");

/* TASK2*/
   /* Check if the correct number of arguments are provided */
    if (argc != 3) {
        printf("Usage: %s fileIn fileOut\n", argv[0]);
        return 1;
    }

    /*Allocate memory for inputFilename and outputFilename*/
    char *inputFile = malloc(strlen(argv[1]) +  5); /* +5 for ".txt\0"*/
    char *outputFile = malloc(strlen(argv[2]) +  5); /* +5 for ".txt\0"*/

    if (!inputFile || !outputFile) {
        fprintf(stderr, "Failed to allocate memory for filenames.\n");
        exit(EXIT_FAILURE);
    }

    /* Copy argv[1] and argv[2] to inputFile outputFile*/
    strcpy(inputFile, argv[1]);
    strcpy(outputFile, argv[2]);

    /* Add .txt extension if necessary*/
    addTxt(inputFile);
    addTxt(outputFile);

   /*code to open the file for reading*/
    FILE *fp;
    char *buffer = NULL;
    size_t bufferSize =  0;
    size_t charsRead =  0;
    char  ch;
    if ((fp = fopen(inputFile, "r")) == NULL) {
        printf("Unable to open file for read access.\n");
    
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(1);
    }
    /*this code print out what is in the input file*/
    while (!feof(fp)) {
        ch = fgetc(fp);
        /*printf("%3d: %c\n",ch,ch);*/
        /*new code*/
        if (charsRead >= bufferSize) {
            /* Double the buffer size or allocate a larger initial size if needed*/
            bufferSize = charsRead +  1024;
            buffer = realloc(buffer, bufferSize);
            if (buffer == NULL) {
                /* Handle allocation failure*/
                fprintf(stderr, "Failed to allocate memory for buffer.\n");
                exit(EXIT_FAILURE);
            }
        }
        buffer[charsRead++] = ch;
    }
    
    if (charsRead >  0) {
        charsRead--;
    }
    /*Null-terminate the string*/
    buffer[charsRead] = '\0';
    fclose(fp);
    /*revrese string code*/
    printf("Original string: %s\n", buffer);
    reverseString(buffer);
    printf("Reversed string: %s\n", buffer);
    printf("\n");
    /*writes to an output file*/
    /* Open a file for writing (creates the file if it doesn't exist)*/
    fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1; /* Return an error code*/
    }
    /*Write formatted output to the file*/
    fprintf(fp, "the printed revserse message: %s\n", buffer);
    /* Close the file*/
    fclose(fp);
    printf("Data written to file.\n");
    /*new code*/
    /* Free the allocated memory*/
    free(buffer);

    free(inputFile);
    free(outputFile);
    /* return EXIT_SUCCESS;*/
    printf("\n");
    printf("this is the end of task 2\n");
    /*return 0;*/

    printf("\n");


/* TASK3*/
    printf("this is the start of task 3\n");
    printf("\n");
    msString ms = msSetString("Hello");
    msString ms2 = msSetString (" World!");
    msString mscopy = NULL;


    printf("String |%s| is %d characters long (%p).\n", msGetString(ms),msLength(ms),ms);
    msCopy(&mscopy,ms);
    /*printf("Copied string |%s| is %d characters long (%p).\n", msGetString(mscopy),msLength(mscopy),mscopy);*/

    /*this is where i address the memory leak */
    char *msCopyStr = msGetString(mscopy);
    printf("Copied string |%s| is %d characters long (%p).\n", msCopyStr, msLength(mscopy), mscopy);
    free(msCopyStr); /* Free the memory allocated by msGetString*/

    printf("\n");
    printf("this is a test the value of ms: |%s|\n", msGetString(ms));
    printf("this is a test the value of msCopy: |%s|\n", msGetString(mscopy));
    printf("this is a test the value of ms2: |%s|\n", msGetString(ms2));
    printf("\n");


    printf("Compare ms with mscopy: %d\n",msCompare(ms,mscopy));        /*0*/
    printf("Compare ms with ms2 : %d\n",msCompare(ms,ms2));             /*1*/
    printf("Compare ms with Hello : %d\n",msCompareString(ms,"Hello")); /*0*/
    printf("Compare ms with HelloX: %d\n",msCompareString(ms,"HelloX"));/*1*/
    printf("Compare ms with Hella : %d\n",msCompareString(ms,"Hella")); /*1*/

    msConcatenate(&mscopy,ms2);
    printf("Concatenated string |%s| is %d characters long (%p).\n", msGetString(mscopy),msLength(mscopy),mscopy);


    printf("this is the end of task 3\n");

    printf("\n");


}
