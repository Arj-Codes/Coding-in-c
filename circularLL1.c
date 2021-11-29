#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node *start,*s;

void enterElement(struct node** head,struct node **s,int val)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    struct node* temp=(*head);
    new->data=val;
    if((*s)->next==NULL)
    {
        (*s)->next=new;
        (*head)=new;  

    }
    else
    {
        while(temp->next!=(*head))
        {
        temp=temp->next;
        }
        temp->next=new;            
    }
    new->next=(*head);
}

void traverse(struct node** head,struct node **s)
{
    struct node *temp=*head;
    printf("The entered circular LL is : \n");
    do
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }while(temp!=(*head));    
   
}

void enterFirst(struct node**head,struct node **s,int val)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if((*s)->next==NULL)
    {
         (*head)=new;
         (*s)->next=new;
    }
    else{
     new->next=(*head);
     (*s)->next=new;
     (*head)=new;
    }
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    printf("Enter number of nodes \n");
    int n;scanf("%d",&n);
    s=(struct node*)malloc(sizeof(struct node));
    s->next=NULL;
    s->data=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter data in node %d\n",(i+1));
        int v;scanf("%d",&v);
        enterElement(&start,&s,v);
    }
    
    traverse(&start,&s);
    printf("After function applied\n");
    enterFirst(&start,&s,100);
    traverse(&start,&s);
    return 0;
}
