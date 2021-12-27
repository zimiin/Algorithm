// 11057번 오르막 수

#include <cstdio> 
using namespace std;

#define MOD 10007

int n, dp[1001][10];

int main() {
	scanf("%d", &n);
	
	// initialize
	for (int i=0; i<10; i++) {
		dp[1][i] = 1;
	}
	
	for (int len=2; len<=n; len++) {
		dp[len][9] = 1;
		
		for (int first=8; first>=0; first--) {
			dp[len][first] = (dp[len][first + 1] + dp[len - 1][first]) % MOD;
		}
	}
	
	int ans = 0;
	for (int first=0; first<10; first++) ans += dp[n][first];
	printf("%d", ans % MOD);
}
