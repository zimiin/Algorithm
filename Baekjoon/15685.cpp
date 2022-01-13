#include <iostream>
#include <vector>
using namespace std;

int N;
bool coord[101][101];
int curveInfo[20][4];
int startDirX[] = { 1, 0, -1, 0 };
int startDirY[] = { 0, -1, 0, 1 };

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> curveInfo[i][j];
    }
  }
}

void checkCurve(int no) {
  int startX = curveInfo[no][0];
  int startY = curveInfo[no][1];
  int dir = curveInfo[no][2];
  int endGen = curveInfo[no][3];
  int secondX = startX + startDirX[dir];
  int secondY = startY + startDirY[dir];

  vector<pair<int, int>> curve;
  curve.push_back(make_pair(startX, startY));
  curve.push_back(make_pair(secondX, secondY));

  coord[startY][startX] = true;
  coord[secondY][secondX] = true;

  for (int gen = 0; gen < endGen; gen++) {
    int dotToMove = curve.size() - 2;
    int curEndX = curve.back().first;
    int curEndY = curve.back().second;

    for (; dotToMove >= 0; dotToMove--) {
      int dotX = curve[dotToMove].first;
      int dotY = curve[dotToMove].second;
      int nextDotX = curEndX + (curEndY - dotY);
      int nextDotY = curEndY - (curEndX - dotX);

      curve.push_back(make_pair(nextDotX, nextDotY));
      coord[nextDotY][nextDotX] = true;
    }
  }
}

void printCoord() {
  int max = 10;
  for (int i = 0; i < max; i++) {
    for (int j = 0; j < max; j++) {
      cout << coord[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  input();

  for (int curve = 0; curve < N; curve++) {
    checkCurve(curve);

    // test
    // printCoord();
  }

  int count = 0;
  for (int y = 0; y < 100; y++) {
    for (int x = 0; x < 100; x++) {
      if (coord[y][x] == true && coord[y][x + 1] == true && coord[y + 1][x] == true && coord[y + 1][x + 1] == true) {
        count++;
      }
    }
  }

  cout << count;

  return 0;
}