/*
GeeksforGeeks: http://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
LeetCode: 340

Time Complexity: O(n)
Space Complexity: constant

Idea is to maintain a window of size k (unique chars) and if number of unique elements exceed k then start removing elements from left.
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<map>
#include<unordered_map>
#include<algorithm>
#include <utility>
#include <string>
#include <complex>
#include <tuple>
#include<stdbool.h>
#include<queue>
#include<string.h>

#define MAX_CHAR 26

using namespace std;

bool isValid(int count[], int k) {
  int val = 0;
  for(int i = 0; i < MAX_CHAR; i++)
    if(count[i] > 0)
      val++;
  
  return (k >= val);
}

void kunique(string s, int k) {
  int n = s.size();
  int count[MAX_CHAR], u = 0;
  memset(count, 0, sizeof(count));
  
  for(int i = 0; i < n; i++) {
    if(count[s[i] - 'a'] == 0)
      u++;
    count[s[i]-'a']++;
  }
  
  if(u < k) {
    cout << "Not enough unique characters\n";
    return;
  }
  
  
  memset(count, 0, sizeof(count));
  
  count[s[0] - 'a']++;
  int curr_end = 0, curr_start = 0, max_window_size = 1, max_window_start = 0;
  
  for(int i = 1; i < n; i++) {
    count[s[i] - 'a']++;
    curr_end++;
    
    while(!isValid(count, k)){
      count[s[curr_start] - 'a']--;
      curr_start++;
    }
    
    if(curr_end - curr_start + 1 > max_window_size) {
      max_window_size = curr_end - curr_start + 1;
      max_window_start = curr_start;
    }
  }
  
  cout << "Max Length Substring with k unique char: " << s.substr(max_window_start, max_window_size) << endl;
  cout << "Max Length = " << max_window_size << endl;
}

//Main -- sample string
int main() {
  string str = "aabacbebebe";
  int k = 3;
  kunique(str, k);
  
  return 0;
}
