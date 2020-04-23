#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>
#include<kmer.h>

using namespace std;

int main()
{
  ifstream inFile;
  inFile.open("input.txt");
  if (!inFile) {
    cout << "Unable to open input.txt" << endl;
    exit(1);
  }
  ofstream outFile;
  outFile.open("output.txt");
  if (!outFile) {
    cout << "Unable to write to output.txt" << endl;
    exit(1);
  }
  string text;
  getline(inFile, text);
  int k;
  inFile >> k;
  size_t size = 1 << (2*k);
  int* fqarr = (int*)calloc(size, sizeof(int));
  int len = text.length();
  for (int i = 0 ; i <= len - k; i++) {
    fqarr[pat2Num(text.substr(i, k))]++;
  }
  for (int i = 0; i < size; i++)
    outFile << fqarr[i] << " ";
  outFile << endl;

  inFile.close();
  outFile.close();
  return 0;
}