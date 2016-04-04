/* 
LeetCode: 33 Search In rotated sorted array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

int search(int* nums, int numsSize, int target) {
  if(numsSize == 0)
    return -1;
        
  if(numsSize == 1 && target == nums[0])
    return 0;
    
  int low = 0;
  int high = numsSize - 1;
    
  while (low < high) {
    //printf("low = %d and high = %d\n", low, high);
    if(nums[low] == target)
      return low;
        
    if(nums[high] == target)
      return high;
        
    int mid = (low + high) / 2;
    //printf("mid value = %d\n", mid);
        
    if(nums[mid] == target)
      return mid;
        
    if(nums[mid] <= nums[high]) {
      if(target > nums[mid] && target <= nums[high])
	low = mid + 1;
      else
	high = mid - 1;
    }
    else {
      if (target >= nums[low] && target < nums[mid])
	high = mid - 1;
      else
	low  = mid + 1;
    }
  }
    
  return -1;
}
