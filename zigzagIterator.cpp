/* Leet Code 281
Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Technique:
==========
Use Queue of pairs. Make Pair of the iterator begin and end and push it to the queue. end() in vector return iterator the last i.e. 0
For our example:

Queue Initially:
Q = (1, 0), (3, 0) -- 1 and 3 iterator to 1st element and iterator to end is 0

Start:
Print 1
Q = (3, 0), (2, 0)
Print 3
Q = (2, 0), (4, 0)
Print 2 -- no more elements in vector 1
Q = (4, 0)
Print 4
Q = (5, 0)
Print 5
Q = (6, 0)
Print 6
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

using namespace std;

int main(){
  vector<int> v1 {1, 2};
  vector<int> v2 {3, 4, 5, 6};
  
  queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
  
  if(v1.size() != 0)
    Q.push(make_pair(v1.begin(), v1.end()));
  if(v2.size() != 0)
    Q.push(make_pair(v2.begin(), v2.end()));

  while(!Q.empty()){
    vector<int>::iterator it = Q.front().first;
    vector<int>::iterator endit = Q.front().second;
    
    Q.pop();
    
    if(it+1 != endit)
      Q.push(make_pair(it+1, endit));
    
    cout << *it << " ";
  }
  cout << endl;
  
  return 0;
}
