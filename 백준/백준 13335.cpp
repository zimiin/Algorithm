// 13335 트럭

#include <cstdio> 
using namespace std;

int n, w, l, truck[1000];
int loc[1000], s, e, time;

int main() {
	scanf("%d%d%d", &n, &w, &l);
	for (int i=0; i<n; i++) scanf("%d", &truck[i]);
	
	s = 0; e = -1;
	int sumWeight = 0;
	
	while (true) {
		if (loc[s] == w + 1) {
			s++;
			if (s == n) break;
		}
		
		if (loc[s] == w) {
			sumWeight -= truck[s];
		}
		
		if (e + 1 < n && sumWeight + truck[e + 1] <= l) {
			e++;
			sumWeight += truck[e];
		}
		
		for (int i=s; i<=e; i++) {
			loc[i]++;
		}
		
		time++;
	}
	
	printf("%d", time);
	
	return 0;
} 
