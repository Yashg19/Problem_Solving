/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    int m = s.length();
    int n = m;
    bool dp[m][n];
        
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
	dp[i][j] = false;
                
        
    for(int l = 1; l <= m; l++) {
      for(int i = 0; i <= m-l; i++) {
	int j = i+l-1;
	string temp = s.substr(i, l);
	if(wordDict.count(temp) > 0) {
	  dp[i][j] = true;
	  continue;
	}
	for(int k = i+1; k <= j; k++) {
	  if(dp[i][k-1] && dp[k][j]) {
	    dp[i][j] = true;
	    break;
	  }
	}
      }
    }
    return dp[0][m-1];  
  }
};
