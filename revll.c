#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* newnode(int data)
{
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;

  return new;
}

void printll(struct node* root)
{
  struct node* temp = root;
  while(temp)
    {
      printf("%d\t", temp->data);
      temp = temp->next;
    }
  printf("\n");
}

void reverse(struct node** root)
{
  //head->1->2->3->4->5->null

  struct node* temp = *root;
  struct node* next;
  struct node* prev = NULL;
  
  while(temp)
    {
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
  
  *root = prev;
}

void rec_reverse(struct node** root)
{
  struct node* f;
  struct node* r;

  if(*root == NULL)
    return;

  f = *root; //pointing to first node
  r = f->next; //pointing to rest of the node

  if(r == NULL)
    return;

  rec_reverse(&r);

  f->next->next = f;
  
  f->next = NULL;

  *root = r;
}

void removedupsorted(struct node* root)
{
  struct node* temp = root;
  struct node* next;

  if(temp == NULL)
    return;

  while(temp->next != NULL)
    {
      if(temp->data == temp->next->data)
	{
	  next = temp->next->next;
	  free(temp->next);
	  temp->next = next;
	}
      else
	{
	  temp = temp->next;
	}
    }
}

void removeDupUnsorted(struct node* root)
{
  int count[100] = {0};
  struct node* prev = NULL;
  struct node* temp = root;

  while(temp != NULL)
    {
      if(count[temp->data] != 0)
	{
	  prev->next = temp->next;
	  free(temp);
	  temp = prev->next;
	}
      else
	{
	  count[temp->data]++;
	  prev = temp;
	  temp = temp->next;
	}
    }
}

void FrontbackSplit(struct node *root, struct node** f, struct node** b)
{
  if(root->next == NULL)
    {
      *f = root;
      *b = NULL;
    }
  
  struct node* slow = root;
  struct node* fast = root->next;

  while(fast != NULL)
    {
      fast = fast->next;
      if(fast != NULL)
	{
	  slow = slow->next;
	  fast = fast->next;
	}
    }
  *f = root;
  *b = slow->next;
  slow->next = NULL;
}

struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  if(a == NULL)
    return b;
  else if(b == NULL)
    return a;
  
  if(a->data > b->data)
    {
      result = b;
      result->next = SortedMerge(a, b->next);
    }
  else
    {
      result = a;
      result->next = SortedMerge(a->next, b);
    }
  return result;
}

void MergeSort(struct node** root)
{
  struct node* head = *root;
  struct node* a;
  struct node* b;

  if(head == NULL || head->next == NULL)
    return;

  FrontbackSplit(head, &a, &b);

  MergeSort(&a);
  MergeSort(&b);

  *root = SortedMerge(a, b);
}

void swapNodes(struct node** root, int x, int y)
{
  if(x == y)
    return;

  struct node* p1;
  struct node* p2;
  struct node* a;
  struct node* b;
  struct node* temp = *root;

  if(temp->data == x)
    {
      p1 = NULL;
      a = temp;
    }
  
  while(temp->next)
    {
      if(temp->next->data == x)
	{
	  p1 = temp;
	  a = temp->next;
	}
      else if(temp->next->data == y)
	{
	  p2 = temp;
	  b = temp->next;
	}
      temp = temp->next;
    }
  
  temp = *root;
  struct node* t = NULL;

  printf("a data = %d and b data = %d\n", a->data, b->data);
  if(p1)
    printf("p1 data = %d\n", p1->data);
  if(p2)
    printf("p2 data = %d\n", p2->data);

  if(b->next == NULL)
    t = a->next;

  a->next = b->next;
  if(temp->data != x)
    p1->next = b;
  else
    temp = b;
  
  if(b->next != NULL)
    b->next = p2;
  else
    b->next = t;
  if(p2 != a)
    p2->next = a;

  *root = temp;
}

int main(int argc, char* argv[])
{
  struct node* root = newnode(1);
  root->next = newnode(2);
  root->next->next = newnode(2);
  root->next->next->next = newnode(4);
  root->next->next->next->next = newnode(5);
  root->next->next->next->next->next = newnode(6);
  root->next->next->next->next->next->next = newnode(6);

  printf("Originial list: \n");
  printll(root);

  reverse(&root);

  printf("Iterative List: \n");  
  printll(root);

  rec_reverse(&root);

  printf("Recursion List: \n");  
  printll(root);

  removedupsorted(root);
  printf("Removed duplicate List: \n");  
  printll(root);

  free(root);

  root = newnode(10);
  root->next = newnode(1);
  root->next->next = newnode(20);
  root->next->next->next = newnode(4);
  root->next->next->next->next = newnode(7);
  root->next->next->next->next->next = newnode(6);
  root->next->next->next->next->next->next = newnode(2);

  printf("New Unsorted List: \n");
  printll(root);

  MergeSort(&root);
  printf("Sorted List: \n");
  printll(root);

  free(root);

  root = newnode(10);
  root->next = newnode(10);
  root->next->next = newnode(1);
  root->next->next->next = newnode(20);
  root->next->next->next->next = newnode(1);
  root->next->next->next->next->next = newnode(7);
  root->next->next->next->next->next->next = newnode(10);
  root->next->next->next->next->next->next->next = newnode(6);

  printf("New Unsorted List with Duplicates: \n");
  printll(root);
  
  removeDupUnsorted(root);

  printf("New Unsorted List with Duplicates Removed: \n");
  printll(root);

  free(root);

  root = newnode(10);
  root->next = newnode(15);
  root->next->next = newnode(12);
  root->next->next->next = newnode(13);
  root->next->next->next->next = newnode(20);
  root->next->next->next->next->next = newnode(14);

  printf("Unsorted linked list - problem swapping nodes without swapping data\n");
  printll(root);

  swapNodes(&root, 10, 15);

  printf("Unsorted linked list - problem swapping nodes without swapping data solution: \n");
  printll(root);

  return 0;
}
