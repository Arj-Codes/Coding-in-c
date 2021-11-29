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
void reverse(struct node **head){
    struct node* temp = *head;
    struct node* temp1=(*head)->next;
    while(temp1!=NULL){
        temp=temp->next;
        temp1=temp1->next;
    }
    printf("%d \n",temp->data);
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

int main(){
    printf("Enter number of nodes \n");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d \n",i+1);
        int v;scanf("%d",&v);
        enterElement(&start,v);
    }    
    traverse(&start);
    printf("\nReversed Linked List : \n");
    for(int x=0;x<n;x++){
        reverse(&start);
        deleteLast(&start);
    }
}