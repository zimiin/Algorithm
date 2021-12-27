// 2003번 수들의 합

#include <iostream>
using namespace std;

int N, M;
int A[10000];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];

	int s = 0, e = 0;
	int sum = A[0];

	int res = 0;

	while (e < N) {
		if (sum < M) sum += A[++e];
		else {
			if (sum == M) res++;
			sum -= A[s++];
		}
	}

	cout << res;
	
	return 0;
}
