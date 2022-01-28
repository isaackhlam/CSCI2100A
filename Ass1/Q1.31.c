#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    scanf("%d\n",&n);
    while(n--){
        char str[257]="";
        char word[257][51];
        int index=0,i=0,j=0;
        fgets(str, 257, stdin);
        for(i=0; i<=strlen(str);i++){
            if(str[i]==' '||str[i]=='\0'){
                word[index][j]='\0';
                index++;    //i-th word++
                j=0;        //reset position
            }else{
                word[index][j]=str[i];
                j++;
            }
        }

        for(i=0; i<index; i++){
			for(j=strlen(word[i]);j>0;j--){
                if(word[i][j-1]=='\n'||word[i][j-1]==' ') continue;
                printf("%c",word[i][j-1]);
            }
            if(i==index-1) break;
			printf(" ");
        }
        if(!n) break;
		printf("\n");
    }
    return 0;
}
