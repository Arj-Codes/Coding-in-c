#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *link;
};
struct node *top=NULL;

void push(int x){

//if(top==NULL){
//top->data=x;
//top->link=NULL;
//}

//else{
struct node *new = (struct node*)malloc(sizeof(struct node));
new->data=x;
new->link=top->link;
top=new;
//}
}
void show(){
  int i=1;
  while(top!=NULL){
    printf("Element %d of stack is %d : ",i,top->data);
    printf("\n");
    i++;
    top=top->link;// this is to check
  }
}

int main(){
printf("Enter number of elements in the stack \n");
int n; scanf("%d",&n);int x;
for(int i=0;i<n;i++){
printf("Enter element %d\n",(i+1));
int x;scanf("%d",&x);
push(x);
}
show();
return 0;
}