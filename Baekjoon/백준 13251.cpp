// 13251 조약돌 꺼내기

#include <cstdio> 
using namespace std;

double prob = 0, tmp;
int no[50], all = 0, m, k;

int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &no[i]);
		all += no[i];
	}
	scanf("%d", &k);
	
	for (int i = 0; i < m; i++) {
		if (no[i] < k) continue;
		
		tmp = 1;
		for (int j = 0; j < k; j++) {
			tmp *= (double)(no[i] - j) / (all - j);
		}
		prob += tmp;
	}
	
	printf("%.15lf", prob);
	
	return 0;
}
