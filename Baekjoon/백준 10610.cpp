// 10610 30
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int a, int b) {
	return a > b ? true : false;
}

int main() {
	int N[100000];
	int len;
	
	string input;
	cin >> input;

	for (len = 0; input[len]; len++) {
		N[len] = input[len] - '0';
	}

	int cnt0 = 0, sum = 0;
	for (int i = 0; i < len; i++) {
		sum += N[i];
		if (N[i] == 0) cnt0++;
	}

	if (cnt0 == 0 || sum % 3 != 0) {
		cout << -1;
		return 0;
	}

	sort(N, N + len, cmp);

	for (int i = 0; i < len; i++) {
		cout << N[i];
	}

	return 0;
}
