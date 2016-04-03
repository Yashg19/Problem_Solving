/* Leet Code Problem 287

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Idea:
====

The idea is to use Binary Search and do it in Time Complexity: nlogn

*/

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1, l = 1;
    int h = n;
    int mid, count;
    while(l < h) {
      count = 0;
      mid = (l + h)/2;
      for(int i = 0; i <= n; i++) {
	if(nums[i] <= mid)
	  count++;
      }
      if(count > mid)
	h = mid;
      else
	l = mid+1;
    }
    return l;
  }
};

