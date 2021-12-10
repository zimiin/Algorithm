// 11052번 카드 구매하기

#include <cstdio> 
using namespace std;

int n, p[1001], dp[1001];

int maxf(int a, int b) { return a>b?a:b; }

int recur(int cur) {	
	if (dp[cur]) return dp[cur];
	
	dp[cur] = p[cur];
	
	for (int i = cur - 1; i > 0; i--) {
		dp[cur] = maxf(dp[cur], p[i] + recur(cur - i));
	}
	return dp[cur];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	
	printf("%d\n", recur(n));
		
	return 0;
}
