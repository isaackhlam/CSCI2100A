#include <stdio.h>
#include <stdlib.h>
#define NUM 256 // maximum length of 255
int stack[NUM];
int top = -1;
void push(int);
int pop(void);

int main(void){
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
