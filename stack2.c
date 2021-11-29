#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  int data;
  struct node *link;
};
struct node *top=NULL;

void push(char x){
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
    printf("%c",top->data);
    top=top->link;
  }
}

int main(){
  printf("Enter a string\n");
  char x[100];
  gets(x);
  //fgets(x,100,stdin); 
  //scanf("%[^\n]%*c",x); 
  int l = strlen(x);
  for(int i=0;i<l;i++){
    push(x[i]);
  }
  show();
  return 0;
}