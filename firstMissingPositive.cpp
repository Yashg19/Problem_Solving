/*
LeetCode: 41: Find First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int seperatePosNeg(int *nums, int numsSize) {
  int i, j = 0;
  for(i = 0; i < numsSize; i++) {
    if(nums[i] <= 0) {
      swap(&nums[i], &nums[j]);
      j++;
    }
  }
  return j;
}

int findMissingPos(int *nums, int numsSize) {
  int i;
  for(i = 0; i < numsSize; i++) {
    if( abs(nums[i]) - 1 < numsSize && nums[abs(nums[i]) - 1] > 0 )
      nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
  }
    
  for(i = 0; i < numsSize; i++) {
    if(nums[i] > 0)
      return i+1;
  }
  return numsSize + 1;
}

int firstMissingPositive(int* nums, int numsSize) {
  int positiveArr = seperatePosNeg(nums, numsSize);   
  int ans = findMissingPos(nums + positiveArr, numsSize - positiveArr);
  return ans;
}
