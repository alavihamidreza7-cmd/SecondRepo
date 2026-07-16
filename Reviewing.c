#i#include<stdio.h>
#include <stdlib.h>
#include<string.h>
/////////////HLLLLLLLLLLLLLLLLLLLLLLLLKAFDLHLDHFALSDF




int main(){
    int **x=(int **)malloc(2*sizeof(int *));
    for(int i=0;i<5;++i){
        x[i]=(int *)malloc(2*sizeof(int));
    }
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            x[i][j]=12;
    }
    }
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            printf("%d\n",x[i][j]);
    }
    }

    for(int i=0;i<2;++i){
        free(x[i]);
    }
    free(x);
    int *p;
    int *y=(int *)malloc(5*sizeof(int));
    realloc(y,7);
    for(int k=0;k<7;++k){
       *(y+k)=k+15;
    }
    for(int k=0;k<7;++k){
        printf("%d\n",y[k]);
    }
    free(p);
    
}
