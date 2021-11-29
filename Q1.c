//QUEUE
#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int size;
  int f,r;
  int *arr;
};
int isFull(struct queue *q){
if(q->r==(q->size-1)){
return 1;
}
  return 0;
}

int isEmpty(struct queue* q){
if(q->f==q->r){
return 1;
}
return 0;
}

void enqueue(struct queue* q,int val)
{
  if(isFull(q)){
   printf("Queue Overflow");
  }
  else{
   q->r=q->r+1;//q->r++
   q->arr[q->r]=val; 
   printf("Enqueued value : %d\n",val);
  }
}

int dequeu(struct queue *q)
{
  if(isEmpty(q)){
   printf("Queue Underflow");
  }
  else{
   q->f++;
   return q->arr[q->f];
  }
  return -1;
}

int main() 
{
  struct queue* q=(struct queue*)malloc(sizeof(struct queue));
q->size=10;
q->f=q->r=-1;
q->arr=(int *)malloc(q->size*sizeof(int));
  enqueue(q,10);
  enqueue(q,20);
  enqueue(q,30);
  enqueue(q,40);
  enqueue(q,50);
  enqueue(q,60);
  printf("Dequeueing value : %d\n",dequeu(q));
  printf("Dequeueing value : %d\n",dequeu(q));
  printf("Dequeueing value : %d\n",dequeu(q));
  printf("Dequeueing value : %d\n",dequeu(q));
  printf("Dequeueing value : %d\n",dequeu(q));
  printf("Dequeueing value : %d\n",dequeu(q));
  enqueue(q,70);
  return 0;
}