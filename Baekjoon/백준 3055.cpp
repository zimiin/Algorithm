// 3055번 

#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[50][50];	// 지도

queue<pair<int, int>> wq;	// 물 이동 탐색 시 사용
queue<pair<int, int>> hq;	// 고슴도치 이동 탐색 시 사용

int nrpos[] = { 1, 0, -1, 0 };
int ncpos[] = { 0, 1, 0, -1 };

void input() {
	cin >> R >> C;

	char line[50];
	for (int i = 0; i < R; i++) {
		cin >> line;

		for (int j = 0; j < C; j++) {
			map[i][j] = line[j];

			if (map[i][j] == '*') {
				wq.push(make_pair(i, j));
			}
			else if (map[i][j] == 'S') {
				hq.push(make_pair(i, j));
			}
		}
	}
}

bool in_range(int r, int c) {
	if (r >= 0 && r < R && c >= 0 && c < C) {
		return true;
	}
	return false;
}

int solution() {
	int min = 1;
	int size, r, c, nr, nc;

	while (!hq.empty()) {
		// 물 이동
		size = wq.size();
		for (int i = 0; i < size; i++) {
			r = wq.front().first;
			c = wq.front().second;
			wq.pop();

			for (int n = 0; n < 4; n++) {
				nr = r + nrpos[n];
				nc = c + ncpos[n];

				if (!in_range(nr, nc)) continue;

				if (map[nr][nc] != 'D' && map[nr][nc] != 'X' && map[nr][nc] != '*') {
					map[nr][nc] = '*';
					wq.push(make_pair(nr, nc));
				}
			}
		}

		// 고슴도치 이동
		size = hq.size();
		for (int i = 0; i < size; i++) {
			r = hq.front().first;
			c = hq.front().second;
			hq.pop();

			for (int n = 0; n < 4; n++) {
				nr = r + nrpos[n];
				nc = c + ncpos[n];

				if (!in_range(nr, nc)) continue;

				if (map[nr][nc] != '*' && map[nr][nc] != 'X' && map[nr][nc] != 'S') {
					if (map[nr][nc] == 'D') return min;

					map[nr][nc] = 'S';
					hq.push(make_pair(nr, nc));
				}
			}
		}

		min++;
	}
	return -1;
}

int main() {
	input();
	
	int res = solution();
	
	if (res == -1) cout << "KAKTUS";
	else cout << res;

	return 0;
}
