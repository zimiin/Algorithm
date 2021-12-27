// 1806번 부분합

#include <iostream>
#include <limits.h>
using namespace std;

int N, S;
int num[100000];

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> num[i];

	int s = 0, e = 0;
	int sum = num[0];
	int min = INT_MAX;

	while (e < N) {
		if (sum < S) sum += num[++e];
		else {
			if (e - s + 1 < min) min = e - s + 1;
			sum -= num[s++];
		}
	}
	
	if (min == INT_MAX) cout << 0;
	else cout << min;

	return 0;
}
