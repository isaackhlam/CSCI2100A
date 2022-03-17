#include <stdio.h>
#include <stdlib.h>

int* build(int);
int hashFunction(int, int);
int hashNext(int, int, int);
void insert(int*, int, int);
int search(int*, int, int);
void solve(void);
int count(int*, int, int);

int main(void){
    solve();
    return 0;
}

int* build(int size){
    int* h = (int*)malloc(sizeof(int) * size);
    for(int i=0;i<size;i++) h[i] = 0;
    return h;
}

int hashFunction(int data, int size){
    return data % size;
}

int hashNext(int k, int data, int size){
    return (hashFunction(data, size) + k) % size;
}

void insert(int* h, int data, int size){
    int hashValue = hashFunction(data, size);
    int i = hashValue;
    int k = 1;
    while(h[i])
        i = hashNext(k++, data, size);
    h[i] = data;
}

int search(int* h, int data, int size){
    int hashValue = hashFunction(data, size);
    int i = hashValue;
    int k = 1;
    while(h[i] != data){
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
        int* h = build(size);
        for(int i = 0; i<size; i++){
            scanf("%d",&data);
            insert(h, data, size);
        }
        printf("%d\n",count(h, product, size));
        free(h);
    }
}

int count(int* h, int product, int size){
    int COUNT = 0;
    if(!product){
        for(int i=0; i<size; i++)
            if(!h[i]) return (size-1)*(size-2)/2;
        return 0;
    } 
    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
            if((h[i]*h[j] <= product) && (h[i]*h[j]) && !(product % h[i]*h[j])){
                int k = product / (h[i]*h[j]);
                if(k >= h[i] && k >= h[j] && search(h, k, size))
                    COUNT++;
            }
    return COUNT;
}