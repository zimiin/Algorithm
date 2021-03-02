// 5569 출근 경로

#include <cstdio> 
using namespace std;

#define R 0	// right
#define U 1	// up
#define S 0	// straight
#define T 1	// turn

#define MOD 100000

int w, h, dp[110][110][2][2];

int main() {
	scanf("%d%d", &w, &h);
	
	dp[1][2][R][S] = 1;
	dp[2][1][U][S] = 1;
	
	for (int r = 1; r <= w; r++) {
		for (int c = 1; c <= h; c++) {
			if (r == 1 && c == 1) continue;
			
			// test
			//printf("현r: %d, c: %d, U/S: %d, U/T: %d, R/S: %d, R/T: %d\n"
			//, r, c, dp[r][c][U][S], dp[r][c][U][T], dp[r][c][R][S], dp[r][c][R][T]);
			
			dp[r + 1][c][U][S] = (dp[r + 1][c][U][S] + dp[r][c][U][S] + dp[r][c][U][T]) % MOD;
			dp[r + 1][c][U][T] = (dp[r + 1][c][U][T] + dp[r][c][R][S]) % MOD;
			dp[r][c + 1][R][S] = (dp[r][c + 1][R][S] + dp[r][c][R][S] + dp[r][c][R][T]) % MOD;
			dp[r][c + 1][R][T] = (dp[r][c + 1][R][T] + dp[r][c][U][S]) % MOD;
		}
	}
	
	printf("%d", (dp[w][h][U][S] + dp[w][h][U][T] + dp[w][h][R][S] + dp[w][h][R][T]) % MOD);
	
	return 0;
}
