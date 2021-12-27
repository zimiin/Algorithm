// 2564 경비원

#include <cstdio> 
using namespace std;

int w, h, n, loc[101], sum;

int absf(int a) { return a < 0 ? -a : a; }
int minf(int a, int b) { return a < b ? a : b; }

int main() {
	scanf("%d%d%d", &w, &h, &n);
	
	for (int i = 0; i <= n; i++) {
		int cardinal, location;
		scanf("%d%d", &cardinal, &location);
		
		if (cardinal == 1) {
			loc[i] = location;
		}
		else if (cardinal == 2) {
			loc[i] = 2 * w + h - location;
		}
		else if (cardinal == 3) {
			loc[i] = 2 * w + 2 * h - location;
		}
		else if (cardinal == 4) {
			loc[i] = w + location;
		}
	}
	
	for (int i = 0; i < n; i++) {
		int dist = absf(loc[n] - loc[i]);
		sum += minf(dist, 2 * w + 2 * h - dist);
	}
	
	printf("%d", sum);
	
	return 0;
}
