// 1256번 사전

#include <iostream>
using namespace std;

#define AZ_MAX 200
#define Q_MAX 1000000000

int pascal[AZ_MAX + 1][AZ_MAX + 1];
int noA, noZ, q;
int noAZ;

void cal_pascal() {
	for (int n = 1; n <= noAZ; n++) {
		for (int k = 0; k <= n; k++) {
			if (k == 0 || n == k) {
				pascal[n][k] = 1;
			}
			else {
				pascal[n][k] = pascal[n - 1][k - 1] + pascal[n - 1][k];
				if (pascal[n][k] > Q_MAX) pascal[n][k] = Q_MAX;
			}
		}
	}
}

int main() {
	cin >> noA >> noZ >> q;
	noAZ = noA + noZ;
	cal_pascal();

	if (pascal[noAZ][noZ] < q) {
		cout << -1;
		return 0;
	}

	char ans[201];
	for (int i = 1; i <= noAZ; i++) {
		// 둘 중 하나를 다 쓴 경우
		if (noA == 0) {
			ans[i - 1] = 'z';
			continue;
		}
		else if (noZ == 0) {
			ans[i - 1] = 'a';
			continue;
		}

		// a 선택
		if (q <= pascal[noAZ - i][noZ]) {
			ans[i - 1] = 'a';
			noA--;
		}
		// z 선택
		else {
			ans[i - 1] = 'z';
			q -= pascal[noAZ - i][noZ];
			noZ--;
		}
	}
	ans[noAZ] = '\0';

	cout << ans;

	return 0;
}
