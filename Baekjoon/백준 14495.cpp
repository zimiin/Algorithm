// 14495번 피보나치 비스무리한 수열

#include <cstdio> 
using namespace std;
typedef long long ll;

ll seq[120], n;

int main() {
	scanf("%lld", &n);
	
	for (int i = 1; i <= n; i++) {
		if (i <= 3) {
			seq[i] = 1;
			continue;
		}
		
		seq[i] = seq[i - 1] + seq[i - 3];
	}
	
	printf("%lld", seq[n]);
	
	return 0;
}
