#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NO_OF_CHAR 256
#define NO_OF_ALPHA 26
#define BUFFERSIZE 10000

void pangram(char *str)
{
  int len = strlen(str);
  int i, alpha_count = 0;
  int count[NO_OF_CHAR] = {0};
  
  //Converting input string to lower case for easy checking
  for(i=0; i<len; i++)
    count[tolower(str[i])]++;

  //once the string is converted into lowercase we can easily see if it contains all the characters //referring ASCII values here
  for(i=97; i<=122; i++)
    {
      if(count[i] > 0)
	alpha_count++;
      else
	{
	  //if any of the count for char a-z is 0 - then its not a pangram
	  printf("not pangram\n");
	  return;
	}
    }

  //code to check if its a multi-pangram or just a pangram
  if(alpha_count >= NO_OF_ALPHA)
    {
      int temp = 0; //temp variable to keep track of count of pangrams
      for(i=97; i<=122; i++)
	{
	  if(count[i] > 0)
	    {
	      if(temp == 0)
		temp = count[i];
	      if(temp != count[i])
		{
		  printf("pangram\n");
		  return;
		}
	    }
	}
      printf("multiple pangram %d\n", temp);
    }
}

int main()
{
  char *big_str = NULL, *old_big_str;
  char s[31] = {0};
  int len = 0, old_len;

  do {
    old_len = len;
    old_big_str = big_str;
    scanf("%30[^\n]", s);
    if (!(big_str = realloc(big_str, (len += strlen(s)) + 1))) {
      free(old_big_str);
      //fprintf(stderr, "Out of memory!\n");
      break;
    }
    printf("old_len = %d\n", old_len);
    printf("strlen(s) = %d\n", strlen);
    strcpy(big_str + old_len, s);
  } while (len - old_len == 30);

  //fgets(str, BUFFERSIZE, stdin);

  //printf("text = %s\n", big_str);
  pangram(big_str);
  //pangram(str1);
  //pangram(str2);
  //pangram(str3);

  return 0;
}
