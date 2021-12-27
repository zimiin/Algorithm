// 2725번 보이는 점의 개수

#include <cstdio> 
using namespace std;

int cnt[1010];
int t, n;

bool is_coprime(int a, int b) {
	int gcd = a, remain = b;
	while (remain > 0) {
		int tmp = remain;
		remain = gcd % remain;
		gcd = tmp;	
	}
	
	if (gcd == 1) return true;
	else return false;
}

int main() {
	// cnt 세기
	cnt[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		cnt[i] += cnt[i - 1];
		
		for (int j = 1; j < i; j++) {
			if (is_coprime(i, j)) {
				cnt[i] += 2;
			}
		}	
	}
	
	scanf("%d", &t);
	
	for(int c = 0; c < t; c++) {
		scanf("%d", &n);
		printf("%d\n", cnt[n]);
	}
	
	return 0;
}
