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

int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node* search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key == root->data){
        return root;
    }
    else if(key < root->data){
        return search(root->left, key);
    }
    else if(key > root->data){
        return search(root->right, key);
    }
}

struct node* searchiter(struct node* root, int key){
    while(root != NULL){
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else if(key > root->data){
            root = root->right;
        }
    }
    return NULL;
}

void insert(struct node* root, int key){
    struct node* prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            printf("Cannot insert %d", key);
            return;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

int main(){
    struct node* p = createNode(5);
    struct node* p1 = createNode(3);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(2);
    struct node* p4 = createNode(4);
    struct node* p5 = createNode(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    insert(p, 400);
    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    insert(p, 40);
    printf("\n%d",isBST(p));
    struct node* n = search(p, 7);

    if(n!=NULL){
    printf("\nFound: %d", n->data);
    }
    else{
        printf("\nElement not found");
    }

    struct node* n1 = searchiter(p, 40);

    if(n1!=NULL){
    printf("\nFound: %d", n1->data);
    }
    else{
        printf("\nElement not found");
    }

    return 0;
}