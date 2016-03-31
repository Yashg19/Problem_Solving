/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/


/* 1 digit number - (0-9) -- [0-9] -- number of 1's => 1
   2 digit number - (0-99) -- [0-9][0-9] which can further be denoted as (I) [0, 2-9][0-9] and (II) [1][0-9] -- number of 1's ==> 20
   3 digit number - (0-999) -- [1][0-9][0-9] ==> 100 and [0, 2-9][0-9][0-9] ==> number of 1's 20 * 10 = 200 -- total number of 1's -- 300
*/

int countDigitOne(int n) {
  int res = 0, m = 0;
  for(long i = 1; i <= n; i = i * 10) {
    int d = (n % (i * 10))/i;    //this will get the digit from right to left for ex. if the digit is 1354 then d will be 4 then 5 then 3 and then 1
    res += d * m + (d == 1)*(n%i + 1) + (d > 1)*i;
    //res will calculate number of 1's from right to left. For ex. num of 1's < 4 then < 54 then < 354 <= 1354
    m = m*10 + i;
  }
  return res;
}
