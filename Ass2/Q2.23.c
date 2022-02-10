#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 256 // maximum length of 255
int stack[NUM];
int top = -1;
void push(int);
int pop(void);
int fact(int);
int main(void){
    int n;
    scanf("%d\n",&n);
    while(n--){
        // This part chop down the string input into words
        int index=0, i=0, j=0, ans=0;
        char str[256]="";
        char word[256][256];
        fgets(str,256,stdin);
        for(i=0; i<strlen(str); i++)
            if(str[i]==' '||str[i]=='\0'){
                word[index][j]='\0';
                index++;
                j=0;
            }else{
                word[index][j]=str[i];
                j++;
            }
        //Computation part
        int t1,t2,calerr=0;
        for(i=0; i<=index; i++){
            switch(word[i][0]){
                case '+':
                    ans=pop()+pop();
                    push(ans);
                    index++;
                    break;
                case '-':
                    if(word[i][1]!='\0'){
                        push(atoi(word[i]));
                        break;
                    }
                    t2=pop();
                    t1=pop();
                    ans=t1-t2;
                    push(ans);
                    index++;
                    break;
                case '*':
                    ans=pop()*pop();
                    push(ans);
                    index++;
                    break;
                case '/':
                    t2=pop();
                    t1=pop();
                    if (!t2){
                        printf("division by zero\n");
                        i=index;
                        calerr=1;
                        break;
                    }
                    ans=t1/t2;
                    push(ans);
                    index++;
                    break;
                case '!':
                    t1=pop();
                    if(t1<0){
                        printf("factorial of an negative number\n");
                        i=index;
                        calerr=1;
                        break;
                    }
                    ans=fact(t1);
                    push(ans);
                    index++;
                    break;
                default:
                    push(atoi(word[i]));
            }
        }
        if(calerr){
            for(i=0; i<NUM; i++) stack[i]=0;
            continue;
        }
        printf("%d\n",ans);
    }
}

void push(int n){
    if(top == NUM-1){
        fprintf(stderr,"stack is full!");
        exit(1);
    }
    stack[++top] = n;
}

int pop(void){
    if(top == -1){
        fprintf(stderr,"stack is empty!");
        exit(1);
    }
    return stack[top--];
}

int fact(int n){
    int ans=1;
    if(n==1) return 1;
    ans *= n*fact(n-1);
    return ans;
}
