#include<stdio.h>
#include<stdlib.h>

struct node
{
  int key;
  struct node* left, *right;
};
 
/* Helper function that allocates a new Node with the
   given key and NULL left and right pointers. */
struct node* newNode(int key)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return (temp);
}

void inOrder(struct node* root)
{
  if(root == NULL)
    return;

  inOrder(root->left);
  printf("%d\t", root->key);
  inOrder(root->right);
}

void serialize(struct node* root, FILE *fp)
{
  if (root == NULL)
    {
      fprintf(fp, "%d ", -1);
      return;
    }
  fprintf(fp, "%d ", root->key);
  serialize(root->left, fp);
  serialize(root->right, fp);
}

void deSerialize(struct node** root, FILE *fp)
{
  int val;
  while(!fscanf(fp, "%d ", &val) || val == -1)
    return;

  *(root) = newNode(val);
  struct node* temp = *(root);
  deSerialize(&temp->left, fp);
  deSerialize(&temp->right, fp);
}

int main()
{
  // Let us construct a tree shown in the above figure
  struct node *root        = newNode(20);
  root->left               = newNode(8);
  root->right              = newNode(22);
  root->left->left         = newNode(4);
  root->left->right        = newNode(12);
  root->left->right->left  = newNode(10);
  root->left->right->right = newNode(14);

  FILE *fp = fopen("tree.txt", "w");
  if (fp == NULL)
    return -1;

  serialize(root, fp);

  fclose(fp);

  struct node* root1 = NULL;
  fp = fopen("tree.txt", "r");

  deSerialize(&root1, fp);

  printf("Inorder Traversal of tree\n");
  
  inOrder(root1);

  return 0;

}
  
