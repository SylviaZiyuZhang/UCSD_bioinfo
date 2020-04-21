#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  int len = str.length();
  reverse(str.begin(), str.end());
  for (int i = 0; i < len; i++) {
    switch(str.at(i)) {
      case 'A' :
        cout << 'T';
        break;
      case 'T':
        cout << 'A';
        break;
      case 'C':
        cout << 'G';
        break;
      case 'G':
        cout << 'C';
        break;
    }
  }
  return 0;

}
