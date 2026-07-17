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
void Map(){
    for(int i=1;i<=30;++i){
        gotoxy(50,i);
        if(i==1 || i==30){
            for(int j=1;j<=60;++j){
                printf("█");
            }
            printf("\n");
            continue;
        }
        
        
        printf("█");
        
        for(int k=1;k<=58;++k){
            printf(" ");

        }
        printf("█");
        printf("\n");
    }
    Sleep(1000);
    int x=50,y=15;
    for(int i=1;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        ++x;
    }
    Sleep(1000);
    x=109,y=15;
    for(int i=1;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        --x;
    }
    Sleep(1000);
    x=80,y=1;
    for(int i=0;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        ++y;
    }
    Sleep(1000);
    x=80,y=30;
    for(int i=1;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        --y;
    }

}
int main(){
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    system("cls");
    Map();

}