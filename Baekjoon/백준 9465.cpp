// 9465 스티커

#include <cstdio> 
using namespace std;

#define MAX 100010

int n, sticker[2][MAX], t;
int dp[2][MAX];

int maxf(int a, int b) { return a>b?a:b; }

int main() {
	scanf("%d", &t);
	
	while (t--) {
		// initialize
		for (int i=0; i<2; i++) {
			for (int j=0; j<MAX; j++) {
				dp[i][j] = 0;
			}
		} 
		
		scanf("%d", &n);
		
		for (int i=0; i<2; i++) {
			for (int j=1; j<=n; j++) {
				scanf("%d", &sticker[i][j]);
			}
		}
		
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		
		for (int i=2; i<=n; i++) {
			dp[0][i] = maxf(dp[1][i - 1], maxf(dp[0][i - 2], dp[1][i - 2])) + sticker[0][i];
			dp[1][i] = maxf(dp[0][i - 1], maxf(dp[0][i - 2], dp[1][i - 2])) + sticker[1][i];
		}
		
		printf("%d\n", maxf(maxf(dp[0][n - 1], dp[1][n - 1]), maxf(dp[0][n], dp[1][n])));
	}
	
	return 0;
}
