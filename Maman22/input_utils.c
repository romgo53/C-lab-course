
#include "input_utils.h"



extern complex A, B, C, D, E, F;

char *commands_list[NUM_FUNC] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real",
                                 "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};

void get_line(char line[]) {
    printf("Please enter a command:\n");

    /* If there's no line (not even line break character) the
     * program reached the end of the file before receiving stop command */
    if (fgets(line, LINE_LEN, stdin) == NULL) {
        printf("\nReached EOF before stop command\n");
        exit(0);
    }
}

void extract_data_from_input(char line[]) {
    int i;
    char *input;
    char *second_num;

    input = line;

    input = skip_spaces_and_tabs(input);

    if (input[0] == '\n') { /* check if the line is only with spaces */
        printf("(blank line)\n");
        return;
    }

    i = extract_command(input); /* we classify the command name */

    if (i == -1) {
        printf("Undefined command name\n");
        return;
    }

    input += strlen(commands_list[i]); /* We no longer need the command name */

    remove_spaces_and_tabs_from_input(input); /* In this part of the line we do not need spaces */

    if (input[0] == ',') {
        printf("Illegal comma\n");
        return;
    }


    if (i == STOP) {
        EXTRANEOUS_TEXT(input[0])
        stop(); /* we need to stop the program (the user entered "stop") */
    }

    /* In all the other functions the first variable is A,B,C,D,E,F : */

    MISSING_PARAMETER(input[0])

    if (!is_legal_complex_variable(input[0])) {
        printf("Undefined complex variable\n");
        return;
    }

    /* we now know that input[0] is a complex */

    if (i == ABS_COMP || i == PRINT_COMP) { /* need only one complex name */
        EXTRANEOUS_TEXT(input[1])
        if (i == ABS_COMP)
            abs_comp(identify_complex_var(input[0]));
        else
            print_comp(identify_complex_var(input[0]));

        return;
    }

    /* in all the commands we need a comma now: */
    MISSING_COMMA(input[1])

    if (i == ADD_COMP || i == SUB_COMP || i == MULT_COMP_COMP) { /* need 2 complex names (one more) */

        if (!is_legal_complex_variable(input[2])) {  /* There is an error, we will classify it: */
            MISSING_PARAMETER(input[2])

            MULTIPLE_CONSECUTIVE_COMMAS(input[2])

            printf("Undefined complex variable\n");
            return;
        }

        /* input[2] is the name of the second complex parameter */

        EXTRANEOUS_TEXT(input[3])

        /* All right! */

        if (i == ADD_COMP)
            add_comp(identify_complex_var(input[0]), identify_complex_var(input[2]));
        else if (i == SUB_COMP)
            sub_comp(identify_complex_var(input[0]), identify_complex_var(input[2]));
        else
            mult_comp_comp(identify_complex_var(input[0]), identify_complex_var(input[2]));

        return;
    }

    /* we now know that i is READ_COMP or MULT_COMP_REAL or MULT_COMP_IMG (so we need a first number for all of them:)*/

    if (!isdigit(input[2])) { /* the parameter may not be a number */
        MISSING_PARAMETER(input[2])

        MULTIPLE_CONSECUTIVE_COMMAS(input[2])

        if (input[2] != '-' || !isdigit(input[3])) { /* check for negative number */
            printf("Invalid parameter - not a number\n");
            return;
        }
    }

    /* we now know that there is a first number */

    if (i == READ_COMP) { /* we need one more comma and one more number */
        second_num = skip_number(input + 2);

        MISSING_COMMA(*second_num)

        second_num += 1; /* we want it on the first digit of the number */

        if (!isdigit(second_num[0])) { /* the parameter may not be a number */

            MISSING_PARAMETER(second_num[0])

            MULTIPLE_CONSECUTIVE_COMMAS(second_num[0])

            if (second_num[0] != '-' || !isdigit(second_num[1])) { /* check for negative number */
                printf("Invalid parameter - not a number\n");
                return;
            }

        }
        /* we now know that there are 2 numbers in the line */

        EXTRANEOUS_TEXT(*skip_number(second_num)) /* check for extraneous text after the second number */

        /* All right! */
        read_comp(identify_complex_var(input[0]), atof(input + 2), atof(second_num));
        return;
    }

    EXTRANEOUS_TEXT(*skip_number(input + 2))

    /* All right! */
    if (i == MULT_COMP_REAL)
        mult_comp_real(identify_complex_var(input[0]), atof(input + 2));
    else /* i = MULT_COMP_IMG */
        mult_comp_img(identify_complex_var(input[0]), atof(input + 2));

}

void stop() {
    printf("The program has stopped!\n"); 
    exit(0);
}

int extract_command(char *input) {
    int i;
    char tmp[LINE_LEN];
    char command[COMMAND_SIZE];
    /* remove white chars from command*/
    strcpy(tmp, input);
    strcpy(command, strtok(tmp, " \t\n"));

    for (i = 0; i < NUM_FUNC; i++) {
        if (strcmp(command, commands_list[i]) == 0){
            return i;
        }
    }
    return -1; /* In case of unknown command name*/

}

char *skip_spaces_and_tabs(char *input) {
    int n;
    for (n = 0; input[n] != 0 && (input[n] == ' ' || input[n] == '\t'); n++) {}
    return input + n;
}


complex *identify_complex_var(char complex_char) {
    /* Returns the pointer to the identified number*/
    switch (complex_char){
        case 'A':
            return &A;
        case 'B':
            return &B;
        case 'C':
            return &C;
        case 'D':
            return &D;
        case 'E':
            return &E;
        case 'F':
            return &F;
        default:
            return NULL;
    }
}

int is_legal_complex_variable(char complex_char) {
    return complex_char >= 'A' && complex_char <= 'F'; /* complex name in only A,B,C,D,E,F */
}


/* Function to remove all spaces from a given string */
void remove_spaces_and_tabs_from_input(char *input) {
    int i;
    /* To keep track of non-space character count */
    int count = 0;

    /* Traverse the given string. If current character
     is not space, then place it at index 'count++' */
    for (i = 0; input[i]; i++) {
        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
            input[count++] = input[i]; /* here count is incremented */
    }

    input[count] = '\0'; /* finish the string */
}

char *skip_number(char *input) {
    int i = 0;
    int hadDot = 0;

    if (input[0] == '-')
        i++; /* skip the - sign at the beginning of the number (if there is one) */

    for (; isdigit(input[i]) || input[i] == '.'; i++) {
        if (input[i] == '.') {
            if (hadDot || !isdigit(input[i + 1])) /* the dot is the end of the number */
                return input + i;
            hadDot = 1; /* only one dot is allowed in the number */
        }
    }
    return input + i; /* return a pointer to the char after the number */

}

