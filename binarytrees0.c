#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(struct node* root){
    if(root != NULL){
        printf("%d->", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    // printf("\n");
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d->", root->data);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d->", root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node* p = createNode(5);
    struct node* p1 = createNode(10);
    struct node* p2 = createNode(15);
    struct node* p3 = createNode(20);
    struct node* p4 = createNode(25);
    struct node* p5 = createNode(30);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}