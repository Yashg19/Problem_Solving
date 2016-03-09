#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

void show_mem_rep(char *start, int n)
{
  int i;
  for(i=0; i<n; i++)
    printf("%.2x", start[i]);
  printf("\n");
}

int littleToBig(int x)
{
  x = ( x >> 24 ) | (( x << 8) & (0x00ff0000)) | ((x >> 8) & 0x0000ff00) | (x << 24);

  printf("Value of x = %x\n", x);

  show_mem_rep((char*)&x, sizeof(x));

  return x;
}


int bigToLittle(int x)
{
  int res;
  res = (x >> 24) | ((x << 8) && (0x00ff0000)) | ((x >> 8) & 0x0000ff00) | (x << 24);

  return res;
}

int main()
{
  int num1 = 1;
  char* ch = (char*)&num1;
  int x = 0x12345678;
  int res;
  
  if(*ch)
    {
      printf("Little Endian\n");
      printf("Show Original Memory Representation\n");
      show_mem_rep((char*)&x, sizeof(x));
      res = littleToBig(x);
      printf("Show Changed Memory Representation\n");
      show_mem_rep((char*)&x, sizeof(x));
    }
  else
    {
      printf("Big Endian\n");
      res = bigToLittle(x);
    }

  printf("Result = %x\n", res);

  uint32_t num = 1234;
  uint32_t b0,b1,b2,b3;
  uint32_t res1;

  show_mem_rep((char*)&num, sizeof(num));

  printf("32-bit integer: 0x%08" PRIX32 "\n", num);

  b0 = (num & 0x000000ff) << 24u;
  b1 = (num & 0x0000ff00) << 8u;
  b2 = (num & 0x00ff0000) >> 8u;
  b3 = (num & 0xff000000) >> 24u;

  printf("32-bit integer: 0x%08" PRIX32 "\n", b0);
  printf("32-bit integer: 0x%08" PRIX32 "\n", b1);
  printf("32-bit integer: 0x%08" PRIX32 "\n", b2);
  printf("32-bit integer: 0x%08" PRIX32 "\n", b3);

  res = b0 | b1 | b2 | b3;

  printf("32-bit integer: 0x%08" PRIX32 "\n", res);

  return 0;
}
  
      
