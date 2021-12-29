#include <iostream>
using namespace std;

int getAnswer(int x, int y) {
  int dist = y - x;
  int hop = 1;
  int cnt = 0;

  while (dist > hop) {
    dist -= hop;
    cnt++;

    if (dist > hop) {
      dist -= hop;
      cnt++;
    } else {
      break;
    }

    hop++;
  }

  if (dist > 0) {
    cnt++;
  }

  return cnt;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int x, y;
    cin >> x >> y;

    cout << getAnswer(x, y) << endl;
  }

  return 0;
}