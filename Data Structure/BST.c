#include <stdio.h>
#include <stdlib.h>
#define isleaf(p) (p->lchild == NULL && p->rchild == NULL) ? 1:0

typedef struct node{
    int key;
    struct node* lchild;
    struct node* rchild;
    struct node* parent;
} NODE;

NODE* search(int,NODE*);
NODE* search2(int,NODE*);
void insert(int,NODE**);
void delete(int,NODE*);
void inorder(NODE*);
NODE* leftmost(NODE*);
NODE* rightleast(NODE*);

int main(void){
  return 0;
}

NODE* leftmost(NODE* p){
    if(p->lchild == NULL)
        return NULL;
    p = p->lchild;
    while(p->rchild != NULL)
        p = p->rchild;
    if(p->lchild != NULL)
        p = p->lchild;
    return p;
}

NODE* rightleast(NODE* p){
    if(p->rchild == NULL)
        return NULL;
    p = p->rchild;
    while(p->lchild != NULL)
        p = p->lchild;
    if(p->rchild != NULL)
        p = p->rchild;
    return p;
}

NODE* search(int key,NODE* p){
    while(p){
        if(key == p->key) return p;
        if(key < p->key)
            p = p->lchild;
        else
            p = p->rchild;
   }
   return NULL;
}

NODE* search2(int key,NODE* p){
    while(p != NULL){
        if(key == p->key) return NULL;
        if(key < p->key)
            if(p->lchild == NULL)
                return p;
            else
                p = p->lchild;
        else
            if(p->rchild == NULL)
                return p;
            else
                p = p->rchild;
  }
}

void delete(int key,NODE* p){
    NODE *n=search(key,p);
    if(isleaf(n)){
        if(n->parent->key > n->key)
            n->parent->lchild = NULL;
        else
            n->parent->rchild = NULL;
        free(n);
        return;
    }else{
        NODE *l=leftmost(n);
        NODE *r=rightleast(n);
        if(l != NULL){
            n->key = l->key;
            if(l->parent->rchild == l)
                l->parent->rchild = NULL;
            else
                l->parent->lchild = NULL;
            free(l);
        }else{
            n->key = r->key;
            if(r->parent->rchild == r)
                r->parent->rchild = NULL;
            else
                r->parent->lchild = NULL;
            free(r);
        }
    }
}

void insert(int key,NODE **p){
    NODE *n,*tmp;
    tmp = search2(key,*p);
    if(tmp != NULL || *p == NULL){
        n = (NODE*)malloc(sizeof(NODE));
        n->key = key;
        n->parent = NULL;
        n->lchild = NULL;
        n->rchild = NULL;
        if(*p != NULL){
            if(key < tmp->key){
                tmp->lchild = n;
                n->parent = tmp;
            }else{
                tmp->rchild = n;
                n->parent = tmp;
            }
        }else *p =n;
    }
}

void inorder(NODE* p){
    if(p != NULL){
        inorder(p->lchild);
        printf("%d ",p->key);
        inorder(p->rchild);
    }
}
