#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    scanf("%d\n",&n);
    while(n--){
        char str[257]="";
        char word[257][51];
        int index=0,j;
        fgets(str, 257, stdin);
        for(int i=0; i<=strlen(str);i++){
            if(str[i]==' '||str[i]=='\0'){
                word[index][j]='\0';
                index++;    //i-th word++
                j=0;        //reset position
            }else{
                word[index][j]=str[i];
                j++;
            }
        }

        for(int i=0; i<index; i++){
            for(j=strlen(word[i]);j>0;j--){
                if(word[i][j-1]=='\n') continue;
                printf("%c",word[i][j-1]);
            }
            printf(" ");
        }
        printf("\n");

    }
    return 0;
}
