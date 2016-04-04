/* Leet Code: 76: Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#define MAX_NO_CHAR 256

class Solution {
public:
  string minWindow(string s, string t) {
    int m = s.size();
    int n = t.size();
    int hash[MAX_NO_CHAR] = {0};
        
    int len = 0, min_len = -1, start = 0, min_start, valid_len = 0;
        
    for(int i = 0; i < n; i++)
      hash[t[i]]++;
            
    for(int i = 0; i < m; i++) {
      if(hash[s[i]] > 0)
	valid_len++;
      hash[s[i]]--;
      len++;
            
      while(hash[s[start]] < 0) {
	hash[s[start]]++;
	start++;
	len--;
      }
            
      if(valid_len == n && (min_len == -1 || len < min_len)) {
	min_len = len;
	min_start = start;
      }
    }
        
    if(valid_len < n)
      return "";
            
    return s.substr(min_start, min_len);
  }
};
