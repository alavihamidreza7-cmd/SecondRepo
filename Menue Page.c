#include<stdio.h>
#include<conio.h>

#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int x_head=3,y_head=3,x_tail=2,y_tail=3;
int main(){
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    system("cls");
    int x,q;
    x=0+(rand()%50);
    q=0+(rand()%25);
    for(int i=1;i<=25;++i){
        if(i==1 || i==25){
            for(int j=1;j<=49;++j){
                printf("█");
            }
            printf("\n");
            continue;
        }
        
        printf("█");
        /*if(i==13){
            for(int y=1;y<=10;++y){
                printf("█");
            }
            for(int p=1;p<=27;++p){
                printf(" ");
            }
            for(int y=1;y<=10;++y){
                printf("█");
            }
            printf("█");
            printf("\n");
            continue;
        }*/
        for(int k=1;k<=47;++k){
            printf(" ");

        }
        printf("█");
        printf("\n");
    }
    gotoxy(x_head,y_head);
    printf("♥♥");
    gotoxy(x_tail,y_tail);
    printf("●");
    gotoxy(x,q);
    printf("▲"); 
    gotoxy(1,27);
    


/*
    wint_t key;
    while(1){
        
        
        Sleep(1000);
        printf("Hi");
        if(kbhit()!=0){
            key=_getwch();
            printf("goodby");
            printf("%lc",key);
            printf("%d",key);
            
        }
    }
    */
   /*
            if(kbhit()!=0){
            direct=_getwch();
            if(direct=='e'){
                printf("e");
            }
            while(1){
                Sleep(10);
                printf("ok");
                if(kbhit()!=0){
                    break;
                }
            }
        }
        Sleep(10);
        printf("hi");
    */
    
    
    

}