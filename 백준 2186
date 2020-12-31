// 2186번 문자판

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, M, K;
char board[100][100];
char word[81];

int res[100][100][80];

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	cin >> word;
}

int DFS(int r, int c, int depth) {
	if (depth == strlen(word) - 1) {
		return 1;
	}

	res[r][c][depth] = 0;

	int i = r - K > 0 ? r - K : 0;
	int end = r + K < N ? r + K + 1 : N;

	// vertical
	for (; i < end; i++) {
		if (i == r) continue;
		if (board[i][c] != word[depth + 1]) continue;

		// board[i][c] == word[depth+1]
		// already visited
		if (res[i][c][depth + 1] != -1) {
			res[r][c][depth] += res[i][c][depth + 1];
		}
		else {
			res[r][c][depth] += DFS(i, c, depth + 1);
		}
	}

	// horizontal
	i = c - K > 0 ? c - K : 0;
	end = c + K < M ? c + K + 1 : M;

	for (; i < end; i++) {
		if (i == c) continue;
		if (board[r][i] != word[depth + 1]) continue;
		
		// board[r][i] == word[depth+1]
		// already visited
		if (res[r][i][depth + 1] != -1) {
			res[r][c][depth] += res[r][i][depth + 1];
		}
		else {
			res[r][c][depth] += DFS(r, i, depth + 1);
		}
	}

	return res[r][c][depth];
}

int solution() {
	int ans = 0;

	// initialize res array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < strlen(word); k++) {
				res[i][j][k] = -1;
			}
		}
	}

	// push the first character's location
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == word[0]) {
				ans += DFS(i, j, 0);
			}
		}
	}

	return ans;
}

int main() {
	input();
	cout << solution();
	return 0;
} 
