/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*/

class Solution {
public:
  void findWords(const string &s, int beg, unordered_set<string>& wordDict, vector<bool>& dp, string str, vector<string>& res) {
    if(beg == s.size()){
      res.push_back(str.substr(0, str.size() - 1));
      return;
    }    
    for(int i = beg+1; i <= s.size(); i++) {
      if(dp[i] && wordDict.find(s.substr(beg, i - beg)) != wordDict.end())
	findWords(s, i, wordDict, dp, str + s.substr(beg, i - beg) + " ", res);
    }
  }
    
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> res;
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
        
    for(int i = 1; i <= s.size(); i++) {
      for(int j = i-1; j >= 0 && !dp[i]; j--) {
	dp[i] = dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end();
      }
    }
    if(!dp[s.size()])
      return res;
    findWords(s, 0, wordDict, dp, "", res);
    return res;
  }
};

//DP + DFS solution
