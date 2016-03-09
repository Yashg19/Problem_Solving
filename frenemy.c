int isFrenemy(int n, char** frenemy, int x, int y, char* relation) {
  int i, j, k;
  int len = strlen(relation);
  int dp[len+1][len+1];
  memset(dp, 0, sizeof(dp));
  dp[x][0] = 1;
  for(k = 1; k < len+1; k++){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	if(!(i == j) && (dp[j][k-1] == 1) && (frenemy[i][j] == relation[k-1])){
	  dp[i][k] = 1;
	  break;
	}
      }
    }
  }
  return dp[y][k-1];
}

