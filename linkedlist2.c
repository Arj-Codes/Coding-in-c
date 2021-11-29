#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void traverse(struct node* ptr){
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }

}

struct node *atfirst(struct node* head,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next=head;
    head=newnode;
    newnode->data=data;
    return head;
}

struct node *inbetween(struct node* head,int data,int index){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    newnode->next=p->next;
    p->next=newnode;
    newnode->data=data;
    return head;
}

struct node *atend(struct node* head,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    newnode->next=NULL;
    p->next=newnode;
    newnode->data=data;
    return head;
}

struct node *afterNode(struct node *prevNode,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next=prevNode->next;
    prevNode->next=newnode;
    newnode->data=data;
}




int main(){    
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    printf("Before Insertion \n");
    traverse(head);
    //head = atfirst(head,40);
    //head = inbetween(head,40,2);
    //head = atend(head,40);
    afterNode(second,40);
    printf("\nAfter Insertion \n");
    traverse(head);

    return 0;
}