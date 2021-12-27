// 5557번 1학년

#include <cstdio> 
using namespace std;

int n, nums[100];
long long dp[100][21];

int main() {
	// test
	//freopen("5557_t1.txt", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	
	dp[0][nums[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			int cur = j + nums[i];
			if (cur >= 0 && cur <= 20) {
				dp[i][cur] += dp[i - 1][j];
				
				// test
				//printf("dp[%d][%d] = %d\n", i, cur, dp[i][cur]);
			}
			
			cur = j - nums[i];
			if (cur >= 0 && cur <= 20) {
				dp[i][cur] += dp[i - 1][j];
				
				// test
				//printf("dp[%d][%d] = %d\n", i, cur, dp[i][cur]);
			}
		}
	}
	
	printf("%lld", dp[n - 2][nums[n - 1]]);
	
	return 0;
}
