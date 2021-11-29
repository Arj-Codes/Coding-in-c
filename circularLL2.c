#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node* start;
struct node* s;
void enterElement(struct node** head,struct node** s,int v)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node* temp=*head;
    new->data=v;
    if((*s)->next==NULL)
    {
        ((*s)->next)=new;
        (*head)=new;
    }
    else{
        while(temp->next!=(*head))
        temp=temp->next;
        temp->next=new;
    }
    new->next=(*head);
}

void traverse(struct node** head)
{
    struct node* temp=*head;
    printf("Linked List before function :\n");
        do{
            printf("%d\n",temp->data);
            temp=temp->next;
        }while(temp!=(*head));
}

void enterFirst(struct node** head,struct node** s,int val)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=val;    
    new->next=*head;
    (*s)->next=new;
    (*head)=new;
}

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number of elements\n");
    int n;scanf("%d",&n);
    s->next=NULL;
    s->data=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d\n",(i+1));
        int val;scanf("%d",&val);
        enterElement(&start,&s,val);
    }
    traverse(&start);
    printf("\n LL after function\n");
    enterFirst(&start,&s,100);
    traverse(&start);
    return 0;
}