#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stack>
#include<ctype.h>

using namespace std;

void printCombination(string s, int start, int end, vector<string> &res) {
  if(start == end) {
    res.push_back(s);
    return;
  }
  
  s[start] = toupper(s[start]);
  printCombination(s, start+1, end, res);
  
  s[start] = tolower(s[start]);
  printCombination(s, start+1, end, res);
}

int main(){
  string str = "abc";
  int len = str.size();
  vector<string> res; 
  printCombination(str, 0, len, res);
  
  for(int i = 0; i < (int)res.size(); i++)
    cout << res[i] << "\t";
  
  cout << endl;
  
  return 0;
}
