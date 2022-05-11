#include <stdio.h>
#include <stdlib.h>

typedef struct Hashstruct{
    int* key;
    int* state;
}Hash;

Hash* build(int);
int hashFunction(int, int);
int hashNext(int, int, int);
void insert(Hash*, int, int);
int search(Hash*, int, int);

int main(void){
    return 0;
}

Hash* build(int size){
    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->key = (int*)malloc(sizeof(int) * size);
    h->state = (int*)malloc(sizeof(int) * size);
    for(int i=0;i<size;i++) h->state[i] = 0;
    return h;
}

int hashFunction(int data, int size){
    return data % size;
}

int hashNext(int k, int data, int size){
    return (hashFunction(data, size) + k) % size;
}

void insert(Hash* h, int data, int size){
    int hashValue = hashFunction(data, size);
    int i = hashValue;
    int k = 1;
    while(h->state[i])
        i = hashNext(k++, data, size);
    h->key[i] = data;
    h->state[i] = 1;
}

int search(Hash* h, int data, int size){
    int hashValue = hashFunction(data, size);
    int i = hashValue;
    int k = 1;
    while(h->key[i] != data){
        i = hashNext(k++, data, size);
        if(k > size) return 0;
    }
    return 1;
}
