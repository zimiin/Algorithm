// 1149번 RGB 거리

 #include <cstdio>
 using namespace std;
 
 #define R 0
 #define G 1
 #define B 2
 
 int n, dp[1010][3];
 
 int getmin(int a, int b) { return a<b?a:b; }
 
 int main() {
 	scanf("%d", &n);
 	for (int i = 1; i <= n; i++) {
 		scanf("%d%d%d", &dp[i][R], &dp[i][G], &dp[i][B]);
	 }
	 
	for (int i = 1; i <= n; i++) {
		dp[i][R] += getmin(dp[i - 1][G], dp[i - 1][B]);
		dp[i][G] += getmin(dp[i - 1][R], dp[i - 1][B]);
		dp[i][B] += getmin(dp[i - 1][R], dp[i - 1][G]);
	}
	
	printf("%d", getmin(dp[n][R], getmin(dp[n][G], dp[n][B])));
 	
 	return 0;
 }
