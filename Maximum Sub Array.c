#include <stdio.h>
#include<stdbool.h>

bool isPositive(int* a,int n){
 for(int i=0;i<n;i++){
  if(a[i]<0) {
   return false;
   break;
  }
 }
 return true;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void maxSubArray(int* nums, int numsSize) {
  if(isPositive(nums,numsSize)){
  int sum=0;
  printf("The maximum sub array is \n");
  for(int i=0;i<numsSize;i++){
   printf(" %d ",nums[i]);
   sum+=nums[i];
  }
  printf("\nThe maximum sum of this sub array is %d",sum);
 }else{
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;
    
    for (int i = 1; i < numsSize; i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        
        if (currentSum == nums[i])
            tempStart = i;
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    printf("The maximum subarray is:\n");
    for (int i = start; i <= end; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\nThe maximum sum of this subarray is %d\n", maxSum);
}

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
  maxSubArray(a,n);
 return 0;
}