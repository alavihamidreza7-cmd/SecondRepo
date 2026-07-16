#include<stdio.h>
#include<string.h>
#define SIZE 8
#define SIZE_2 98
int main(void){
  //  printf("Hello World\n");
    char Array_String_1[]="Hello World";
    char Array_String_2[20];
    //scanf("%19s",Array_String_2);
   // printf("\n %s      %s",Array_String_1,Array_String_2);
  int Array[]={12,25,65,98,123,123,123,456,789,1234,56987};
  //Search above array(Array) for detecting a special Value with binary search
  int special=0;
  puts("Please enter a value for exploring: ");
  scanf("%d",&special);
  int high=10,low=0;
  while(low<=high){
    int midle=(high+low)/2;
    if(Array[midle]==special){
      printf("Desired value founded in %dth Index.",midle);
      return 0;
    }
    else if(special>Array[midle]){
      low=midle+1;
    }
    else{
      high=midle-1;
    }
  }
  puts("Desired Value not founded.");



}