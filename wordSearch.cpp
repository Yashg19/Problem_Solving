/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
private:
  int row;
  int col;
    
  bool dfs(vector<vector<char>>&board, string word, int i, int j, int index) {
    if(index == word.size())
      return true;
            
    if(i < 0 || j < 0 || i >= row || j >= col)
      return false;
        
    if(word[index] != board[i][j])
      return false;
        
    board[i][j] = '#';
        
    if(dfs(board, word, i+1, j, index+1) ||
       dfs(board, word, i-1, j, index+1) ||
       dfs(board, word, i, j+1, index+1) ||
       dfs(board, word, i, j-1, index+1))
      return true;
           
    board[i][j] = word[index];
        
    return false;
  }

public:
  bool exist(vector<vector<char>>& board, string word) {
    if(board.size() == 0)
      return false;
    row = board.size();
    col = board[0].size();
    for(int r = 0; r < row; r++) {
      for(int c = 0; c < col; c++) {
	if(dfs(board, word, r, c, 0))
	  return true;
      }
    }
    return false;
  }
};
