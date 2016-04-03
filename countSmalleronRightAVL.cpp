/*
Count Smaller Elements on the right side in an array --> http://www.geeksforgeeks.org/count-smaller-elements-on-right-side/

The same code can be used for finding total count of inversion in an array -- http://www.geeksforgeeks.org/count-inversions-in-an-array-set-2-using-self-balancing-bst/
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.

    Two elements a[i] and a[j] form an inversion if 
     a[i] > a[j] and i < j. For simplicity, we may 
     assume that all elements are unique.

     Example:
     Input:  arr[] = {8, 4, 2, 1}
     Output: 6
     Given array has six inversions (8,4), (4,2),
     (8,2), (8,1), (4,1), (2,1).     

If we go with the naive approach -- we can find that in a O(n*n) time complexity

Better Approach: AVL Trees -- Time complexity - O(nlogn), Space Complexity - O(n) to store answers

Little Background on AVL Trees:
==============================

AVL Trees - balanced binary search tree
   --- Worst case Insertion, Deletion, Search -- O(logn)

AVL Trees --  most important points

1. left-left   - In case of left-left all we have to do is right Rotate

2. left-right  - First we do left rotate and then we do right rotate

3. right-right - LeftRotate

4. right-left  - Right Rotate -- and then finally LEFTRotate
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

struct node{
  int data;
  struct node* left;
  struct node* right;
  int height;
  int size;
};

int height(struct node* n) {
  if(n == NULL)
    return 0;
  return n->height;
}

int size(struct node* n) {
  if(n == NULL)
    return 0;
  return n->size;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

struct node* newNode(int data) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  temp->height = temp->size = 1;
  return temp;
}

int getBalance(struct node* n) {
  if(n == NULL)
    return 0;
  return height(n->left) - height(n->right);
}

//Right Rotate
struct node* rightRotate(struct node* n) {
  struct node* newHead = n->left;
  struct node* t = newHead->right;
  
  //Rotation
  newHead->right = n;
  n->left = t;
  
  n->height = max(height(n->left), height(n->right)) + 1;
  newHead->height = max(height(newHead->left), height(newHead->right)) + 1;
  
  n->size = max(size(n->left), size(n->right)) + 1;
  newHead->size = max(size(newHead->left), size(newHead->right)) + 1;
  
  return newHead;
}

//Left Rotate
struct node* leftRotate(struct node* n) {
  struct node* newHead = n->right;
  struct node* t = newHead->left;
  
  //Rotation
  newHead->left = n;
  n->right = t;
  
  n->height = max(height(n->left), height(n->right)) + 1;
  newHead->height = max(height(newHead->left), height(newHead->right)) + 1;
  
  n->size = max(size(n->left), size(n->right)) + 1;
  newHead->size = max(size(newHead->left), size(newHead->right)) + 1;
  
  return newHead;
}


struct node* insert(struct node* n, int data, int *res) {
  if(n == NULL)
    return newNode(data);
  
  if(data < n->data)
    n->left = insert(n->left, data, res);
  else {
    n->right = insert(n->right, data, res);
    *res = *res + size(n->left) + 1;
  }
  
  n->height = max(height(n->left), height(n->right)) + 1;
  n->size = max(size(n->left), size(n->right)) + 1;
  
  int balance = getBalance(n);
  
  //Checking for left left case
  if(balance > 1 && data < n->left->data)
    return rightRotate(n);
  
  //Checking for left-right case
  if(balance > 1 && data > n->left->data) {
    n->left = leftRotate(n->left);
    return rightRotate(n);
  }
  
  //checking for right right case
  if(balance < 1 && data > n->right->data)
    return leftRotate(n);
   
  //checking for right left case
  if(balance < 1 && data < n->right->data){
    n->right = rightRotate(n->right);
    return leftRotate(n);
  }
  
  return n;
}

void constructAVLTree(int a[], int n, int *res) {
  struct node* root = NULL;
  
  //initializing the result array with 0
  for(int i = 0; i < n; i++)
    res[i] = 0;
  
  for(int i = n-1; i >= 0; i--)
    root = insert(root, a[i], &res[i]);
}

void printAns(int arr[], int n) {
  cout << "Following is the result: count of number smaller on right\n";
  for(int i = 0; i < n; i++)
    cout << arr[i] << " " ;
  cout << endl;
}

int main() {
  int input[] = {10, 6, 15, 20, 30, 5, 7};
  int size = sizeof(input)/sizeof(input[0]);
  
  int *countSmaller = (int*)malloc(sizeof(int) * size);
  
  constructAVLTree(input, size, countSmaller);
  
  printAns(countSmaller, size);
  
  return 0;
}
