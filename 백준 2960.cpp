// 2960번 에라토스테네스의 체

#include <iostream>
using namespace std;

int is_prime[1001];

int main() {
	int N, K;
	cin >> N >> K;

	// initialize
	for (int i = 0; i <= N; i++) is_prime[i] = true;

	// find the result
	int no = 0;
	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) continue;

		// i is the prime number
		no++;
		if (no == K) {
			cout << i;
			return 0;
		}

		for (int j = i + i; j <= N; j += i) {
			// already checked
			if (!is_prime[j]) continue;
			
			is_prime[j] = false;
			no++;
			
			if (no == K) {
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}
