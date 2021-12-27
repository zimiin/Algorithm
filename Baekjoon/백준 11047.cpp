// 11047 동전
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b ? true : false;
}

int main() {
	int N, K;
	int coin[10];

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	// 내림차순
	sort(coin, coin + N, cmp);

	int i = 0, cnt = 0;

	while (K > 0) {
		for (; i < N; i++) {
			if (K / coin[i] > 0) {
				cnt += K / coin[i];
				K %= coin[i];
			}
		}
	}

	cout << cnt;

	return 0;
}
