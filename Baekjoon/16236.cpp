#include <iostream>
#include <queue>
using namespace std;

int N;
int space[20][20];
int sharkR, sharkC;
int sharkSize = 2;
int sharkAte = 0;
int nrpos[] = { -1, 0, 0, 1 };
int ncpos[] = { 0, -1, 1, 0 };

int abs(int x) { return x < 0 ? -x : x; }

class LocDist
{
  public:
    pair<int, int> loc;
    int dist;
    LocDist(pair<int, int> loc, int dist) {
      this->loc = loc;
      this->dist = dist;
    }
};

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    if (a.first > b.first) {
      return true;
    } else if (a.first < b.first) {
      return false;
    } else {
      if (a.second > b.second) {
        return true;
      } else return false;
    }
  }
};

LocDist* getFishLocDist()
{
  int r = 21, c = 21;
  int minDist = -1;

  // BFS
  bool visited[20][20] = { 0 };
  queue<pair<int, int>> q;
  q.push(make_pair(sharkR, sharkC));
  visited[sharkR][sharkC] = true;

  while (!q.empty()) {
    int len = q.size();
    minDist++;

    for (int i = 0; i < len; i++) {
      int cr = q.front().first;
      int cc = q.front().second;
      // cout << "cr " << cr << ", cc " << cc << endl;
      q.pop();

      if (space[cr][cc] < sharkSize && space[cr][cc] != 0) {
        if (cr < r || (cr == r && cc < c)) {
          r = cr;
          c = cc;
        }
      }
      
      for (int j = 0; j < 4; j++) {
        int nr = cr + nrpos[j];
        int nc = cc + ncpos[j];

        if (0 <= nr && nr < N && 0 <= nc && nc < N) {
          if (space[nr][nc] <= sharkSize && !visited[nr][nc]) {
            visited[nr][nc] = true;
            q.push(make_pair(nr, nc));
          }
        }
      }
    }

    if (r != 21) {
      break;
    }
  }

  return new LocDist(make_pair(r, c), minDist);
}

void printSpace() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // cout << space[i][j] << " ";
    }
    // cout << endl;
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> space[i][j];
      if (space[i][j] == 9) {
        sharkR = i;
        sharkC = j;
        space[i][j] = 0;
      }
    }
  }  

  int time = 0;

  while(true) {
    LocDist* locDist = getFishLocDist();
    int fishR = locDist->loc.first;
    int fishC = locDist->loc.second;
    int fishDist = locDist->dist;

    if (fishR == 21)
    {
      break;
    }

    space[fishR][fishC] = 0;
    sharkAte++;
    if (sharkAte >= sharkSize)
    {
      sharkSize++;
      sharkAte = 0;
    }
    time += fishDist;
    sharkR = fishR;
    sharkC = fishC;

    // printSpace();
    // cout << "sharkR " << sharkR << ", sharkC " << sharkC << endl;
    // cout << "sharkSize " << sharkSize << ", sharkAte " << sharkAte << endl;
    // cout << "time " << time << endl;
  }

  cout << time;

  return 0;
}