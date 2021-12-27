// 2748번 피보나치 수

#include <iostream>
using namespace std;

long long fibo[90 + 1];

int main() {
	int n;
	cin >> n;

	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n];
}
