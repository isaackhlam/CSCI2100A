#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void * p, const void * q){
    const char *a = *(const char **)p;
    const char *b = *(const char **)q;
    char tmp1[5]="",tmp2[5]="";
    strcat(tmp1,a);
    strcat(tmp1,b);
    strcat(tmp2,b);
    strcat(tmp2,a);
    return strcmp(tmp1,tmp2);
    /*
    if(a[1]==b[1] && a[1]==0){
        return a[0]-b[0];
    }else if(a[2]==b[2] && a[2]==0){
        if(a[0]==b[0])
            return a[1]-b[1];
        else
            return a[0]-b[0];
    }else if(a[1]==0){
        if(b[0]==a[0])
            return a[0]-b[1];
        else
            return a[0]-b[0];
    }else{
        if(b[0]==a[0])
            return a[1]-b[0];
        else
            return a[0]-b[0];
    }
    */
}

int solve(void){
    int n;
    scanf("%d ",&n);
    char** input = (char**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        input[i]=(char*)malloc(sizeof(char)*3);
        scanf("%s",input[i]);
    }
    qsort(input,n,sizeof(input[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%s",input[i]);
    printf("\n");
}

void init(void){
    int n;
    scanf("%d",&n);
    while(n--)
        solve();
}

int main(void){
    init();
    return 0;
}
