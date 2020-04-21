#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  unordered_map<string, int> dict;
  string text;
  getline(cin, text);
  int textlen = text.length();
  int k;
  cin >> k;
  string sub;
  for (int i = 0; i <= textlen - k; i++) {
    sub = text.substr(i, k);
    auto it = dict.find(sub);
    if (it == dict.end())
      dict[sub] = 1;
    else {
      it->second ++;
    }
  }
  int max = 0;
  for (auto it = dict.begin(); it != dict.end(); it++) {
    if (max < it->second)
      max = it->second;
  }
  for (auto it = dict.begin(); it != dict.end(); it++) {
    if (it->second == max) {
      cout << it->first << " ";
    }
  }
  cout<<endl;
  return 0;
}
