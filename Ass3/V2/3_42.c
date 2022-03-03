#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lchild(i) 2*i+1
#define rchild(i) 2*i+2
#define NUM 1024
int painter = 0;
int input[NUM];

typedef struct node{
    int data;
    int painted;
    struct node* lchild;
    struct node* rchild;
    struct node* parent;
}NODE;

void paint(NODE*);
void check(NODE*);
void release(NODE*);
void reset(NODE*);
NODE* build(void);
NODE* create(NODE*, int);
NODE* insert(NODE*, NODE*, int, int);

int main(void){
    int n;
    scanf("%d",&n);
    while(n--){
        NODE* root = build();
        check(root);
        if(!root->painted) painter++;
        printf("%d\n", painter);
        reset(root);
    }
    return 0;
}

NODE* build(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&input[i]);
    NODE* root = insert(NULL, root, 0, n);
    return root;
}

NODE* create(NODE* p, int data){
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->lchild = tmp->rchild = NULL;
	tmp->parent = p;
	tmp->data = data;
	tmp->painted = 0;
	return tmp;
}

NODE* insert(NODE* parent, NODE* root, int i, int n){
	if(!input[i]) return NULL;
	if(i<n){
		root = create(parent, input[i]);
		root->parent = parent;
		root->lchild = insert(root, root->lchild,lchild(i),n);
		root->rchild = insert(root, root->rchild,rchild(i),n);
	}
	return root;
}

void check(NODE* p){
	if(p->lchild)
		check(p->lchild);
	if(p->rchild)
		check(p->rchild);
	if(p->lchild && !(p->lchild->painted))
        paint(p);
    else if(p->rchild && !(p->rchild->painted))
        paint(p);
}

void paint(NODE* p){
	painter++;
    p->painted = 1;
    if(p->parent) p->parent->painted = 1;
    if(p->lchild) p->lchild->painted = 1;
    if(p->rchild) p->rchild->painted = 1;
}

void release(NODE* p){
	if(p){
		release(p->lchild);
		release(p->rchild);
		free(p);
	}
}

void reset(NODE* p){
    painter = 0;
    release(p);
    memset(input,'0',sizeof(input));
}
