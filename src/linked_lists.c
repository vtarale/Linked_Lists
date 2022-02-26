#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void append(struct node **, int);
void addbeg(struct node **, int);
int len(struct node *);
int in(struct node *, int);
void insert(struct node **, int, int);
void display(struct node *);
void delete(struct node **, int);
void _dump(struct node *);
void dump(struct node **);

int main(void){
    struct node *linked_list;
    linked_list = NULL;

    append(&linked_list, 1);
    display(linked_list);
    append(&linked_list, 2);
    display(linked_list);
    append(&linked_list, 3);
    display(linked_list);
    printf("Length: %i\n", len(linked_list));
    printf("Index of 2: %i\n", in(linked_list, 2));
    insert(&linked_list, 2, 4);
    display(linked_list);
    delete(&linked_list, 2);
    display(linked_list);
    dump(&linked_list);
}

void append(struct node **root, int data){
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(*root == NULL){
        *root = newnode;
        return;
    }

    struct node *temp = *root;
    while(temp->next != NULL)
        temp = temp->next;
        
    temp->next = newnode;
}

void addbeg(struct node **root, int data){
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *root;
    *root = newnode;
}

int len(struct node *root){
    int i = 0;
    while(root != NULL){
        ++i;
        root = root->next;
    }
    return i;
}

int in(struct node *root, int data){
    int i = 0;
    while(root->data != data){
        ++i;
        root = root->next;
    }
    return i;
}

void insert(struct node **root, int pos, int data){
    struct node *temp = *root, *old = NULL;
    for(int i = 0;i < pos; ++i){
        old = temp;
        temp = temp->next;
    }
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp;
    if(old != NULL)
        old->next = newnode;
}

void display(struct node *root){
    while(root != NULL){
        printf("%i\t", root->data);
        root = root->next;
    }
    printf("\n");
}

void delete(struct node **root, int pos){
    struct node *temp = *root, *old = NULL;
    for(int i = 0;i < pos; ++i){
        old = temp;
        temp = temp->next;
    }
    if(old != NULL)
        old->next = temp->next;
    free(temp);
}

void _dump(struct node *root){
    if(root != NULL){
        _dump(root->next);
        free(root);
    }
}

void dump(struct node **root){
    _dump(*root);
    *root = NULL;
}