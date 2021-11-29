#include<stdio.h>
int check(int a[],int e){
if(e==1)
return a[e-1];

if(a[e-1]<check(a,e-1)){
return a[e-1];
}

}

int main(){
  printf("Enter number of elements in array\n");
  int n; scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    printf("Enter element %d : ",(i+1));
    scanf("%d",&a[i]);
  }
  int l = check(a,n);
  printf("Largest element is : %d",l);
}