// 6603 로또

#include <iostream>
using namespace std;

int k;
int S[12];

bool num[12] = { 0 };

void print() {
	for (int i = 0; i < k; i++) {
		if (num[i]) cout << S[i] << ' ';
	}
	cout << endl;
}

void solution(int index, int depth) {
	if (depth > 6) {
		print();
		return;
	}

	for (int i = index; i < (k - 6 + depth); i++) {
		num[i] = true;
		solution(i + 1, depth + 1);
		num[i] = false;
	}
}

int main() {
	while (true) {
		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}

		solution(0, 1);
		cout << endl;
	}

	return 0;
}
