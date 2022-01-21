#include <stdio.h>

unsigned int length(unsigned int a){
    unsigned int count=0;
    while(a){
        count++;
        a >>= 1;
    }   
    return count;
}

int main(void){
    int n; 
    scanf("%d", &n);
    int result[n];

    for(int i=0; i<n; i++){
        unsigned int a, b;
        scanf(" %d %d",&a,&b);
        a <<= length(b);
        result[i] = a|b;
    } 

    for(int i=0;i<n;i++)
        printf("%u\n",result[i]);
    
    return 0;
}
