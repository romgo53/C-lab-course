#include <stdio.h>
#include <string.h>
#define SIZE 80

/* 
   name: Rom Waidergoren
   date: 01/04/2023
 */

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, unsigned int n);

int my_strchr(char *str, char chr);

int main() {
    char s1[SIZE];
    char s2[SIZE];
    char chr;
    int n;

    printf("Enter a char to search in the first string: \n");
    scanf("%chr", &chr);
    printf("Enter the first String: \n");
    scanf("%s", s1);
    printf("Enter the second String: \n");
    scanf("%s", s2);
    printf("Enter the number of chars in the strings you want to compare (strncmp): \n");
    scanf("%d", &n);

    printf("First string \"%s\"\n", s1);
    printf("Second string \"%s\"\n", s2);
    printf("Entered char %c\n", chr);
    printf("Entered n %d\n", n);
    printf("The result of compering \"%s\" and \"%s\" is: %d\n",s1, s2, my_strcmp(s1, s2));
    printf("The result of compering the first %d chars of \"%s\" and \"%s\" is: %d\n",n+1, s1, s2, my_strncmp(s1, s2, n));
    printf("The index of the first occurrence of '%c' is %d", chr, my_strchr(s1, chr));
    return 0;
}

// Compares string s1 to string s2
// Returns <0 if s1 < s2, >0 if s1 > s2 and 0 if s1 == s2
int my_strcmp(char *s1, char *s2) {
    int i;
    for (i = 0; s1[i] && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}

// Compares at most n characters of string s1 to string s2
// Returns <0 if s1 < s2, >0 if s1 > s2 and 0 if s1 == s2
int my_strncmp(char *s1, char *s2, unsigned int n) {
    int i;
    for (i = 0; s1[i] == s2[i] && i < n; i++);
    return s1[i] - s2[i];
}

// Returns the index of the first occurrence of chr in str
// If the chr does not exist in str returns -1
int my_strchr(char *str, char chr) {
    int i;
    for (i = 0; str[i]!='\0' && str[i] != chr; i++);
    return (str[i] == chr) ? i : -1;
}

