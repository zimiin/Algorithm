// 1963번 소수경로

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10000

bool prime[MAX];	// true: prime num.
bool visited[MAX] = { 0 };

void to_false() {
	for (int i = 1000; i < MAX; i++) visited[i] = false;
}

void eratos() {
	// initialize
	for (int i = 2; i < MAX; i++) prime[i] = true;

	// do sieve of eratosthenes 
	for (int i = 2; i < MAX >> 2; i++) {
		if (!prime[i]) continue;

		int j = 2;
		int num = i * j;
		while (num < MAX) {
			prime[num] = false;
			j++;
			num = i * j;
		}
	}
}

bool queing(queue<int> &q, int cur, int end, int digit) {
	int value = (cur / digit) % 10;
	cur -= value * digit;

	for (int i = 0; i < 10; i++, cur += digit) {
		if (prime[cur] && !visited[cur]) {
			if (cur == end) return true;

			visited[cur] = true;
			q.push(cur);
		}
	}

	return false;
}

int answer(int begin, int end) {
	if (begin == end) return 0;

	queue<int> q;
	int result = 1, size, first;

	q.push(begin);
	visited[begin] = true;

	while (!q.empty()) {
		size = q.size();
		for (int i = 0; i < size; i++) {
			first = q.front();
			q.pop();

			for (int digit = 1; digit <= 1000; digit *= 10) {
				// reached the end number
				if (queing(q, first, end, digit)) {
					return result;
				}
			}
		}

		result++;
	}

	return -1;
}

int main() {
	int T;
	int A, B;
	int result;

	cin >> T;
	eratos();

	while (T--) {
		cin >> A >> B;
		// set visited array values to false
		to_false();
		result = answer(A, B);

		if (result == -1) cout << "Impossible" << endl;
		else cout << result << endl;
	}

	return 0;
}
