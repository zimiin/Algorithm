// 2580번 스도쿠

#include <iostream>
using namespace std;

int board[9][9];
int noZero = 0;

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) noZero++;
		}
	}
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void available(int r, int c, bool num[]) {
	for (int i = 0; i < 9; i++) {
		num[board[r][i]] = false;
		num[board[i][c]] = false;
	}

	int row = (r / 3) * 3;
	int col = (c / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			num[board[row + i][col + j]] = false;
		}
	}
}

int solution(int r, int c, int zero) {
	if (zero == 0) {
		print();
		exit(0);
	}

	bool find = false;

	// find zero
	if (c >= 9) r++;
	for (; r < 9; r++) {
		for (c = 0; c < 9; c++) {
			if (board[r][c] == 0) {
				find = true;
				break;
			}
		}
		if (find) break;
	}

	bool num[10];
	for (int i = 0; i < 10; i++) num[i] = true;

	// find available numbers
	available(r, c, num);

	for (int i = 1; i < 10; i++) {
		if (!num[i]) continue;

		board[r][c] = i;
		solution(r, c + 1, zero - 1);
	}

	// failed
	board[r][c] = 0;
	return -1;
}

int main() {
	input();
	solution(0, 0, noZero);
	return 0;
}
