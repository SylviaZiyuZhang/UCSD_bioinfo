#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string text;
  string pattern;
  getline(cin, text);
  getline(cin, pattern);
  int patternlen = pattern.length();
  int textlen = text.length();
  int count = 0;
  for (int i = 0; i <= textlen - patternlen; i++) {
    if (pattern.compare(text.substr(i, patternlen)) == 0)
      count++;
  }
  cout<<count<<endl;
  return 0;
}

