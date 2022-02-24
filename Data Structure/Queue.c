#include <stdio.h>
#include <stdlib.h>
#define NUM 1024

typedef struct queue{
    int q[NUM];
    int front;
    int rear;
} Queue;
Queue qu;
void printQueue(void);
void enqueue(int);
int dequeue(void);
int main(void){
    return 0;
}

void enqueue(int n){
    if(qu.rear == NUM -1){
        fprintf(stderr,"queue is full!\n");
        return;
    } else
        qu.q[++qu.rear] = n;
}

int dequeue(void){
    if(qu.front == qu.rear){
        fprintf(stderr,"queue is empty!\n");
        return -1;
    } else
        return qu.q[++qu.front];
}

void printQueue(void){
    for(int i=qu.front+1; i<=qu.rear; i++)
        printf("%d",qu.q[i]);
    printf("\n");
}

void reversePrintQueue(void){
    for(int i=qu.rear; i>=qu.front+1; i--)
        printf("%d",qu.q[i]);
    printf("\n");
}
