#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct dataFreq
{
  int data;
  int freq;
  int index;
};

struct node{
  int freq;
  int data;
  int index;
  struct node* left;
  struct node* right;
};

struct node* root = NULL;

struct node* createNode(int val, int ix)
{
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->freq = 1;
  new->data = val;
  new->index = ix;
  new->left = new->right = NULL;
  return new;
}

void insert(int val, int ix)
{
  int left = 0, right = 0;
  if(!root)
    {
      root = createNode(val, ix);
      return;
    }
  struct node* temp = root;
  struct node* parent;
  while(temp != NULL)
    {
      left = 0, right = 0;
      if(temp->data == val)
	{
	  (temp->freq)++;
	  return;
	}
      else if(temp->data < val)
	{
	  parent = temp;
	  temp = temp->right;
	  right = 1;
	}
      else
	{
	  parent = temp;
	  temp = temp->left;
	  left = 1;
	}
    }
  if(left)
    parent->left = createNode(val, ix);
  if(right)
    parent->right = createNode(val, ix);
}
    
void printInorder(struct node* root)
{
  if(root == NULL)
    return;
  printInorder(root->left);
  printf("(%d,%d,%d)\t", root->data, root->freq, root->index);
  printInorder(root->right);
}

void store(struct node* r, struct dataFreq count[], int *index)
{
  if(r == NULL)
    return;

  store(r->left, count, index);
  count[(*index)].freq = r->freq;
  count[(*index)].data = r->data;
  count[(*index)].index = r->index;
  (*index)++;

  store(r->right, count, index);
}

/*
int compare(struct dataFreq a, struct dataFreq b)
{
  if(a.freq != b.freq)
    return (a.freq < b.freq);
  else
    return a.index > b.index;
}
*/
int compare(const void* a, const void* b)
{
  if((*(const struct dataFreq*)b).freq != (*(const struct dataFreq*)a).freq)
    return ((*(const struct dataFreq*)b).freq - (*(const struct dataFreq*)a).freq);
}


void sortByFreq(int a[], int size)
{
  int i;
  for(i=0; i<size; i++)
    insert(a[i], i);

  printInorder(root);
  printf("\n");

  struct dataFreq count[size];
  int index = 0;
  store(root, count, &index);

  for(i=0; i<index; i++)
    printf("(%d,%d,%d)\t", count[i].data, count[i].freq, count[i].index);
  printf("\n");

  qsort(count, index, sizeof(count[0]), compare);

  printf("Solution: \n");
  for(i=0; i<index; i++)
    printf("(%d,%d)\t", count[i].data, count[i].freq);
  printf("\n");
 

}

int main()
{
  int arr[] =  {1,2,1,7,4,5,4,3,1,4,4,2};
  int size = sizeof(arr)/sizeof(arr[0]);

  sortByFreq(arr, size);

  return 0;
}
