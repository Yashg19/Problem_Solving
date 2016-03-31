/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
  int numSquares(int n) {
    /*
        if(n <= 0)
            return 0;
    */    
    //int *dp = new int[n+1];
    //for better performance saving calculated results using static vector and initializing it with 0
    //Reference: https://leetcode.com/discuss/82781/recommend-beginners-implementation-detailed-explanation
    static vector<int> dp({0});
    if(dp.size() >= n+1)
      return dp[n];
        
    //for(int i = 1; i <= n; i++) {
    for(int i = dp.size(); i <=n; i++) {
      int temp = INT_MAX;
      for(int j = 1; j * j <= i; j++) {
	temp = min(temp, dp[i-j*j] + 1);    
      }
      dp.push_back(temp);
    }
    return dp[n];
  }
};
