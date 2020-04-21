#include <iostream>
#include <string>
using namespace std;

int main()
{
  string pattern, text;
  getline(cin, pattern);
  getline(cin, text);
  int patternlen = pattern.length(), textlen = text.length();
  for (int i = 0; i <= textlen - patternlen; i++) {
    if (pattern.compare(text.substr(i, patternlen)) == 0)
      cout<< i << " ";
  }
  cout<<endl;
  return 0;
}
