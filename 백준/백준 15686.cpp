// 15686번 치킨 배달

#include <cstdio> 
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int numc = 0, numh = 0, n, m, ans = 10000;
pair<int, int> c[13], h[100];
bool use[13];

int absf(int a) { return a < 0 ? -a : a; }
int minf(int a, int b) { return a < b ? a:b; }

void update() {
	int sum = 0;
	
	// 각 집의 치킨거리 계산 후 합 구함 
	for (int i=0; i<numh; i++) {
		int tmp = 100;
		for (int j=0; j<numc; j++) {
			if(use[j]) {
				tmp = minf(tmp, absf(h[i].first - c[j].first) + absf(h[i].second - c[j].second));		
			}
		}
		sum += tmp;
	}
	
	// 그 합이 ans보다 작으면 업데이트 
	ans = minf(ans, sum);
}

void dfs(int depth, int no) {
	if (no == m) {
		update();
		return;
	}
	
	if (depth == numc) return;
	
	use[depth] = true;
	dfs(depth + 1, no + 1);
	use[depth] = false;
	dfs(depth + 1, no);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) {
		for (int j=0;j <n; j++) {
			int no;
			scanf("%d", &no);
			
			if (no == 2) {
				c[numc].first = i;
				c[numc].second = j;
				numc++;
			}
			else if (no == 1) {
				h[numh].first = i;
				h[numh].second = j;
				numh++;
			}
		}
	}
	
	dfs(0, 0);
	
	printf("%d", ans);
	
	return 0;
}
