#include <iostream>
using namespace std;

int main() {
  int N;
  int seat[20][20] = { 0 };
  int like[401][4] = { 0 };
  int nr[4] = { 0, -1, 0, 1 };
  int nc[4] = { -1, 0, 1, 0 };

  cin >> N;
  for (int i = 0; i < N * N; i++) {
    int std;
    cin >> std;

    for (int j = 0; j < 4; j++) {
      cin >> like[std][j];
    }

    // cout << "STUDENT " << std << endl;

    int likeCnt = 0;
    int emptyCnt = 0;
    int seatR, seatC;
    bool firstEmptySeat = true;

    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (seat[r][c] != 0) {
          continue;
        }

        // cout << "Base r " << r << " c " << c << endl;

        if (firstEmptySeat) {
          // cout << "First empty seat!!" << endl;
          seatR = r;
          seatC = c;
          firstEmptySeat = false;
        }

        int curLikes = 0;
        int curEmpties = 0;

        for (int pos = 0; pos < 4; pos++) {
          int cr = r + nr[pos];
          int cc = c + nc[pos];

          if (0 <= cr && cr < N && 0 <= cc && cc < N) {
            if (seat[cr][cc] == 0) {
              curEmpties++;
            } else {
              for (int likeIdx = 0; likeIdx < 4; likeIdx++) {
                if (seat[cr][cc] == like[std][likeIdx]) {
                  curLikes++;
                }
              }
            }
          }
        }

        if (curLikes > likeCnt)
        {
          // cout << "curLikes > likeCnt : " << curLikes << endl;
          seatR = r;
          seatC = c;
          likeCnt = curLikes;
          emptyCnt = curEmpties;
        }
        else if (curLikes == likeCnt && curEmpties > emptyCnt)
        {
          // cout << "curEmpties > emptyCnt : " << curEmpties << endl;
          seatR = r;
          seatC = c;
          emptyCnt = curEmpties;
        }
      }
    }

    seat[seatR][seatC] = std;
    // cout << endl;
  }

  int score = 0;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      int likeCnt = 0;
      int std = seat[r][c];

      for (int pos = 0; pos < 4; pos++) {
        int cr = r + nr[pos];
        int cc = c + nc[pos];

        if (0 <= cr && cr < N && 0 <= cc && cc < N) {
          for (int likeIdx = 0; likeIdx < 4; likeIdx++)
          {
            if (seat[cr][cc] == like[std][likeIdx]) {
              likeCnt++;
            }
          }
        }
      }

      if (likeCnt == 1) {
        score += 1;
      } else if (likeCnt == 2) {
        score += 10;
      } else if (likeCnt == 3) {
        score += 100;
      } else if (likeCnt == 4) {
        score += 1000;
      }
    }
  }

  cout << score;

  return 0;
}