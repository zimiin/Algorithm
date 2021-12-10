// 11051번 이항계수2

#include <iostream>
using namespace std;

int bino[1001][1001];
int N, K;

int main() {
	cin >> N >> K;

	// 이항계수 구하기
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				bino[i][j] = 1;
				continue;
			}

			bino[i][j] = (bino[i - 1][j - 1] + bino[i - 1][j]) % 10007;
		}
	}

	cout << bino[N][K];

	return 0;
}
