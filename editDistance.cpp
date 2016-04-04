/*

Leet Code: 72

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/

class Solution {
public:
  int minF(int x, int y, int z) {
    return min(min(x, y), z);
  }
  int minDistanceUtil(string word1, string word2, int m, int n) {
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++) {
      for(int j = 0; j <= n; j++) {
	if(i == 0)
	  dp[i][j] = j;
	else if(j == 0)
	  dp[i][j] = i;
	else if(word1[i-1] == word2[j-1])
	  dp[i][j] = dp[i-1][j-1];
	else
	  dp[i][j] = 1 + minF(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
      }
    }
    return dp[m][n];
  }
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
        
    int res = minDistanceUtil(word1, word2, m, n);
        
    return res;
  }
};
