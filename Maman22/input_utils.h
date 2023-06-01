
#include "complex.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h> /* for atof */

#define LINE_LEN 100
#define COMMAND_SIZE 30
#define NUM_FUNC 9

/* Macros for common errors */

#define EXTRANEOUS_TEXT(ch) \
    if (ch) {\
        printf("Extraneous text after end of command\n");\
        return;\
    }

#define MISSING_PARAMETER(ch) \
    if (!ch) {\
        printf("Missing parameter\n");\
        return;\
    }

#define MISSING_COMMA(ch) \
    if (ch != ',') {\
        printf("Missing comma\n");\
        return;\
    }

#define MULTIPLE_CONSECUTIVE_COMMAS(ch) \
    if (ch == ',') {\
        printf("Multiple consecutive commas\n");\
        return;\
    }

/* numbers to identify the command names */
enum names {
    READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP, STOP
};

/* A function that get into line the user inserted, and prints it */
void get_line(char line[]);

/* A function that receives an input line and handle it (does the command or prints an error) */
void extract_data_from_input(char line[]);

/* A function that prints a goodbye message to the user and exits the program */
void stop();

/* A function that gets a pointer to the beginning of the first word in a command and returns a
 * number representing the command (or -1 if the first word is not a command) */
int extract_command(char *input);

/* A function that receives a string and returns a pointer to the first non-white character in the string */
char *skip_spaces_and_tabs(char *input);

/* A function that accepts one of the characters A, B, C, D, E, F and
 * returns a pointer to the complex number with the same name as the char */
complex *identify_complex_var(char complex_char);

/* A function that receives a character and checks whether he is a name of a complex number (A,B,C,D,E,F) */
int is_legal_complex_variable(char complex_char);

/* A function that receives a string and removes the white characters from it */
void remove_spaces_and_tabs_from_input(char *input);

/*A function that accepts a char pointer (to the beginning of a number) and returns a pointer to the end of the number */
char *skip_number(char *input);






