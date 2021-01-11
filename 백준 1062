// 1062번 가르침

#include <iostream>
using namespace std;

int N, K;

bool alph[26] = { 0 };
char words[50][16];
int selectCnt = 0;
int maxCnt = 0;

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}
}

void updateMax() {
	int res = 0;

	for (int i = 0; i < N; i++) {
		int j = 0;
		for (; words[i][j]; j++) {
			if (alph[words[i][j] - 'a'] == false) break;
		}

		if (words[i][j] == '\0') res++;
	}

	if (maxCnt < res) maxCnt = res;
}

void init() {
	// select a, n, t, i, c
	alph['a' - 'a'] = true;
	alph['n' - 'a'] = true;
	alph['t' - 'a'] = true;
	alph['i' - 'a'] = true;
	alph['c' - 'a'] = true;

	selectCnt = 5;
	updateMax();
}

void dfs(int index) {
	// 1. 체크인
	alph[index] = true;
	selectCnt++;

	// 2. 목적지인가?
	if (selectCnt == K) {
		updateMax();

		alph[index] = false;
		selectCnt--;
		return;
	}

	// 3. 연결 순회
	for (int i = index + 1; i < 26; i++) {
		// 4. 갈 수 있는가?
		if (!alph[i]) {
			// 5. 간다
			dfs(i);
		}
	}

	// 6. 체크아웃
	alph[index] = false;
	selectCnt--;
}

int solution() {
	if (K < 5) return 0;

	init();

	for (int i = 1; i < 26; i++) {
		if (!alph[i]) {
			dfs(i);
		}
	}

	return maxCnt;
}

int main() {
	input();
	cout << solution();
	return 0;
}
