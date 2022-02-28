#include <stdio.h>
#include <stdlib.h>
#define lchild(i) 2*i
#define rchild(i) 2*i+1

typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}NODE;

void printTree(NODE*);
void build(NODE[],int);

int main(void){
    int test,n;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        NODE tree[n+1];
        build(tree,n);
        printTree(tree+1);
        printf("\n");
    }
    return 0;
}

void build(NODE tree[],int n){
    for(int i=1; i<n+1; i++)
        scanf("%d",&tree[i].data);
    for(int i=1; i<n+1; i++){
        if(lchild(i)<n+1&&tree[i].data&&tree[lchild(i)].data)
            tree[i].lchild = &tree[lchild(i)];
        else
            tree[i].lchild = NULL;
        if(rchild(i)<n+1&&tree[i].data&&tree[rchild(i)].data)
            tree[i].rchild = &tree[rchild(i)];
        else
            tree[i].rchild = NULL;
    }
}

void printTree(NODE* p){
  if(p){
    printTree(p->lchild);
    printf("%d ",p->data);
    printTree(p->rchild);
  }
}
