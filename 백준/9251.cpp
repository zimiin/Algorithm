#include <iostream>
#include <string>
using namespace std;

int getmax(int a, int b) { return a > b ? a : b; }

int main() {
  string a, b;
  cin >> a >> b;

  int lcs[1010][1010] = { 0 };
  int aLen = a.length();
  int bLen = b.length();

  for (int aIdx = 0; aIdx < aLen; aIdx++) {
    for (int bIdx = 0; bIdx < bLen; bIdx++) {
      if (a[aIdx] == b[bIdx]) {
        lcs[aIdx + 1][bIdx + 1] = lcs[aIdx][bIdx] + 1;
      } else {
        lcs[aIdx + 1][bIdx + 1] = getmax(lcs[aIdx + 1][bIdx], lcs[aIdx][bIdx + 1]);
      }
    }
  }

  cout << lcs[aLen][bLen];
  
  return 0;
}