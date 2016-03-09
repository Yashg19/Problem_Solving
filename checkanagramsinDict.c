#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
  char word[50];
  struct node* left;
  struct node* right;
};

struct node* newnode(char *str)
{
  struct node* new = (struct node*)malloc(sizeof(struct node));
  strcpy(new->word, str);
  new->left = NULL;
  new->right = NULL;
  return new;
}

struct node* root = NULL;

void insert(char *str)
{
  struct node* current = NULL;
  struct node* parent = NULL;
  int res = 0;

  if(!root)
    {
      root = newnode(str);
      return;
    }
  current = root;
  while(current != NULL)
    {
      res = strcasecmp(str, current->word);
      if(res == 0)
	{
	  printf("Word already present\n");
	  return;
	}
      parent = current;
      if (res > 0)
	current = current->right;
      else
	current = current->left;
    }
  if(res > 0)
    parent->right = newnode(str);
  else
    parent->left = newnode(str);
}

void printInorder(struct node* root)
{
  if(root == NULL)
    return;
  
  printInorder(root->left);
  printf("%s\t", root->word);
  printInorder(root->right);
}

bool isElementPresent(char *str)
{
  struct node* temp = root;
  int res = 0;
  while(temp != NULL)
    {
      res = strcasecmp(str, temp->word);
      if(res == 0)
	return true;
      else if(res > 0)
	temp = temp->right;
      else
	temp = temp->left;
    }
  return false;
}

void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

void checkAnagramDict(char *str, int l, int r)
{
  int i;
  char *temp;
  if(l == r)
    {
      temp = (char*)malloc(strlen(str) + 1);
      strcpy(temp, str);
      if(isElementPresent(temp))
	printf("Anagram %s is in Dictionary\n", temp);
      else
	printf("Anagram %s is NOT in Dictionary\n", temp);
    }
  else
    {
      for(i=l; i <=r; i++)
	{
	  swap((str+l), (str+i));
	  checkAnagramDict(str, l+1, r);
	  swap((str+l), (str+i));
	}
    }
}

int main()
{
  char* word[] = {"cat", "act", "dog", "god", "elf", "rack", "deck", "aaron"};
  int size = sizeof(word)/sizeof(word[0]);
  int i;

  for(i=0; i<size; i++)
    insert(word[i]);

  printf("InOrder Traversal\n");
  printInorder(root);
  printf("\n");

  char s[] = "cat";
  
  if(isElementPresent(s))
    printf("Present\n");
  else
    printf("Not Present\n");
  
  int len = strlen(s);
  checkAnagramDict(s, 0, len-1);

  return 0;
}
      
      
