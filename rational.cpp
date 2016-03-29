#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>

using namespace std;

void rational(int a, int b, int &store1, int &store2)
{
  int originala = a;
  int originalb = b;
  while(1)
    {
      a = a % b;
      if(a == 0)
	{
	  store1 = originala / b;
	  store2 = originalb / b;
	  break;
	}
      b = b % a;
      if(b == 0)
        {
	  store1 = originala / a;
	  store2 = originalb / a;
	  break;
	}
    }
}

vector < string > ReduceFraction(vector < string > fractions) {
  vector <string> res;
  int len = fractions.size();
  int n1, n2;
  int ans[2];
  
  for(int i = 0; i < len; i++){
    string record = fractions[i];
    cout << record << endl;
    char *a = new char[record.size() + 1];
    a[record.size()] = 0;
    memcpy(a,record.c_str(),record.size());
    char* pch;
    pch = strtok(a, "/");
    string num = pch;
    n1 = atoi(num.c_str());
    while (pch != NULL) {
      pch = strtok(NULL, "/");
      string den = pch;
      n2 = atoi(den.c_str()); 
      break;
    }
    rational(n1, n2, ans[0], ans[1]);
    string myans = to_string(ans[0])+"/"+to_string(ans[1]);
    res.push_back(myans);
  }
  return res;
}

int main() {
  vector<string> input;
  string s1 = "5/10";
  input.push_back(s1);
  string s2 = "4/6";
  input.push_back(s2);
  
  vector<string> res = ReduceFraction(input);
  
  for(unsigned int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
  
  cout << endl;
  
  return 0;
}

