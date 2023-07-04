#include <stdio.h>

void longestIncreasingSubArray(int* nums, int numsSize) {
    int maxLength = 1; // Minimum length is 1
    int maxStart = 0;
    int maxEnd = 0;
    
    int start = 0;
    int end = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            start = i;
            end = i + 1;
            
            // Extend the increasing subarray until the sequence breaks
            while (end < numsSize - 1 && nums[end] < nums[end + 1]) {
                end++;
            }
            
            // Calculate the length of the current subarray
            int length = end - start + 1;
            
            // Update the longest subarray if necessary
            if (length > maxLength) {
                maxLength = length;
                maxStart = start;
                maxEnd = end;
            }
        }
    }
    
    printf("The longest increasing subarray is:\n");
    for (int i = maxStart; i <= maxEnd; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\nThe length of this subarray is %d\n", maxLength);
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
  longestIncreasingSubArray(a,n);
 return 0;
}