// 3020번 개똥벌레

#include <cstdio> 
#include <algorithm>
using namespace std;

#define MAX_H 500000

int up[MAX_H], down[MAX_H];
int cnt[MAX_H];
int n, h;

int main() {
	scanf("%d%d", &n, &h);
	
	for(int i = 0; i < n; i++) {
		int in;
		scanf("%d", &in);
		
		if (i % 2) 	up[in - 1]++;
		else down[in - 1]++;
	}
	
	// count the no. of obstacles the bug has to break
	cnt[h - 1] = down[h - 1];
	for(int i = h - 2; i >= 0; i--) {
		cnt[i] += cnt[i + 1] + down[i];
	}
	
	cnt[0] += up[h - 1];
	int tmp = up[h - 1];
	for(int i = 1; i <= h - 1; i++) {
		cnt[i] += tmp + up[h - i - 1];
		tmp += up[h - i - 1];
	}
	
	sort(cnt, cnt + h);
	
	// count the minimum no. of obstacles
	int minobs = cnt[0], mincnt = 1;
	for (; minobs == cnt[mincnt]; mincnt++);
	
	printf("%d %d", minobs, mincnt);
	
	return 0;
}
