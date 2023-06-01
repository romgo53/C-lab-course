
/* A program that receives commands about complex numbers from the user and executes them.
 * author: Rom Waidergoren */

#include "input_utils.h"

/* Initializing with the default values (real->0, img->0) */
void initialize();

/* A function that performs the entire process of the program and the user interaction (of course using other functions) */
void program_process(char line[]);

/* Print the menu once:*/
void show_menu();

complex A, B, C, D, E, F;

int main() {
    char input[LINE_LEN];
    initialize(); /* Initialize the complex variables to a value of 0 + 0i */
    show_menu();
    while (1) { /* Loops until stop command/EOF */
        get_line(input);
        extract_data_from_input(input);
    }
    return 0;
}


void initialize() {
    read_comp(&A, 0, 0);
    read_comp(&B, 0, 0);
    read_comp(&C, 0, 0);
    read_comp(&D, 0, 0);
    read_comp(&E, 0, 0);
    read_comp(&F, 0, 0);
}

void show_menu(){
    printf("1. read_comp <COMP>,<REAL>,<IMG>\n");
    printf("2. print_comp <COMP>\n");
    printf("3. add_comp <COMP_1>,<COMP_2>\n");
    printf("4. sub_comp <COMP_1>,<COMP_2>\n");
    printf("5. mult_comp_real <COMP>,<REAL>\n");
    printf("6. mult_comp_img <COMP>,<IMG>\n");
    printf("7. mult_comp_comp <COMP_1>,<COMP_2>\n");
    printf("8. abs_comp <COMP>\n");
    printf("9. stop\n");
}

void program_process(char line[]) {

}

