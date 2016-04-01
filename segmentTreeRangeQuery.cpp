#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>

using namespace std;

int min(int a, int b){
  return (a < b) ? a : b;
}

void constructTree(vector<int> &input, vector<int> &segTree, int low, int high, int pos) {
  if(low == high){
    segTree[pos] = input[low];
    return;
  }
  
  int mid = (low + high) / 2;
  constructTree(input, segTree, low, mid, 2 * pos + 1);
  constructTree(input, segTree, mid+1, high, 2 * pos + 2);
  segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);
}

int rangeQuery(vector<int> &segTree, int qlow, int qhigh, int low, int high, int pos) {
  
  if(qlow <= low && qhigh >= high)
    return segTree[pos];
  if(qlow > high || qhigh < low)
    return INT_MAX;
  int mid = (low + high)/2;
  return min(rangeQuery(segTree, qlow, qhigh, low, mid, 2*pos+1),
             rangeQuery(segTree, qlow, qhigh, mid+1, high, 2*pos+2));
}

int main() {
  vector<int> input {-1, 2, 4, 0};
  int len = input.size();
  cout << "len = " << len << endl;
  vector<int> segTree (len*2 - 1);
  
  constructTree(input, segTree, 0, len-1, 0);
  
  for(unsigned int i = 0; i < segTree.size(); i++)
    cout << segTree[i] << " ";
  cout << endl;
  
  cout << "Result = " << rangeQuery(segTree, 0, 3, 0, 7, 0);
  
  return 0;
}
