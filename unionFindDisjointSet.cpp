/* Union Find algorithm on Disjoint Set
   Time Complexity -- O(m alpha(n)) -- alpha(n) <= 4 so -- > O(m) --> m operations and n is number of elements
   Space Complexity: -- O(n) -- n elements
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

using namespace std;

struct node {
  long data;
  struct node* parent;
  int rank;
};

map<long, node*> mp;

void makeSet(long data) {
  struct node* n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->parent = n;
  n->rank = 0;
  mp[data] = n;
}

struct node* findS(struct node* t) {
  struct node* parent = t->parent;
  if(parent == t)
    return parent;
  t->parent = findS(t->parent);
  return t->parent;
} 

long findSet(long data) {
  struct node* temp =  mp.find(data)->second;
  return findS(temp)->data;
}

bool unionAlgo(long data1, long data2) {
  struct node* n1 = mp.find(data1)->second;
  struct node* n2 = mp.find(data2)->second;
  
  struct node* p1 = findS(n1);
  struct node* p2 = findS(n2);
  
  if(p1->data == p2->data)
    return false;
  
  if(p1->rank >= p2->rank) {
    p1->rank = (p1->rank == p2->rank) ? p1->rank + 1 : p1->rank;
    p2->parent = p1;
  }
  else {
    p1->parent = p2;
  }
  return true;
}

int main() {
  makeSet(1);
  makeSet(2);
  makeSet(3);
  makeSet(4);
  makeSet(5);
  makeSet(6);
  makeSet(7);
  
  unionAlgo(1, 2);
  unionAlgo(2, 3);
  unionAlgo(4, 5);
  unionAlgo(6, 7);
  unionAlgo(5, 6);
  unionAlgo(3, 7);
  
  cout << findSet(1) << endl;
  cout << findSet(2) << endl;
  cout << findSet(3) << endl;
  cout << findSet(4) << endl;
  cout << findSet(5) << endl;
  cout << findSet(6) << endl;
  cout << findSet(7) << endl;
  
  return 0;
  
}

