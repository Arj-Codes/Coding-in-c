#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* start=NULL;
int count;
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

int traverse(struct node **head){
    count=0;
    struct node* temp = *head;
    printf("Required Linked List : \n");
    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
        count++;
    }
    return count;
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



int main(){
    printf("Enter number of nodes \n");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d \n",i+1);
        int v;scanf("%d",&v);
        enterElement(&start,v);
    }
    int l = traverse(&start);
    if(l%2!=0)
    {
        enterPos(&start,100,((l+1)/2));
    }
    else{
        enterPos(&start,100,((l/2)+1));
    }
    int m = traverse(&start);
}