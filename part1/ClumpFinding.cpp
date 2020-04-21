#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
  unordered_map<string, vector<int>> dict;
  string text;
  getline(cin, text);
  int textlen = text.length();
  int k, L, t;
  cin >> k >> L >> t;
  string sub;
  for (int i = 0; i <= textlen - k; i++) {
    sub = text.substr(i, k);
    auto it = dict.find(sub);
    if (it == dict.end()) {
      vector<int> pusher;
      pusher.push_back(i);
      dict[sub] = pusher;
    }
    else {
      (it->second).push_back(i);
    }
  }
  vector<string> solution;
  for (auto it = dict.begin(); it != dict.end(); it++) {
    int veclen = it->second.size();
    for (int i = 0; i <= veclen - t; i++) {
    	int pos1 = it->second.at(i);
    	int pos2 = it->second.at(i + t - 1);
    	if (pos2 - pos1 + k <= L) {
    		solution.push_back(it->first);
    		break;
    	}
    }
  }
  /*
  for (int i = 0; i < solution.size(); i++) {
    cout<< solution.at(i) << " ";
  }
  */
  cout << solution.size() << endl;
}
