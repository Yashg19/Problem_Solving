/*
LeetCode: 153:

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

int findMin_Bsearch(int* a, int low, int high)
{
  while(low < high)
    {
      if(a[low] < a[high])
	return a[0];
        
      int mid = (low + high)/2;
        
      if( (a[mid] < a[mid+1]) && (a[mid] < a[mid-1]) )
	return a[mid];
            
      if(a[mid] > a[mid+1])
	return a[mid+1];
        
      if(a[mid] < a[low])
	high = mid-1;
      else
	low = mid + 1;
    }
  return -9999;
}

int findMin(int* nums, int numsSize) {
  if(numsSize == 1)
    return nums[0];
  if(numsSize == 0)
    return 0;
        
  int min = findMin_Bsearch(nums, 0, numsSize - 1);
    
  return min;
    
}
