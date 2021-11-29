#include<stdlib.h>
#include<stdio.h>
struct node{
  int data;
  struct node *link;
};
struct node *top=NULL;

int push(int x){
struct node *new=(struct node*)malloc(sizeof(struct node));
new->data=x;
new->link=top;
top=new;
}
void pop(){
  struct node* new;
  new->link=top->link;
  top=top->link;
  free(new);
}
void isEmpty(){
  if(top==NULL){
    printf("Stack is empty\n");
  }
  else{
    printf("Stack is not empty\n");
  }
}
void peek(){
  printf("Top element of the stack is %d\n",top->data);
}

void show(){
while(top!=NULL){
printf("%d ",top->data);
top=top->link;
}
}

int main(){
  printf("Enter number of elements in stack\n");
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Enter value %d in stack : \n",(i+1));
    int x;scanf("%d",&x);
    push(x);
  }
  pop();
  push(50);
  isEmpty();
  peek();
  show();
}