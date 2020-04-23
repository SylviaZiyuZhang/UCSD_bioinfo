#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifdef __cplusplus
extern "C"
{
  #endif
  int char2digit(char c);
  char digit2char(int x);
  #ifdef __cplusplus
}
#endif
int pat2Num(string pat);
string num2pat(int len, int num);
string revComplement(string str);
vector <int> patternMatching(string text, string pattern);
int HammingDist(string str1, string str2);