#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* a, const void* b)
{
  return (*(int*)b - *(int*)a);
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void permute(int a[], int l, int r)
{
  int i;
  if(l == r)
    {
      for(i=0; i<=r; i++)
	printf("%d", a[i]);
      printf("\n");
    }
  else
    {
      for(i=l; i<=r; i++)
	{
	  swap((a+i),(a+l));
	  permute(a, l+1, r);
	  swap((a+i),(a+l));
	}
    }
}

int main()
{
  int arr[] = {1,1,2};
  int size = sizeof(arr)/sizeof(arr[0]);

  qsort(arr, size, sizeof(int), compare);

  permute(arr, 0, size-1);

  return 0;
}
