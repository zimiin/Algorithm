// 3108번 로고

#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000 * 2 + 1

int N;
int X1, Y1, X2, Y2;
int minX = MAX, minY = MAX, maxX = 0, maxY = 0;

int plane[MAX][MAX] = { 0 };
int no = 1;

int nx[] = { 1, 0, -1, 0 };
int ny[] = { 0, -1, 0, 1 };

bool in_range(int x, int y) {
	if (x >= 0 && x < MAX && y >= 0 && y < MAX) {
		return true;
	}
	return false;
}

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	plane[y][x] = ++no;

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (!in_range(curx + nx[i], cury + ny[i]))
				continue;

			// not visited
			if (plane[cury + ny[i]][curx + nx[i]] == 1) {
				plane[cury + ny[i]][curx + nx[i]] = no;
				q.push(make_pair(curx + nx[i], cury + ny[i]));
			}
		}
	}
}

int solution() {
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			// not visited
			if (plane[i][j] == 1) BFS(i, j);
		}
	}

	// start from 0, 0
	if (plane[1000][1000] != 0) {
		return no - 2;
	}
	else return no - 1;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		X1 = (X1 + 500) * 2;
		Y1 = (Y1 + 500) * 2;
		X2 = (X2 + 500) * 2;
		Y2 = (Y2 + 500) * 2;

		minX = minX < X1 ? minX : X1;
		maxX = maxX > X2 ? maxX : X2;
		minY = minY < Y1 ? minY : Y1;
		maxY = maxY > Y2 ? maxY : Y2;

		// 세로변 그리기
		for (int y = Y1; y <= Y2; y++) {
			plane[y][X1] = 1;
			plane[y][X2] = 1;
		}

		// 가로변 그리기
		for (int x = X1; x <= X2; x++) {
			plane[Y1][x] = 1;
			plane[Y2][x] = 1;
		}
	}
}

int main() {
	input();
	cout << solution() << endl;
	return 0;
}
