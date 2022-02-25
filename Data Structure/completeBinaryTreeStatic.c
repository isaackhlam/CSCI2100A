#include <stdio.h>
#include <stdilb.h>
#define lchild(i) 2*i
#define rchild(i) 2*i+1

typedef struct node{
    char data;
    struct node* lchild;
    struct node* rchild;
}NODE;

void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);

int main(void){
    int n;
    NODE tree[n]; 
    for(int i=1; i<n; i++){
       scanf("%d",&tree[i].data);
      if(lchild(i)<n)
        tree[i].lchild = %tree[lchild(i)];
      else
        tree[i].lchild = NULL;
      if(rchild(i)<n)
        tree[i].rchild = &tree[rchild(i)];
      else
        tree[i].rchild = NULL;
    }
    return 0;
}

void preorder(NODE* p){
  if(p){
    printf("%d",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void inorder(NODE* p){
  if(p){
    inorder(p->lchild);
    printf("%d",p->data);
    inorder(p->rchild);
  }
}

void postorder(NODE* p){
  if(p){
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d",p->data);
  }
}

  
