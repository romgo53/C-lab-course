#include <stdio.h>
#include <stdlib.h>
#define ENLARGE_SET 4
int* get_set(int *arr_len);
void print_set(int* set, int arr_len);

int main() {
    // The size of the array
    int arr_len=0;
    int* set;
    set = get_set(&arr_len);
    print_set(set, arr_len);
    free(set);
    return 0;
}

// Checks if the input from the user is valid for the set
int check_input(int* set, int input, int arr_len){
    int i;
    for(i=0; i < arr_len; i++){
        if(set[i] == input)
            return 0;
    }
    return 1;
}

//prints the created set, doesn't need to return anything
void print_set(int* set, int arr_len){
    int i;
    printf("\nThe final set: \n");
    for(i=0; i < arr_len; i++){
        printf("%3d", set[i]);
    }
    puts("\n");
}

// returns the set therefore int* func is declared
int* get_set(int* arr_len){
    printf("Enter numbers that you want to add to the set to finish use CTRL-D \n");
    int* set = malloc(ENLARGE_SET);
    int input;
    while(scanf("%d", &input) != EOF){
        if(check_input(set, input, *arr_len)){
            *arr_len+=1;
            set = realloc(set, *arr_len*ENLARGE_SET);
            set[*arr_len - 1] = input;
        }
    }

    return set;
}


