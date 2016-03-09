#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

struct stack{
  int num[MAXSIZE];
  int top;
};

typedef struct stack STACK;
STACK s;

int pop()
{
  int res;
  if(s.top == -1)
    return;
  else
    {
      res = s.num[s.top];
      s.top = s.top - 1;
    }
  return res;
}

void push(int lock_num)
{
  if(s.top == (MAXSIZE - 1))
    return;
  else
    {
      s.top = s.top + 1;
      s.num[s.top] = lock_num;
    }
  return;
}

int checkEvents(int size, char **str)
{
  s.top = -1;
  int i;
  int num;
  for(i=0; i<size; i++)
    {
      if(*str[i] == 'A')
	{
	  char *temp = (char*)malloc(sizeof(char)*30);
	  strcpy(temp, str[i]);
	  char *ch;
	  ch = strtok(temp, " ");
	  while(ch != NULL)
	    {
	      num = atoi(ch);
	      ch = strtok(NULL, " ");
	    }
	  free(temp);
	  push(num);
	}
    }
      
  printf("Pop = %d\n", pop());
  printf("Pop = %d\n", pop());
  printf("Pop = %d\n", pop());
      
  return 0;
      
}

int main()
{
  char *str[] = {"ACQUIRE 45", "ACQUIRE 10", "ACQUIRE 22"};
  int size = sizeof(str)/sizeof(str[0]);

  int i;
  for(i=0; i<size; i++)
    printf("%s\n", str[i]);

  int result = checkEvents(size, str);

  return 0;
}
