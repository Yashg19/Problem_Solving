/*
Leet Code: 5

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Subscribe to see which companies asked this question

*/

char* longestPalindrome(char* s) {
  int len = strlen(s);
  if(len == 1)
    return s;
  int dp[len+1][len+1];
  memset(dp, 0, sizeof(dp));
  int i, j;

  for(i=len-1; i >=0; i--)
    {
      for(j = i; j < len; j++)
        {
	  if(((j-i <=2) || dp[i+1][j-1]) && (s[i] == s[j]))
	    dp[i][j] = 1;
        }
    }

  int max = 1, max_palin_len = 0, start = 0, end = 0;
  for(i=0; i < len; i++)
    {
      for(j=i; j < len; j++)
        {
	  if(dp[i][j])
            {
	      max_palin_len = j+1-i;
	      //printf("max len = %dn", max_palin_len);                                                                                                                                                     
	      if(max_palin_len > max)
                {
		  max = max_palin_len;
		  start = i;
		  end = j+1;
                }
            }
        }
    }
  char *res = (char*)malloc(sizeof(char) * (max + 1));
  int k = 0;
  for(i = start; i < end; i++)
    {
      res[k] = s[i];
      k++;
    }
  res[k] = '\0';
  return res;
}
