#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* buildPrefixArr(char *p, int pLen)
{
  int i = 1, j = 0;
  char prev = p[0];
  int *temp = malloc(sizeof(int)*pLen);
  memset(temp, 0, sizeof(temp));
  
  while(i < pLen)
    {
      //printf("i = %d and j = %d\n", i, j);
      if(prev == p[i])
	{
	  temp[i] = j+1;
	  j++;
	  prev = p[j];
	  i++;
	}
      else if((prev != p[i]) && (j != 0))
	{
	  j = temp[j-1];
	  prev = p[j];
	}
      else
	i++;
    }
  return temp;
}

void patMatch(char *t, char *p, int tLen, int pLen)
{
  int *arr = buildPrefixArr(p, pLen);
  int i = 0, j = 0, count;
  
  while(i < tLen)
    {
      if(t[i] == p[j])
	{
	  i++;
	  j++;
	}
      if(j == pLen)
	{
	  printf("Pattern Found at location = %d\n", i-j);
	  j = arr[j-1];
	}
      else if(i < tLen && (t[i] != p[j]))
	{
	  if(j != 0)
	    {
	      j = arr[j-1];
	    }
	  else
	    i++;
	}
    }
  /*
  printf("Count = %d\n", count);
  if(count == pLen && j == pLen)
    {
      printf("pattern found at index = %d\n", i-count);
      return;
    }
  */
  //printf("Pattern Not Found\n");
  
}

int main()
{
  char text[] = "ABABDABACDABABCABABABABCABAB";
  char patt[] = "ABABCABAZ";

    int tLen = strlen(text);
  int pLen = strlen(patt);

  patMatch(text, patt, tLen, pLen);

  return 0;
}

  
