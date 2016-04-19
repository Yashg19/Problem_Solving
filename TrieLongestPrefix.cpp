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
  
  //function to insert the given word or vector of strings input into the Trie data structure
  void insert(string word) {
    count++;
    TrieNode* node = getNode(word, true);
    node->hasValue = true;
    node->data = count;
  }
  
  //search if the word exist in the key or not
  bool search(string word) {
    TrieNode* res = getNode(word, false);
    return (res != NULL && res->hasValue);
  }
  
  //check if there is an input in the trie that starts with a given key
  bool startsWith(string prefix) {
    return (getNode(prefix, false) != NULL);
  }
  
  //longest common prefix given a key
  string prefixMatch(string key) {
    return prefixM(key);
  }

  //to calculate longest common prefix - given input vector of strings
  string LCP() {
    return LCPUtil();
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

  //Function to calculate longest common prefix by reading all the input strings (first step is to insert all the words in the trie)
  string LCPUtil() {
    TrieNode* temp = root;
    return LCPstr(temp);
  }
  
  string LCPstr(TrieNode* temp) {
    int i;
    if(temp == NULL)
      return string("");
    for(i = 0; i < 26; i++)
      if(temp->child[i] != NULL)
        break;
    if(i == 25)
      return string("");
    
    char ch = 'a' + i;
    
    string str;
    str.insert(str.begin(), ch);
    if(temp->hasValue)
      return string("");
    else
      return str + LCPstr(temp->child[i]);
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
