// 1783 병든 나이트

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int ans;
	if (N >= 3 && M >= 7) {
		ans = M - 2;
	}
	else if (N < 2) {
		ans = 1;
	}
	else if (N < 3) {
		ans = fmin((M - 1) / 2 + 1, 4);
	}
	else if (M < 7) {
		ans = fmin(M, 4);
	}

	cout << ans;

	return 0;
}
