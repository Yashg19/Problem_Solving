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

using namespace std;

bool compare(pair<string, int> f1, pair<string, int> f2) {
  return f2.second > f1.second;
}

int main() {
  
  unordered_map<string, int> hm;
  
  hm["xyz"] = 11;
  hm["abc"] = 2;
  hm["qrs"] = 12;
  hm["mno"] = 40;
  hm["def"] = 5;
  
  unordered_map<string, int>::iterator it;
  
  for(it = hm.begin(); it != hm.end(); it++)
    cout << it->first << " " << it->second << endl;
  
  cout << "Sorted by values" << endl;
  
  vector<pair<string,int>> myvec(hm.begin(), hm.end());
  
  sort(myvec.begin(), myvec.end(), compare);
  
  for(unsigned int i = 0; i < myvec.size(); i++)
    cout << myvec[i].first << " " << myvec[i].second << endl;
  cout << endl;
    
  return 0;
}
