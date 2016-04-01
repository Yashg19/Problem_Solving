/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
private:
  vector<vector<int>> matrixSum;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    if(matrix.size() == 0)
      return;
    int m = matrix.size();
    int n = matrix[0].size();
    int sum;
    vector<vector<int>> matSum(m+1, vector<int>(n+1, 0));
        
    for(int i = 1; i <= m; i++){
      sum = 0;
      for(int j = 1; j <= n; j++) {
	sum += matrix[i-1][j-1];
	matSum[i][j] = matSum[i-1][j] + sum;
      }
    }
    matrixSum = matSum;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return matrixSum[row2+1][col2+1] + matrixSum[row1][col1] - matrixSum[row1][col2+1] - matrixSum[row2+1][col1];    
  }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
