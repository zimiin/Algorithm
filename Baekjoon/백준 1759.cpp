// 1759번 암호 만들기

#include <iostream>
using namespace std;

#define NO_ALPH 26
int L, C;
bool available[NO_ALPH] = { 0 };
bool pw[NO_ALPH] = { 0 };

void input() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		available[c - 'a'] = true;
	}
}

bool is_valid() {
	char vowel[] = { 'a', 'e', 'i', 'o', 'u' };
	int noVowel = 0;
	for (int i = 0; i < 5; i++) {
		if (pw[vowel[i] - 'a']) noVowel++;
	}

	if (noVowel > 0 && (L - noVowel) > 1) return true;
	return false;
}

void print() {
	for (int i = 0; i < NO_ALPH; i++) {
		if (pw[i]) cout << (char)('a' + i);
	}
	cout << endl;
}

void solution(int depth, int index) {
	if (depth == L) {
		if (is_valid()) print();
	}

	for (int i = index; i < NO_ALPH; i++) {
		if (available[i]) {
			pw[i] = true;
			solution(depth + 1, i + 1);
			pw[i] = false;
		}
	}
}

int main() {
	input();
	solution(0, 0);
	return 0;
}
