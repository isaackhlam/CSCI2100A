#include <stdio.h>
#include <stdlib.h>
#define lchild(i) 2*i
#define rchild(i) 2*i+1
int painter = 0;

typedef struct node{
    int data;
    int painted;
    struct node* lchild;
    struct node* rchild;
    struct node* parent;
}NODE;

void build(NODE[],int);
void paint(NODE*);
void check(NODE*);

int main(void){
    int test,n;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        NODE tree[n+1];
        build(tree,n);
        check(tree+1);
        printf("%d\n", painter);
        painter=0;
    }
    return 0;
}

void build(NODE tree[],int n){
    for(int i=1; i<n+1; i++){
        scanf("%d",&tree[i].data);
        tree[i].painted = 0; 
    }
        tree[1].parent = NULL;
    for(int i=1; i<n+1; i++){
        if(lchild(i)<n+1&&tree[i].data){
            tree[i].lchild = &tree[lchild(i)];
            tree[i].lchild->parent = &tree[i];
        }else
            tree[i].lchild = NULL;
        if(rchild(i)<n+1&&tree[i].data&&tree[rchild(i)].data){
            tree[i].rchild = &tree[rchild(i)];
            tree[i].rchild->parent = &tree[i];
        }else
            tree[i].rchild = NULL;   
    }
}

void check(NODE* p){
    if(p){
        check(p->lchild);
        check(p->rchild);
        if(!p->painted) paint(p->parent);
    }
}

void paint(NODE* p){
    p->painted = 1;
    if(p->parent) p->parent->painted = 1;
    if(p->lchild) p->lchild->painted = 1;
    if(p->rchild) p->rchild->painted = 1;
    painter++;
}
