// 1987번 알파벳

#include <iostream>
using namespace std;

int R, C;
char board[20][20];

bool visited[26] = { 0 };
int maxNo = 1;

int nr[] = {0, 1, 0, -1};
int nc[] = {1, 0, -1, 0};

void input() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
}

bool in_range(int r, int c) {
	if (r >= 0 && r < R&&c >= 0 && c < C) return true;
	else return false;
}

void solution(int r, int c, int no) {
	for (int i = 0; i < 4; i++) {
		if (!in_range(r + nr[i], c + nc[i]))
			continue;

		if (visited[board[r + nr[i]][c + nc[i]] - 'A'])
			continue;

		visited[board[r + nr[i]][c + nc[i]] - 'A'] = true;
		solution(r + nr[i], c + nc[i], no + 1);
		visited[board[r + nr[i]][c + nc[i]] - 'A'] = false;
	}

	if (maxNo < no) maxNo = no;
}

int main() {
	input();

	visited[board[0][0] - 'A'] = true;
	solution(0, 0, 1);
	
	cout << maxNo;
	return 0;
}
