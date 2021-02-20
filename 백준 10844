// 10844번 쉬운 계단 수

#include <cstdio> 
using namespace std;

#define MOD 1000000000

int dp[101][10], n, ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
		
		dp[i][9] = dp[i - 1][8];
	}
	
	for (int i = 1; i < 10; i++) {
		ans = (ans + dp[n][i]) % MOD;
	}
	printf("%d", ans);
	
	return 0;
}
