#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BG_BLACK 0
#define BG_BLUE (BLUE << 4)
#define BG_GREEN (GREEN << 4)
#define BG_CYAN (CYAN << 4)
#define BG_RED (RED << 4)
#define BG_MAGENTA (MAGENTA << 4)
#define BG_BROWN (BROWN << 4)
#define BG_LIGHTGRAY (LIGHTGRAY << 4)
#define COLOR_DEFAULT (WHITE | BG_BLACK)
#define COLOR_ERROR (WHITE | BG_RED)
#define COLOR_SUCCESS (BLACK | BG_GREEN)
#define COLOR_WARNING (BLACK | BG_YELLOW)
#define COLOR_INFO (BLACK | BG_CYAN)
#define COLOR_MENU (YELLOW | BG_BLUE)
#define COLOR_HIGHLIGHT (BLACK | BG_WHITE)
#define ATTR_DEFAULT 7 
#define ATTR_RED_TEXT 12  
#define ATTR_GREEN_TEXT 10  
#define ATTR_BLUE_TEXT 9   
#define ATTR_YELLOW_TEXT 14 
#define ATTR_RED_BG 64     
#define ATTR_GREEN_BG 32   
#define ATTR_BLUE_BG 16    
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void resetColor() {
    setColor(COLOR_DEFAULT);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Map22(){
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
int main(void){
    
    while(1){
        int scores[100];
        int score=0;
        int Tail[1250][2]={{56,2},{57,2}};
        int i=0,x_tail,y_tail,x_head=58,y_head=2,x,y;
        srand(time(NULL));
        SetConsoleOutputCP(65001);
        system("cls");
        Map22();
        Sleep(1000);
        gotoxy(56,2);
        printf("●");
        Sleep(1000);
        gotoxy(57,2);
        printf("●");
        Sleep(1000);
        gotoxy(58,2);
        printf("▶");
        Sleep(1000);
        int collide=0;
        int o=1;
        int Pointeer=0;
        int flag=0;
        int length=1;
        int movement=0;
        wint_t direct='d';
        while(1){
            ++movement;
            if(movement==10){
                x=51+(rand()%59);
                y=1+(rand()%29);
                flag=1;
            }
            if(flag==0){
                x=51+(rand()%59);
                y=1+(rand()%29);
            }
            for(int j=0;j<=length;++j){
                if((x==Tail[j][0] && y==Tail[j][1])){
                    Pointeer=1;
                }
                if(x_head==Tail[j][0] && y_head==Tail[j][1]){
                    collide=1;
                }

            }
            if(x==51 || x==108 || y==1 || y==28 || Pointeer==1){
                Pointeer=0;
                --movement;
                continue;
            }
            if((y==15 && (x<=60 && x>=50 )) || (y==15 && (x<=109 && x>=99))||(x==80 && (y<=10 &&y>=1))|| (x==80 &&(y<=30 && y>=20))){
                --movement;
                continue;

            }
            if(x_head==50 || x_head==110 || y_head==0 || y_head==30 || Pointeer==1){
                printf("GGGGAMMME OVERdsss");
                break;
            }
            if((y_head==15 && (x_head<=60 && x_head>=50 )) || (y_head==15 && (x_head<=109 && x_head>=99)) || (x_head==80 && (y_head<=10 &&y_head>=1)) || (x_head==80 &&(y_head<=30 && y_head>=20))){
                collide=1;
            }
            if(collide==1){
                printf("GGGGAAAAAAAME OVER");
                break;
            }
            if(flag==0 && o<6){
                gotoxy(x,y);
                setColor(RED);
                printf("●");
                resetColor();
                ++o;
                flag=1;
            }
            if(flag==0 && o==6){
                gotoxy(x,y);
                setColor(GREEN);
                printf("●");
                resetColor();
                o=0;
                flag=1;
            }
            if(movement==10){
                gotoxy(x,y);
                setColor(WHITE);
                printf("●");
                resetColor();
            }
            if(movement==15){
                gotoxy(x+1,y);
                printf("\b \b");
                movement=0;
                flag=0;
            }

            if(x_head==x && y_head==y){
                ++score;
                movement=0;
                Tail[length+1][0]=x;
                Tail[length+1][1]=y;
                flag=0;
                ++length;
                if(direct=='d'){
                    gotoxy(x_head+1,y_head);
                    printf("\b \b");
                    Sleep(10);
                    printf("▶");
                    Sleep(10);
                    gotoxy(x_head,y_head);
                    printf("●");
                    ++x_head;
                    }
                if(direct=='s'){
                    gotoxy(x_head+1,y_head);
                    printf("\b \b");
                    Sleep(10);
                    printf("▼");
                    Sleep(10);
                    gotoxy(x_head,y_head);
                    printf("●");
                    ++y_head;
                    }
                if(direct=='w'){
                    gotoxy(x_head+1,y_head);
                    printf("\b \b");
                    Sleep(10);
                    printf("▲");
                    Sleep(10);
                    gotoxy(x_head,y_head);
                    printf("●");
                    --y_head;
                    }
                if(direct=='a'){
                    gotoxy(x_head+1,y_head);
                    printf("\b \b");
                    Sleep(10);
                    printf("◀");
                    Sleep(10);
                    gotoxy(x_head,y_head);
                    printf("●");
                    --x_head;

                    }
                    if(o==6){
                        ++length;
                        for(int k=0;k<=0;++k){
                            if(direct=='d'){
                                gotoxy(x_head+1,y_head);
                                printf("\b \b");
                                Sleep(10);
                                printf("▶");
                                Sleep(10);
                                gotoxy(x_head,y_head);
                                printf("●");
                                Tail[length][0]=x_head;
                                Tail[length][1]=y_head;
                                ++x_head;
                            }
                            if(direct=='s'){
                                gotoxy(x_head+1,y_head);
                                printf("\b \b");
                                Sleep(10);
                                printf("▼");
                                Sleep(10);
                                gotoxy(x_head,y_head);
                                printf("●");
                                Tail[length][0]=x_head;
                                Tail[length][1]=y_head;
                                ++y_head;
                            }
                            if(direct=='w'){
                                gotoxy(x_head+1,y_head);
                                printf("\b \b");
                                Sleep(10);
                                printf("▲");
                                Sleep(10);
                                gotoxy(x_head,y_head);
                                printf("●");
                                Tail[length][0]=x_head;
                                Tail[length][1]=y_head;
                                --y_head;
                            }
                            if(direct=='a'){
                                gotoxy(x_head+1,y_head);
                                printf("\b \b");
                                Sleep(10);
                                printf("◀");
                                Sleep(10);
                                gotoxy(x_head,y_head);
                                printf("●");
                                Tail[length][0]=x_head;
                                Tail[length][1]=y_head;
                                --x_head;

                            }

                        }
                }
                continue;
            }
            if(direct=='d'){
                if(kbhit()!=0){
                    direct=_getwch();
                }
                gotoxy(x_head+1,y_head);
                Sleep(10);
                printf("\b \b");
                Sleep(10);
                printf("▶");
                
                gotoxy(x_head+1,y_head);
                printf("\b \b");
                    
                gotoxy(x_head+1,y_head);
                printf("▶");
                Sleep(10);
                    
                    
                x_tail=Tail[i][0];
                y_tail=Tail[i][1];
                gotoxy(x_tail+1,y_tail);
                printf("\b \b");
                Sleep(10);
                gotoxy(x_head,y_head);
                printf("●");
                Sleep(10);
                    
                Tail[i][0]=x_head;
                Tail[i][1]=y_head;
                ++x_head;
                    
                if(i==length){
                    i=0;
                    continue;
                }
                ++i;
                Sleep(10);
                
                
            }
            if(direct=='s'){
                if(kbhit()!=0){
                    direct=_getwch();
                }
                gotoxy(x_head+1,y_head);
                printf("\b \b");
                Sleep(10);
                printf("▼");
                Sleep(10);
                gotoxy(x_head+1,y_head);
                printf("\b \b");
                    
                gotoxy(x_head,y_head+1);
                printf("▼");
                Sleep(10);
                    
                    
                x_tail=Tail[i][0];
                y_tail=Tail[i][1];
                gotoxy(x_tail+1,y_tail);
                printf("\b \b");
                Sleep(10);
                gotoxy(x_head,y_head);
                printf("●");
                Sleep(10);
                    
                Tail[i][0]=x_head;
                Tail[i][1]=y_head;
                ++y_head;
                    
                if(i==length){
                    i=0;
                    continue;
                    
                }
                ++i;
                Sleep(10);

                
                

            }
            if(direct=='w'){
                if(kbhit()!=0){
                    direct=_getwch();
                }
                gotoxy(x_head+1,y_head);
                printf("\b \b");
                Sleep(10);
                printf("▲");
                Sleep(10);
                gotoxy(x_head+1,y_head);
                printf("\b \b");
                    
                gotoxy(x_head,y_head-1);
                printf("▲");
                Sleep(10);
                    
                    
                x_tail=Tail[i][0];
                y_tail=Tail[i][1];
                gotoxy(x_tail+1,y_tail);
                printf("\b \b");
                Sleep(10);
                gotoxy(x_head,y_head);
                printf("●");
                Sleep(10);
                    
                Tail[i][0]=x_head;
                Tail[i][1]=y_head;
                --y_head;
                    
                if(i==length){
                    i=0;
                    continue;
                    
                }
                ++i;
                Sleep(10);
                }
                if(direct=='a'){
                    if(kbhit()!=0){
                        direct=_getwch();
                    }
                    gotoxy(x_head+1,y_head);
                    printf("\b \b");
                    Sleep(10);
                    printf("◀");
                    Sleep(10);
                    gotoxy(x_head+1,y_head);
                    printf("\b \b");
                    
                    gotoxy(x_head-1,y_head);
                    printf("◀");
                    Sleep(10);
                    
                    
                    x_tail=Tail[i][0];
                    y_tail=Tail[i][1];
                    gotoxy(x_tail+1,y_tail);
                    printf("\b \b");
                    Sleep(10);
                    gotoxy(x_head,y_head);
                    printf("●");
                    Sleep(10);
                    
                    Tail[i][0]=x_head;
                    Tail[i][1]=y_head;
                    --x_head;
                    
                    if(i==length){
                        i=0;
                        continue;
                    }
                    ++i;
                    Sleep(10);

                }

        }
        system("cls");
        int bv=0,max=0;
        int num=0;
        scores[num]=score;
        ++num;
        printf("\n1.Start the Game\n2.Points menue\n3.Return to provios Menue\n");
        scanf("%d",&bv);
        if(bv==1){
            continue;
        }
        if(bv==2){
            for(int g=0;g<num;++num){
                if(scores[g]>max){
                    max=scores[g];
                }
            }
            printf("\nmaximum of scores is %d",max);
            Sleep(5000);
            return 0;
        }
        if(bv==3){
            return 0;
        }
}


}
