// 11053번 가장 긴 증가하는 부분 수열

#include <cstdio>
using namespace std;

int n, a[1000], dp[1000], ans = 0;

int maxf(int a, int b) { return a>b?a:b; }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = maxf(dp[i], dp[j] + 1);
			}
		}
		ans = maxf(ans, dp[i]);
	}
	
	printf("%d", ans);
	
	return 0;	
}
