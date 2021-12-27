// 11050 이항 계수 1

#include <cstdio> 
using namespace std;

int bin[11][11], n, k;

int main() {
	bin[0][0] = 1;
	
	for (int i = 1; i <= 10; i++) {
		bin[i][0] = bin[i - 1][0];
		
		for (int j = 1; j <= i; j++) {
			bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
		}
	}
	
	scanf("%d%d", &n, &k);
	printf("%d", bin[n][k]);
	
	return 0;
}
