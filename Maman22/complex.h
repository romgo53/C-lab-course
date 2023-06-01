
#include <stdio.h>
#include <math.h>

/* the complex number struct */
typedef struct complex {
    double real;
    double img;
} complex;

void read_comp(complex* a, double real, double image);

void print_comp(complex *a);

/*Receives two complex numbers as parameters, sums them and prints the result*/
void add_comp(complex* a, complex* b);

/*Receives two complex numbers as parameters, subtracts them and prints the result*/
void sub_comp(complex *a, complex *b);

/* Calculates the multiplication of a complex number and a real number received as parameters and prints the result*/
void mult_comp_real(complex *a, double num);

/* Calculates the multiplication of a complex number and an imaginary number received as parameters 1and prints the result*/
void mult_comp_img(complex *a, double img);

/* Calculates the multiplication of two complex numbers received as parameters and prints the result*/
void mult_comp_comp(complex *a, complex *b);

/* Calculates the absolute value of the complex number received as a parameter and prints it */
void abs_comp(complex *a);

