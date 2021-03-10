// 16678번 모독

#include <cstdio> 
#include <algorithm>
using namespace std;
typedef long long ll;

int score[100000], n;
ll ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
	}
	
	sort(score, score + n);
	
	int cur = 1;
	
	for (int i = 0; i < n; i++) {
		if (score[i] >= cur) {
			ans += (score[i] - cur);
			cur++;
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
