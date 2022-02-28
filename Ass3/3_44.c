#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *lchild;
  struct node *rchild;
}NODE;

void print(NODE*);
NODE* newNode(int);
NODE* build(int[], int[], int*, int, int, int);
void release(NODE*);

int main(void){
  int test,n;
  scanf("%d",&test);
  while(test--){
    scanf("%d",&n);
    int pre[n],post[n],level[n],index=0;
    for(int i=0; i<n; i++)
      scanf("%d",&pre[i]);
    for(int i=0; i<n; i++)
      scanf("%d",&post[i]);
    NODE *root=build(pre,post,&index,0,n-1,n);
    print(root);
    printf("\n");
    release(root);
  }
  return 0;
}

NODE* build(int pre[], int post[], int* index, int low, int high, int n){
  if(*index >= n || low>high)
    return NULL;
  NODE* root = newNode(pre[*index]);
  ++*index;
  if (low==high)
    return root;
  int i;
  for(i=low; i<=high; ++i)
    if(pre[*index] == post[i])
      break;
  if(i<=high){
    root->lchild = build(pre,post,index,low,i,n);
    root->rchild = build(pre,post,index,i+1,high-1,n);
  }
  return root;
}

NODE* newNode(int data){
  NODE* tmp = (NODE *) malloc(sizeof(NODE));
  tmp->data = data;
  tmp->lchild = tmp->rchild = NULL;
  return tmp;
}

void print(NODE* p){
  if(p){
    print(p->lchild);
    printf("%d ",p->data);
    print(p->rchild);
  }
}

void release(NODE* p){
  if(p){
    release(p->lchild);
    release(p->rchild);
    free(p);
  }
}
