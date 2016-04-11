#include<iostream>
#include<string.h>
#include<string>
#include<stdlib.h>

using namespace std;

class TrieNode{
public:
  bool hasValue;
  int data;
  TrieNode** child;
  
  TrieNode(){
    hasValue = false;
    data = 0;
    child = new TrieNode*[26]();
  }
};

class Trie{
public:
  Trie(){
    root = new TrieNode();
    count = 0;
  }
  
  void insert(string word) {
    count++;
    TrieNode* node = getNode(word, true);
    node->hasValue = true;
    node->data = count;
  }
  
  bool search(string word) {
    TrieNode* res = getNode(word, false);
    return (res != NULL && res->hasValue);
  }
  
  bool startsWith(string prefix) {
    return (getNode(prefix, false) != NULL);
  }
  
  string prefixMatch(string key) {
    return prefixM(key);
  }
  
private:
  TrieNode* root;
  int count;
  
  //Function used in insert/search and startWith
  TrieNode* getNode(string word, bool create) {
    int len = word.size();
    TrieNode* temp = root;
    for(int level = 0; level < len; level++) {
      int index = word[level] - 'a';
      if(temp->child[index] == NULL) {
	if(create)
	  temp->child[index] = new TrieNode();
	else
	  return NULL;
      }
      temp = temp->child[index];
    }
    return temp;    
  }  
  
  //Function to print the longest prefix of given key
  string prefixM(string key) {
    int l = key.size();
    string s = "";
    int prevMatch = 0;
    TrieNode* t = root;
    for(int level = 0; level < l; level++) {
      int index = key[level] - 'a';
      if(t->child[index]) {
	s += key[level];
	t = t->child[index];
	if(t->data)
	  prevMatch = level + 1;
      }
      else
	break;
    }
      
    if(!t->data)
      return s.substr(0, prevMatch);
    else
      return s;
  }
  
};

int main(){
  Trie trie;
  trie.insert("are");
  trie.insert("area");
  trie.insert("base");
  trie.insert("cat");
  trie.insert("cater");
  trie.insert("children");
  trie.insert("basement");
  
  cout << trie.prefixMatch("caterer") << endl;
  cout << trie.prefixMatch("basemexy") << endl;
  cout << trie.prefixMatch("child") << endl;
  
  cout << trie.startsWith("child") << endl;
  
  return 0;
}
