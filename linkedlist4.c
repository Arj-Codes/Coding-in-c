#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* createNode(struct node* temp,int h){
    for(int i=0;i<h;i++)
    {
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: \n",i+2);
        scanf("%d",&newnode->data);
        temp->next=newnode;
        newnode->next=NULL;
        temp=temp->next;
    }
}

void traverseNode(struct node* ptr){
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}


int main(){
    struct node * head = (struct node*)malloc(sizeof(struct node));
    printf("Enter number of nodes to be added \n");
    int n; scanf("%d",&n);
    printf("Enter data for node 1 \n");
    scanf("%d",&head->data);
    head->next=NULL;    
    createNode(head,n-1);
    printf("\nRequired Linked List : \n");
    traverseNode(head);
}