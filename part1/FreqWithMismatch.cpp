#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "kmer.h"
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
  string text;
  getline(inFile, text);
  int k, threshold;
  inFile >> k >> threshold;
  int len = text.length();
  int size = 1 << (2 * k);
  int* arr = (int*)calloc(size, sizeof(int));
  int max = 0;
  for (int i = 0; i < size; i++) {
    string pat = num2pat(k, i);
    for (int j = 0; j <= len - k; j++) {
      string str = text.substr(j, k);
      if (HammingDist(pat, str) <= threshold) {
        arr[i] ++;
      }
      if (HammingDist(revComplement(pat), str) <= threshold) {
        arr[i] ++;
      }
    }
    if (max < arr[i])
      max = arr[i];
  }
  for (int i = 0; i < size; i++) {
    if (arr[i] == max) {
      outFile << num2pat(k, i) << " ";
    }
  }
  outFile << endl;
}