#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <kmer.h>
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

  string pat, text;
  int k;
  getline(inFile, pat);
  getline(inFile, text);
  inFile >> k;
  int patlen = pat.length();
  int textlen = text.length();
  int count = 0;
  for (int i = 0; i <= textlen - patlen; i++)
  {
    if (HammingDist(pat, text.substr(i, patlen)) <= k)
      count ++;
  }
  outFile << count << endl;
  return 0;
}