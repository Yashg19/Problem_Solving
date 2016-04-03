/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

class Solution {
public:
  void dfs(vector<string> &result, const string &num, const int target, string cur, int pos, const long cv, const long pv, const char op){
    if(pos == num.size() && cv == target)
      result.push_back(cur);
    else {
      for(int i = pos+1; i <= num.size(); i++) {
	string temp = num.substr(pos, i-pos);
	long now = stol(temp);
	if(to_string(now).size() != temp.size())
	  continue;
	dfs(result, num, target, cur+'+'+temp, i, cv+now, now, '+');
	dfs(result, num, target, cur+'-'+temp, i, cv-now, now, '-');
	dfs(result, num, target, cur+'*'+temp, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
      }
    }
  }

  vector<string> addOperators(string num, int target) {
    vector<string> result;
    if(num.empty())
      return result;
    for(int i = 1; i <= num.size(); i++) {
      string s = num.substr(0, i);
      long cur_num = stol(s);
      if(to_string(cur_num).size() != s.size())
	continue;
      dfs(result, num, target, s, i, cur_num, cur_num, '#');
    }
    return result;
  }
};
//DFS solution -- Time Complexity == 4 to the power(n-1) -- consider input 0000..0 and target 0 -- 4 to the power (n-1) output 
