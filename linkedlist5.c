#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* start=NULL;

void enterElement(struct node **head,int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if((*head)==NULL){
        (*head)=new;
    }
    else{
        struct node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}

void traverse(struct node **head){
    struct node* temp = *head;
    printf("Required Linked List : \n");
    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
}

void enterFirst(struct node** head,int val){
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next = NULL;
    if((*head)==NULL){
        (*head)=new;
    }
    else{
        new->next=*head;
        (*head)=new;
    }
}

void deleteFirst(struct node** head){

    if(head==NULL){
        printf("Empty Linked List \n");  
    }
    else{
        struct node* temp=*head;
        (*head)=(*head)->next;
        free(temp);
    }
}

void enterLast(struct node** head,int val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    struct node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}

void deleteLast(struct node** head){
    struct node* x= *head;
    struct node* y= (*head)->next;
    while(y->next!= NULL){
        y=y->next;
        x=x->next;
    }
    x->next=NULL;
    free(y);
}

void enterPos(struct node** head,int val,int pos)
{
    struct node *new= (struct node*)malloc(sizeof(struct node));
    struct node *temp=*head;
    new->data=val;
    new->next=NULL;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    temp->next=new;
}

void deletePos(struct node** head,int pos)
{
    struct node* x= *head;
    struct node* y= (*head)->next;
    int i=1;
    while(i<pos-1)
    {
        x=x->next;
        y=y->next;
        i++;
    }
    x->next=y->next;
    free(y);
}

int main(){
    printf("Enter number of nodes \n");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d \n",i+1);
        int v;scanf("%d",&v);
        enterElement(&start,v);
    }    
    traverse(&start);
    printf("\n1. Enter at first\n2.Delete at First\n3.Enter at last\n4.Delete at Last\n5.Enter at Position\n6.Delete at Position\n");
    printf("Enter your choice\n");
    int c; 
    scanf("%d",&c);

    switch(c){
        case 1: 
            enterFirst(&start,100);
            traverse(&start);
            break;
        case 2:
            deleteFirst(&start);
            traverse(&start);
            break;
        case 3:
            enterLast(&start,600);
            traverse(&start);
            break;
        case 4:
            deleteLast(&start);
            traverse(&start);
            break;
        case 5:
            enterPos(&start,300,3);
            traverse(&start);
            break;
        case 6 :
            deletePos(&start,3);
            traverse(&start);
            break;
    }
    return 0;
}
