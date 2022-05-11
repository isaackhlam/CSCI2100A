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
void solve(void);
int count(Hash*, int, int);

int main(void){
    solve();
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

void solve(void){
    int n;
    scanf("%d",&n);
    while(n--){
        int size, product, data;
        scanf("%d %d",&size, &product);
        Hash* h = build(size);
        for(int i = 0; i<size; i++){
            scanf("%d",&data);
            insert(h, data, size);
        }
        printf("%d\n",count(h, product, size));
        free(h);
    }
}

int count(Hash* h, int product, int size){
    int COUNT = 0;
    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
            if((h->key[i]*h->key[j] <= product) && (h->key[i]*h->key[j]) && !(product % h->key[i]*h->key[j]) ){
                int k = product / (h->key[i]*h->key[j]);
                if(k >= h->key[i] && k >= h->key[j] && search(h, k, size))
                    COUNT++;
            }
    return COUNT;
}
