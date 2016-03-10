/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

class Solution {

public:

  static bool compare(string a, string b) {
    return a+b > b+a;
  }

  string largestNumber(vector<int>& nums) {
    string res = "";

    if(nums.size() == 0)
      return res;
        
    vector<string> r;
    for(int i = 0; i < nums.size(); i++)
      r.push_back(to_string(nums[i]));
        
    sort(r.begin(), r.end(), compare);
        
    vector<string>::iterator it;
        
    for(it = r.begin(); it != r.end(); it++)
      res += *it;

    //for example if input is 00000 then output should be just 0
    while(res[0] == '0' && res.length() > 1)
      res.erase(0, 1);
        
    return res;
  }
};
