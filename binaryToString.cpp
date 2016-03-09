/*
Problem

Our computers are so excited about the upcoming Google I/O that they've started storing their ones as capital letter Is and their zeroes as capital letter Os! For example, the character A, which is 65 in ASCII, would normally be stored as the byte 01000001, but our computers are storing it as OIOOOOOI.

Given a string of 8-character "bytes" consisting of Is and Os, can you translate it using ASCII? Every "byte" is guaranteed to translate to a printable character (a decimal value between 32 and 126, inclusive). Note that one of these characters (the one with decimal value 32) is a space. No translated message will begin or end with a space, but there may be internal space characters.

Solving this problem

Usually, Google Code Jam problems have 1 Small input and 1 Large input. This problem has only 1 Small input. Once you have solved the Small input, you have finished solving this problem.

Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of two lines. The first line of each test case contains an integer representing the number B of "bytes" in the string to be translated. The second line of each test case contains 8 * B characters, all of which are either I or O.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the translated message.

Limits

Small dataset

1 ≤ T ≤ 100.
1 ≤ B ≤ 1000.

Input 

2
2
OIOOIIIIOIOOIOII
21
OIOOIOOIOOIOOOOOOOIOOIIIOOIIIIOOOOIIOOIIOOIOOIIIOOIOOOOOOOIOOOIOOIOOOOIIOOIIOOOOOIIOOIOOOOIIOOIIOOIOOOOOOIOOIOIOOOIIOIOOOIIOIIOIOOIOOOIOOOIOOOOIOOIOOOOOOOIIIOIOOOIOIOOI



Output 
 
Case #1: OK
Case #2: I '<3' "C0d3 J4m"! :)

*/

string convertBin(const string s, int tot) {
  string res;  
  int i = 0, j, k, val;
  string temp;
  
  //Running the loop for the number of bytes in the string -- given as input
  while(i < tot) {
    temp.clear();
    j = s.size() - 1 - (i*8);
    k = 0;
    
    //Since each byte is 8 bits so running loop for 8 times
    while(k < 8) {
      if(s[j] == 'I')
        temp.push_back('1');
      else
        temp.push_back('0');
      k++;
      j--;
    }  
    
    reverse(temp.begin(), temp.end());

    //stoull -- used to convert binary string to an integer/long number
    val = stoull(temp, 0, 2);
    
    //pushing resultant character to the result string
    res.push_back((char)val);

    i++;
  } 
  
  //Result needs to be reversed since we are using push_back function
  reverse(res.begin(), res.end());

  return res;
  
}
