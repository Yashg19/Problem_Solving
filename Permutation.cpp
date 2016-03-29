/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void permuteUtil(vector<int> &nums, int l, int r, vector<vector<int>> &re, vector<int> &temp) {
    if(l == r) {
      for(unsigned int i = 0; i < nums.size(); i++)
	temp.push_back(nums[i]);
      re.push_back(temp);
      temp.clear();
      return;
    }
    else {
      for(int j = l; j <= r; j++) {
	swap(&nums[l], &nums[j]);
	permuteUtil(nums, l+1, r, re, temp);
	swap(&nums[l], &nums[j]);
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() == 0)
      return result;
    vector<int> temp;
    permuteUtil(nums, 0, nums.size() - 1, result, temp);
    return result;
  }
};
