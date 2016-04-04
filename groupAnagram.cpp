/*
LeetCode: 49 Group Anagrams

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

*/

class Solution {
public:
  map<string, int> mp;
  static bool compare(string s1, string s2) {
    return s1 < s2;
  }
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    mp.clear();
    sort(strs.begin(), strs.end(), compare);
        
    vector<string> grp;
    vector<vector<string>> res;
    res.clear();
    int idx = 0;
        
    for(int i = 0; i < strs.size(); i++) {
      grp.clear();
      string temp = strs[i];
      sort(temp.begin(), temp.end());
            
      if(mp[temp] == 0) {
	mp[temp] = ++idx;
	grp.push_back(strs[i]);
	res.push_back(grp);
      }
      else {
	res[mp[temp] - 1].push_back(strs[i]);
      }
    }
    return res;
  }
};
