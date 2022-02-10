#include <stdio.h>
#include <stdlib.h>
#define NUM 1000

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
    int n;
    
    scanf("%d",&n);
    while(n--){
        char operation;
        int bit,end=0;
        qu.rear = -1;
        qu.front = -1;
        while(!end){
            scanf("\n%c",&operation);
            switch(operation){
                case 'S':
                    break;
                case 'E':
                    scanf(" %d",&bit);
                    enqueue(bit);
                    break;
                case 'D':
                    dequeue();
                    break;
                default:
                    printQueue();
                    end=1;
                    break;
                }
        }
    }
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
    for(int i=qu.rear; i>=qu.front+1; i--)
        printf("%d",qu.q[i]);
    printf("\n");
}
