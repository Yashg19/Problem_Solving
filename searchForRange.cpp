/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    
  int searchRangeUtil(vector<int> &nums, int target, int flag) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while(left <= right) {
      int mid = (left + right) / 2;
      if(nums[mid] == target) {
	ans = mid;
	if(flag == 0)
	  right = mid - 1;
	else
	  left = mid + 1;
      }
      else if(nums[mid] > target)
	right = mid - 1;
      else
	left  = mid + 1;
    }
    return ans;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    if(nums.size() == 0) {
      res.push_back(-1);
      res.push_back(-1);
    }    
        
    int first = searchRangeUtil(nums, target, 0);
    int second = searchRangeUtil(nums, target, 1);
        
    res.push_back(first);
    res.push_back(second);
        
    return res;
  }
};
