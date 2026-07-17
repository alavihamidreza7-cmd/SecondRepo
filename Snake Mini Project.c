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
char central_auethentication[100][2][100];
char current_Player_Name[100];
char current_Player_Password[100];
int i=-1;
max_map2=0;
char None[100]={0};
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
    x=109,y=15;
    for(int i=1;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        --x;
    }
    x=80,y=1;
    for(int i=0;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        ++y;
    }
    x=80,y=30;
    for(int i=1;i<=10;++i){
        gotoxy(x,y);
        printf("█");
        --y;
    }
}
void first_menue(){
    system("cls");
    setColor(LIGHTGRAY);
    printf("Dear %s ,welcome to a Nostalgia Game (Snake Game)",current_Player_Name);
    resetColor();
    Sleep(1000);
    setColor(BROWN);
    printf("\nfirst You should sign up in this Game");
    Sleep(1000);
    printf("\nPlease Wait \nLoading....\n");
    resetColor();
    Sleep(2000);
    return ;
}
void signing_up(){
    int p=0;
    while(1){
        system("cls");
        strcpy(central_auethentication[i][0],current_Player_Name);
        printf("select a Pasword:\t");
        scanf("%99s",current_Player_Password);
        strcpy(central_auethentication[i][1],current_Player_Password);
        Sleep(1000);
        setColor(RED);
        printf("\nguide: 1.confirm          2.reject");
        resetColor();
        Sleep(1000);
        printf("\ndo you confirm your Password:  ");
        scanf("%d",&p);
        if(p==1){
            return;
        }
        strcpy(central_auethentication[i][1],None);

    }
}
void Map1(void);
void Map2(void);
int main(){
    while(1){
        int exist=0,notexist=0,choice=0;
        system("cls");
        setColor(BLUE);
        printf("Hellow Dear player ,What is you Name:  ");
        resetColor();
        ++i;
        scanf("%99s",current_Player_Name);
        for(int i=0;i<99;++i){
            if(central_auethentication[i][0]==current_Player_Name){
                if(central_auethentication[i][1]==current_Player_Password){
                    notexist=0;
                    exist=1;
                    break;
                }
            }
            notexist=1;

        }
        if(notexist==1){
            first_menue();
            signing_up();
            exist=1;
        }
        if(exist==1){
            while(1){
                printf("\n1.Map number one \n2.Map number tow \n3.Logout from this account\n4.NEW update (MAP number 4)\n");
                setColor(CYAN);
                printf("\n Dear %s,please choice what do you want to do?  ",current_Player_Name);
                resetColor();
                scanf("%d",&choice);
                switch(choice){
                    case 1:
                        Map1();
                        break;
                    case 2:
                        Map2();
                        break;
                    case 3:
                        for(int j=0;j<99;++j){
                            current_Player_Name[j]=0;
                            current_Player_Password[j]=0;
                        }
                        strcpy(central_auethentication[i][0],current_Player_Name);
                        strcpy(central_auethentication[i][1],current_Player_Password);
                        setColor(RED);
                        printf("Dear %s,you logged out",current_Player_Name);
                        Sleep(2000);
                        resetColor();
                        break;
                    case 4:
                        Sleep(2000);
                        setColor(RED);
                        printf("\nNetwork Error!!");
                        Sleep(3000);
                        resetColor();
                        break;
                    default:
                        break;
                }
                if(choice==3){
                    break;
                }

                }
            
                
            }
        }

}
void Map2(void){
    int bv=0;
    while(1){
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
        int o=0;
        int Pointeer=0;
        int flag=0;
        int length=1;
        wint_t direct='d';
        while(1){
            
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
            if(x==51 || x==109 || y==1 || y==29 || Pointeer==1){
                Pointeer=0;
                continue;
            }
            if((y==15 && (x<=60 && x>=50 )) || (y==15 && (x<=109 && x>=99))||(x==80 && (y<=10 &&y>=1))|| (x==80 &&(y<=30 && y>=20))){
                continue;
            }
            if(x_head==50 || x_head==109 || y_head==1 || y_head==30 || Pointeer==1){
                gotoxy(0,35);
                setColor(RED);
                Sleep(1000);
                printf("Game Over");
                resetColor();
                Sleep(2000);
                printf("\nUnfortunately,Dear %s you occure to WALLS of play!!",current_Player_Name);
                Sleep(2000);
                break;
            }
            if((y_head==15 && (x_head<=59 && x_head>=50 )) || (y_head==15 && (x_head<=109 && x_head>=100)) || (x_head==80 && (y_head<=11)) || (x_head==80 &&(y_head<=30 && y_head>=21))){
                gotoxy(0,35);
                setColor(RED);
                Sleep(1000);
                printf("Game Over");
                resetColor();
                Sleep(2000);
                printf("\nUnfortunately,Dear %s you occure to WALLS of play!!",current_Player_Name);
                Sleep(2000);
                break;
            }
            if(collide==1){
                gotoxy(0,35);
                setColor(RED);
                Sleep(1000);
                printf("GAME OVER!!!");
                resetColor();
                Sleep(2000);
                printf("\nUnfortunately,Dear %s you occure to your snke's Tail!!",current_Player_Name);
                Sleep(2000);
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

            if(x_head==x && y_head==y){
                
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
                    ++score;
                    gotoxy(0,0);
                    setColor(CYAN);
                    printf("%s' score = %d",current_Player_Name,score);
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
                                setColor(BROWN);
                                printf("●");
                                resetColor();
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
                                setColor(BROWN);
                                printf("●");
                                resetColor();
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
                                setColor(BROWN);
                                printf("●");
                                resetColor();
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
                                setColor(BROWN);
                                printf("●");
                                resetColor();
                                Tail[length][0]=x_head;
                                Tail[length][1]=y_head;
                                --x_head;

                            }

                        }
                        gotoxy(0,0);
                        setColor(CYAN);
                        printf("%s' score = %d",current_Player_Name,score);
                        ++score;
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
            if(score>= max_map2){
                max_map2=score;
            }
            setColor(CYAN);
            printf("\nyour score = %d",score);
            resetColor();
            printf("\n1.Start the Game\n2.Points menue\n3.Return to provios Menue\n");
            scanf("%d",&bv);
            if(bv==1){
                continue;
            }
            if(bv==2){
                
                printf("Maximum score of this Map is %d",max_map2);
                Sleep(2000);
                continue;
            }
            if(bv==3)
                return ;
            }
        }


void Map1(void){
    int num=0;
    int max_map2=0;
    while(1){
        int score=0;
        int Tail[1250][2]={{56,2},{57,2}};
        int i=0,x_tail,y_tail,x_head=58,y_head=2,x,y;
        srand(time(NULL));
        SetConsoleOutputCP(65001);
        system("cls");
        Map();
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
        int o=0;
        int Pointeer=0;
        int flag=0;
        int length=1;
        wint_t direct='d';
        while(1){
            
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
            if(x==51 || x==109 || y==1 || y==29 || Pointeer==1){
                Pointeer=0;
                continue;
            }
            if(x_head==50 || x_head==109 || y_head==1 || y_head==30 || Pointeer==1){
                gotoxy(0,35);
                setColor(RED);
                Sleep(1000);
                printf("Game Over");
                resetColor();
                Sleep(2000);
                printf("\nUnfortunately,Dear %s you occure to WALLS of play!!",current_Player_Name);
                Sleep(2000);
                break;
            }
            if(collide==1){
                gotoxy(0,35);
                setColor(RED);
                Sleep(1000);
                printf("GAME OVER!!!");
                resetColor();
                Sleep(2000);
                printf("\nUnfortunately,Dear %s you occure to your snke's Tail!!",current_Player_Name);
                Sleep(2000);
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

            if(x_head==x && y_head==y){
                
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
                    ++score;
                    gotoxy(0,0);
                    setColor(CYAN);
                    printf("%s' score = %d",current_Player_Name,score);
                    resetColor();
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
                        gotoxy(0,0);
                        setColor(CYAN);
                        printf("%s' score = %d",current_Player_Name,score);
                        ++score;
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
                setColor(BROWN);
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
                resetColor();
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
                    resetColor();
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
            int bv=0;
            if(score>= max_map2){
                max_map2=score;
            }
            printf("\nyour score = %d",score);
            printf("\n1.Start the Game\n2.Points menue\n3.Return to provios Menue\n");
            scanf("%d",&bv);
            if(bv==1){
                continue;
            }
            if(bv==2){
                
                printf("Maximum score of this Map is %d",max_map2);
                Sleep(2000);
                continue;
            }
            if(bv==3)
                return ;
            }
    }


