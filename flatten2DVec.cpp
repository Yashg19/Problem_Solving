/* LeetCode - 251

Leetcode: Flatten 2D Vector
Implement an iterator to flatten a 2d vector.
For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
Hint:
How many variables do you need to keep track?
Two variables is all you need. Try with x and y.
Beware of empty rows. It could be the first few rows.
To write correct code, think about the invariant to maintain. What is it?
The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
Not sure? Think about how you would implement hasNext(). Which is more complex?
Common logic in two different places should be refactored into a common method.
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

#define MAX_CHAR 256

using namespace std;

unsigned int row = 0, col = 0;

bool hasNext(vector<vector<int>> &vec) {
  while(row < vec.size() && vec[row].size() == col){
    row++;
    col = 0;
  }
  return row < vec.size();
}

int next(vector<vector<int>> &vec) {
  return vec[row][col++];
}

//Example to flatten 2 D array

int main() {
  vector<vector<int>> vec;
  vector<int> arr {1, 2, 3};
  vec.push_back(arr);
  vector<int> arr1 {4};
  vec.push_back(arr1);
  vector<int> arr2 {};
  vec.push_back(arr2);
  vector<int> arr3 {5, 6, 7, 8, 9};
  vec.push_back(arr3);
  
  while(hasNext(vec) == true)
    cout << next(vec) << " ";
  
  cout << endl;

  return 0;
}
