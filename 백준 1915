// 1915번 가장 큰 정사각형
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int n, m, a[1010][1010], ans=0;
int dp[1010][1010];

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int getmin(int a, int b, int c) {
	if (a < b) return a < c ? a : c;
	else return b < c ? b : c;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	
	// dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != 1) continue;

			int minVal = getmin(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]);
			dp[i][j] = minVal + 1;

			if (dp[i][j] > ans) ans = dp[i][j];
			//printf("%d\n", ans);
		}
	}

	printf("%d", ans*ans);

	return 0;
}
