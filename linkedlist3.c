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

struct node* deletefromfirst(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;    
}
struct node* deleteinbetween(struct node *head,int index){
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }    
    struct node * ptr=p->next;
    p->next=ptr->next;
    free(ptr);
    return head;    
}

struct node* deleteatend(struct node *head){
    struct node *p=head;
    struct node *ptr=p->next;
    while(ptr->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    p->next=NULL;
    free(ptr);
    return head;    
}

struct node* deleteatkey(struct node *head,int val){
    struct node *q=head;
    if(q->data==val){
        head=head->next;
        free(q);
    }
    else{
        struct node *p=head;
        struct node *ptr=head->next;
            while(ptr->data!=val && ptr->next!=NULL){
                ptr=ptr->next;
                p=p->next;
            }
            if(ptr->data==val){
                p->next=ptr->next;
                free(ptr);
            }
            else{
                printf("Element not Found \n");
            }
    }
    return head;
}


int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;
    
    printf("Before deletion : \n");
    traverse(head);

    printf("\nAfter deletion :\n");
    //head = deletefromfirst(head);
    //head=deleteinbetween(head,2);
    //head=deleteatend(head);
    head=deleteatkey(head,40);
    traverse(head);
    return 0;
}