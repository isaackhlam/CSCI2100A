#include <stdio.h>
#include <stdlib.h>
#define lchild(i) (2*(i)+1)
#define rchild(i) (2*(i)+2)
#define parent(i) ((i-1)/2)
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct HeapStruct{
    int capacity;
    int size;
    int* data;
}Heap;

int Heap_Full(Heap*);
int Heap_Empty(Heap*);
Heap* createHeap(int);
void insertHeap(Heap*, int);
int deleteHeap(Heap*);
void run(void);

int main(void){
    run();
    return 0;
}

int Heap_Full(Heap* h){
    if(h->capacity==h->size) return 1;
    return 0;
}

int Heap_Empty(Heap* h){
    if(h->size) return 0;
    return 1;
}

Heap* createHeap(int k){
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = (int*)malloc(sizeof(int) * k);
    h->capacity = k;
    h->size = 0;
    return h;
}

void insertHeap(Heap* h, int data){
    int i;
    if (Heap_Full(h)){
        printf("The heap is Full\n");
        exit(1);
    }
    i = h->size;
    while(i && data > h->data[parent(i)]){
        h->data[i] = h->data[parent(i)];
        i=parent(i);
    }
    h->data[i]=data;
    h->size++;
}

int deleteHeap(Heap *h){
    int parent = 0, child = 1;
    int data,tmp;
    if(Heap_Empty(h)){
        printf("The heap is empty\n");
        exit(1);
    }
    data = h->data[0];
    tmp = h->data[h->size - 1];
    h->size--;
    while (child <= (h->size-1)){
        if(child<(h->size -1) && (h->data[child] < h->data[child+1] ))
            child++;
        if(tmp >= h->data[child])
            break;
        h->data[parent] = h->data[child];
        parent = child;
        child = lchild(child);
    }
    h->data[parent] = tmp;
    return data;
}

void run(void){
    char input;
    int data,k;
    scanf("%d",&k);
    Heap* h = createHeap(k);
    while(input != 'S'){
        scanf("%c",&input);
        switch(input){
            case 'I':
                scanf("%d",&data);
                if(h->size < h->capacity){
                    insertHeap(h,data);
                }else if(data <= h->data[0]){
                    deleteHeap(h);
                    insertHeap(h,data);
                }
                break;
            case 'O':
                printf("%d\n",h->data[0]);
                break;
            case 'S':
                break;
        }
    }
}
