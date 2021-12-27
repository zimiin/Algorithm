// 1010번 다리 놓기

#include <cstdio> 
using namespace std;

int bin[31][31];
int n, m, t;

int main() {
	bin[0][0] = 1;
	for (int i = 1; i < 31; i++) {
		bin[i][0] = bin[i - 1][0];
		
		for (int j = 0; j <= i; j++) {
			bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
		}
	}
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", bin[m][n]);
		
	}
	
	return 0;
}
