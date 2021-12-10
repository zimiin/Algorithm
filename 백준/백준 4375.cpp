// 4375번 1

#include <cstdio>
using namespace std;

int n;
int cnt, div;

int main() {
	while (scanf("%d", &n) != EOF) {
		cnt = 1;
		div = 1;
		
		while (div % n) {
			div %= n;
			div = div * 10 + 1;
			cnt++;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
