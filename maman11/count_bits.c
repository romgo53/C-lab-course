#include <stdio.h>
#define MASK 1

/* 
   name: Rom Waidergoren
   date: 01/04/2023
 */
int count_bits(unsigned long num);

int main(){
    unsigned long num;
    printf("Enter a number number for count_bits function:\n");
    scanf("%lo", &num);
    printf("Counting the bits on even indexes for %lo...", num);
    printf("\nThe result is: %d", count_bits(num));
    return 0;
}

// Counts the even index bits in a given long and returns the result
int count_bits(unsigned long num){
    int count=0,i;
    // Each iteration MASK is used to check the even indexes of num
    for(i=0;num>>i!=0;i=i+2){
        if(num & (MASK << i)) count++;
    }
    return count;
}

