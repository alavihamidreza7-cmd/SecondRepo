#include <stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

char central_auethentication[100][2][100];
char current_Player_Name[100];
char current_Player_Password[100];
int i=-1;
char None[100]={0};
void first_menue(){
    system("cls");
    printf("Dear %s ,welcome to a Nostalgia Game (Snake Game)",current_Player_Name);
    printf("\n first You should sign up in this Game");
    Sleep(1000);
    printf("\nPlease Wait \n Loading....\n");
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
        printf("\nguide:1.confirm 2.reject");
        printf("\ndo you confirm your Password:");
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
    int exist=0,notexist=0,choice=0;
    printf("Hellow Dear player ,What is you Name:\t");
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
            printf("\n1.Map number one \n Map number tow \n Logout from this account\n");
            printf("\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    Map1();
                    break;
                case 2:
                    Map2();
                    break;
                default:
                    printf("log out");
                    break;

            }
            

        }
        
            
    }

}
void Map1(){
    printf("map1");
}
void Map2(){
    printf("map2");
}