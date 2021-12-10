// 1003번 피보나치 함수

#include <cstdio> 
#include <utility>
using namespace std;

pair<int, int> noZeroOne[41];
int t;

int main() {
	// calculate no. of zeros and ones
	noZeroOne[0] = make_pair(1, 0);
	noZeroOne[1] = make_pair(0, 1);
	
	for (int i = 2; i <= 40; i++) {
		noZeroOne[i].first = noZeroOne[i - 1].first + noZeroOne[i - 2].first;
		noZeroOne[i].second = noZeroOne[i - 1].second + noZeroOne[i - 2].second;
	}
	
	// print the result
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", noZeroOne[n].first, noZeroOne[n].second);
	}
}
