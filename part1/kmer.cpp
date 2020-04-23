#include "kmer.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int char2digit(char c)
{
  switch (c) {
  case 'A': return 0;
  case 'C': return 1;
  case 'G': return 2;
  case 'T': return 3;
  default:
    cout << "Invalid char in char2digit" << endl;
    return -1;
  }
}

char digit2char(int x)
{
  switch (x) {
  case 0: return 'A';
  case 1: return 'C';
  case 2: return 'G';
  case 3: return 'T';
  default:
    cout << "Invalid digit in digit2char" << endl;
    return '\0';
  }
}

int pat2Num(string pat)
{
  int len = pat.length();
  if (len == 0)
    return 0;
  char c = pat.at(len - 1);
  string prefix = pat.substr(0, len - 1);
  return 4 * pat2Num(prefix) + char2digit(c);
}

string revComplement(string str)
{
  int len = str.length();
  reverse(str.begin(), str.end());
  string ret;
  for (int i = 0; i < len; i++) {
    switch (str.at(i)) {
    case 'A': ret += 'T'; break;
    case 'T': ret += 'A'; break;
    case 'C': ret += 'G'; break;
    case 'G': ret += 'C'; break;
    }
  }
  return ret;
}

string num2pat(int len, int num)
{
  if (len == 1) return string(1, digit2char(num));

  int prefixindex = num / 4;
  int r = num - 4 * prefixindex;
  char c = digit2char(r);
  string prefix = num2pat(len - 1,prefixindex);
  prefix.insert(prefix.end(), 1, c);
  return prefix;
}

vector <int> patternMatching(string text, string pattern)
{
  vector <int> ret;
  int patternlen = pattern.length(), textlen = text.length();
  for (int i = 0; i <= textlen - patternlen; i++) {
    if (pattern.compare(text.substr(i, patternlen)) == 0)
      ret.push_back(i);
  }
return ret;
}

int HammingDist(string str1, string str2)
{
  int len = str1.length();
  int dist = 0;
  for (int i = 0; i < len; i++)
    if (str1.at(i) != str2.at(i))
      dist++;
  return dist;
}