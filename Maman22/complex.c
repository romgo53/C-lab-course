
#include "complex.h"

void read_comp(complex *a, double real, double image) {
    a->real = real;
    a->img = image;
}


void print_comp(complex *a) {
    printf("%.2f", a->real);
    if (a->img >= 0)
        printf(" + (%.2f)i\n", a->img);
    else
        printf(" - (%.2f)i\n", -a->img);

}


void add_comp(complex *a, complex *b) {
    complex tmp;

    tmp.real = a->real + b->real;
    tmp.img = a->img + b->img;

    print_comp(&tmp);

}


void sub_comp(complex *a, complex *b) {
    complex tmp;

    tmp.real = a->real - b->real;
    tmp.img = a->img - b->img;

    print_comp(&tmp);

}


void mult_comp_real(complex *a, double num) {
    complex tmp;

    tmp.real = a->real * num;
    tmp.img = a->img * num;

    print_comp(&tmp);
}


void mult_comp_img(complex *a, double img) {
    complex tmp;

    tmp.real = -img * (a->img);
    tmp.img = img * a->real;

    print_comp(&tmp);
}


void mult_comp_comp(complex *a, complex *b) {
    complex tmp;

    tmp.real = (a->real * b->real) - (a->img * b->img);
    tmp.img = (a->real * b->img) + (a->img * b->real);

    print_comp(&tmp);
}


void abs_comp(complex *a) {
    printf("%f\n", sqrt(a->real * a->real + a->img * a->img));
}
