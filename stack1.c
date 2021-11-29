#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *top=NULL;

void push(int x){
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->data=x;
  new->link=top;
  top=new;
}

void pop(){
struct node* new;
if(top==NULL)
printf("nothing to pop from");
new=top;
top=top->link;
free(new);
}

void show(){
  while(top!=NULL){
    printf("%d\n",top->data);
    top=top->link;
  }
}

int main(){
  printf("Enter number of elements in stack\n");
  int n,x; scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Enter element %d : ",(i+1));
    scanf("%d",&x); 
    push(x);
  }
  pop();
  push(5);
  show();
  return 0;
}