// 1790 수 이어 쓰기 2

#include <cstdio> 
using namespace std;

int n, k, start, nxt, len;

int main() {
	scanf("%d%d", &n, &k);
	
	start = 1; 
	nxt = 10;
	len = 1;
	
	for (int num = 1; num <= n; num++) {
		if (num >= nxt) {
			nxt *= 10;
			len++;
		}
		
		int end = start + len - 1;
		
		if (start <= k && k <= end) {
			// k번째 수 구하기 
			int loc = end - k + 1;
			int tmp = num, ans;
			
			for (int j=0; j<loc; j++) {
				ans = tmp % 10;
				tmp /= 10;
			}
			
			printf("%d", ans);
			return 0;
		}
		
		start = end + 1;
	}
	
	printf("-1");
	return 0;
}
