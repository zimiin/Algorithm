#include <iostream>
#include <queue>
using namespace std;

#define BLANK 0
#define SNAKE 1
#define APPLE 2
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int board[101][101];
queue<pair<int, int>> snake;
queue<pair<int, char>> turn;
int N, K, L;
int nrpos[] = {0, 1, 0, -1};
int ncpos[] = {1, 0, -1, 0};

int main() {
  cin >> N;
  cin >> K;

  for (int i = 0; i < K; i++)
  {
    int r, c;
    cin >> r >> c;
    board[r][c] = APPLE;
  }

  cin >> L;

  for (int i = 0; i < L; i++) {
    int time;
    char dir;
    cin >> time >> dir;
    turn.push(make_pair(time, dir));
  }

  board[1][1] = SNAKE;
  snake.push(make_pair(1, 1));
  int time = 0;
  int dir = RIGHT;
  int curR = 1;
  int curC = 1;

  while (true) {
    if (turn.front().first == time) {
      if (turn.front().second == 'L') {
        dir -= 1;
        if (dir < 0) dir = 3;
      } else {
        dir += 1;
        if (dir > 3) dir = 0;
      }

      turn.pop();
    }

    time++;
    curR = curR + nrpos[dir];
    curC = curC + ncpos[dir];

    // cout << "curR : " << curR << ", curL : " << curC << endl;

    if (curR < 1 || N < curR || curC < 1 || N < curC || board[curR][curC] == SNAKE)
    {
      break;
    }

    if (board[curR][curC] != APPLE) {
      int tailR = snake.front().first;
      int tailC = snake.front().second;

      board[tailR][tailC] = BLANK;
      snake.pop();
    }

    board[curR][curC] = SNAKE;
    snake.push(make_pair(curR, curC));
  }

  cout << time;

  return 0;
}