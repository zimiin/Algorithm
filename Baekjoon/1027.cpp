#include <iostream>
using namespace std;

int N;
int building[50];

int getMax(int a, int b) { return a > b ? a : b; }

int countVisible(int buildingNo) {
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (i == buildingNo) {
      continue;
    }
    // cout << "is buildingNo " << i << " visible?" << endl;

    double inclination = (double)(building[buildingNo] - building[i]) / (buildingNo - i);
    double alpha = building[i] - inclination * i;
    bool visible = true;

    if (i < buildingNo)
    {
      for (int j = i + 1; j < buildingNo; j++) {
        double y = inclination * j + alpha;

        if (y <= building[j]) {
          // cout << "other building " << j << " is higher" << endl;
          visible = false;
          break;
        }
      }
    }
    else if (buildingNo < i)
    {
      for (int j = buildingNo + 1; j < i; j++) {
        double y = inclination * j + alpha;

        if (y <= building[j]) {
          // cout << "other building " << j << " is higher" << endl;
          visible = false;
          break;
        }
      }
    }

    if (visible)
    {
      cnt++;
    }
  }

  return cnt;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> building[i];
  }

  int max = 0;

  for (int i = 0; i < N; i++) {
    int cnt = countVisible(i);
    // cout << "building " << i << ", cnt " << cnt << ", max " << max << endl;
    max = getMax(max, cnt);
  }

  cout << max;

  return 0;
}