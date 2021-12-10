// 1837번 암호제작

#include <iostream>
#include <string>
using namespace std;

#define MAX 1000000

string P;
int K;

bool is_prime[MAX];

void check_prime() {
	// initialize
	for (int i = 0; i < MAX; i++) is_prime[i] = true;

	for (int i = 2; i < MAX; i++) {
		if (!is_prime[i]) continue;

		// current i value is a prime num.
		for (int j = i + i; j < MAX; j += i)
			is_prime[j] = false;
	}
}

void solution() {
	bool is_bad = false;
	int prime;

	for (int i = 2; i < K; i++) {
		if (!is_prime[i]) continue;

		// i is a prime number
		// divide P by i
		int remainder = 0;
		for (int j = 0; P[j]; j++) {
			remainder *= 10;
			remainder += P[j] - '0';
			remainder %= i;
		}

		if (remainder == 0) {
			is_bad = true;
			prime = i;
			break;
		}
	}

	if (is_bad) printf("BAD %d", prime);
	else printf("GOOD");
}

int main() {
	cin >> P >> K;
	check_prime();
	
	// check whether P is good or bad and print the result
	solution();

	return 0;
}
