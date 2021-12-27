// 1932번 정수 삼각형
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int n;
int tri[510][510], max_val[510][510];

int getmax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	// DP
	max_val[1][1] = tri[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			max_val[i + 1][j] = getmax(max_val[i][j] + tri[i + 1][j], max_val[i + 1][j]);
			max_val[i + 1][j + 1] = getmax(max_val[i][j] + tri[i + 1][j + 1], max_val[i + 1][j + 1]);
		}
	}

	// get result
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = getmax(res, max_val[n][i]);
	}

	printf("%d", res);

	return 0;
}
