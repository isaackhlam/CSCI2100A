#include <stdio.h>
#include <stdlib.h>
#define lchild(i) 2*i
#define rchild(i) 2*i+1
#define NUM 10004

typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}NODE;

void printTree(NODE*);

int main(void){
    int test,n;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        NODE tree[n+1];
        for(int i=1; i<n+1; i++){
        scanf("%d",&tree[i].data);
        if(lchild(i)<n+1)
            tree[i].lchild = &tree[lchild(i)];
        else
            tree[i].lchild = NULL;
        if(rchild(i)<n+1)
            tree[i].rchild = &tree[rchild(i)];
        else
            tree[i].rchild = NULL;
        }
        printTree(tree+1);
        printf("\n");
    }
    return 0;
}

void printTree(NODE* p){
  if(p){
    printTree(p->lchild);
    if(p->data) printf("%d ",p->data);
    printTree(p->rchild);
  }
}
