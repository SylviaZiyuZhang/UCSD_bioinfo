#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
  ifstream inFile;
  inFile.open("input.txt");
  if (!inFile)
  {
    cout << "Unable to open input.txt" << endl;
    exit(1);
  }
  ofstream outFile;
  outFile.open("output.txt");
  if (!outFile)
  {
    cout << "Unable to write to output.txt" << endl;
    exit(1);
  }

  string str;
  getline(inFile, str);
  vector <int> skew;
  int cur = 0;
  int len = str.length();
  int min = len + 1;
  for (auto it = str.begin(); it != str.end(); it++) {
    if ((*it) == 'C') {
      cur --;
      skew.push_back(cur);
      if (min > cur) min = cur;
    }
    else if ((*it) == 'G') {
      cur ++;
      skew.push_back(cur);
    }
    else {
      skew.push_back(cur);
    }
  }
  for (int i = 0; i < len; i++) {
    if (skew.at(i) == min)
      outFile << i + 1 << " ";
  }
  outFile << endl;
  return 0;
  
}