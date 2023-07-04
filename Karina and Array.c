#include<stdio.h>
int max(int a,int b){
 return a>b ? a:b;
}

int karina(int* a,int n){
 int prod,maxim=0;
 for(int i=0;i<n-1;i++){
  prod=a[i]*a[i+1];
  maxim=max(maxim,prod);
 }
 return maxim;
}
int main(){
int n;
 printf("Enter the size of array ");
 scanf("%d",&n);
 int a[n];
 for(int i=0;i<n;i++){
  printf("Enter a number ");
  scanf("%d",&a[i]);
 }
 
 printf("\nThe beaty of the array is %d ",karina(a,n));
 return 0;
}