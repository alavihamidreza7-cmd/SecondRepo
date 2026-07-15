#include<stdio.h>
int main(void){
    printf("Wellcome to\a C Programming");
    printf("\a Wellcom to C Programming");
    char name[20];
    printf("\n");
    scanf("%19[^\n]",name);
    printf("\n%19s",name);
}