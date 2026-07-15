#include<iostream>
#include<string.h>
#include<string.h>
using namespace std;
struct Participants{
    string name;
    int Score=0;
    int Rank=0;
};
Participants Members[100];
string Loosen_Member[8],Array[8];
int Member_Count=0;
int ranking[]={1,2,3,4,5,6,7,8};
int Calculation_Score(int S,int P,int R);
int Calculation_Rank(int S,int P,int Score);
int Finding_Member(string name);
int Finding_LoosenMember(string lossen);
void Determining_Rank(string Name,int Rank);
void Ranking_LoosenMember(void);
int main(void){
    int availableInfo=0;
    cin>>availableInfo;
    for(int i=0;i<availableInfo;++i){
        int S=0,P=0;
        cin>>S>> P;
        for(int j=0;j<P;++j){
            string Player;
            cin>>Player;
            int Exist=Finding_Member(Player);
            int score=Calculation_Score(S,P,j);
            if(Exist!=-1){ 
                Members[Exist].Score+=score;
            }
            else{
                Members[Member_Count].name=Player;
                Members[Member_Count].Score=+score;
                ++Member_Count;
            }
        }
    }
    int S_Loosen=0,P_Loosen=0;
    cin>>S_Loosen>> P_Loosen;
    string actor;
    for(int i=0;i<P_Loosen;++i){
        cin>>actor;
        Loosen_Member[i]=actor;
    }
    int count=0;
    cin>>count;
    for(int j=1;j<=count;++j){
        cin>>actor;
        Determining_Rank(actor,j-1);
    }
    for(int k=1;k<=Member_Count;++k){
        int t=0;
        
        t=Finding_LoosenMember(Members[k-1].name);
        
        if(k==1 && t==1){
            Array[0]=Members[k-1].name;
            continue;
        }
       
        if(t==1){
            int SCORE=Members[k-1].Score-Members[k-2].Score;
            int rank=Calculation_Rank(S_Loosen,P_Loosen,SCORE);
            Array[rank-1]=Members[k-1].name;
        }
        
    }
    


    
    




}