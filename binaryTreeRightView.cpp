/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

//8 ms solution using queue and level order traversal

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
      return res;
    queue<struct TreeNode*> q;
    q.push(root);
    struct TreeNode* s = NULL;
        
    while(!q.empty()) {
      int size = q.size();
      int flag = 0;
      while(size > 0) {
	s = q.front();
	if(flag == 0) {
	  res.push_back(s->val);
	  flag = 1;
	}
	q.pop();
	if(s->right)
	  q.push(s->right);
	if(s->left)
	  q.push(s->left);
	size--;
      }
    }
    return res;
  }
};

//4ms recursive solution to this problem

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
      return res;
    dfs_solution(root, res, 1);
    return res;
  }
    
  void dfs_solution(struct TreeNode* root, vector<int> &res, int level) {
    if(!root)
      return;
    if(res.size() < level)
      res.push_back(root->val);
    dfs_solution(root->right, res, level+1);
    dfs_solution(root->left, res, level+1);
  }
};
