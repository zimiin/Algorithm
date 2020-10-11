// 1107 리모컨

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

int N;	// destination chanel
int M;	// no. of broken buttons
bool btn[10] = { 0 };	// has info. on whether a button is broken
int ans;	// answer
int diff;	// difference between 100 and N

int valid(int n) {
	int len = 0;
	do {
		if (btn[n % 10]) return 0;
		n /= 10;
		len++;
	} while (n > 0);
	return len;
}

void findBig(int n) {
	for (int i = 0; i < diff; i++) {
		int len = valid(n);

		if (len) {
			int res = len + n - N;
			ans = ans < res ? ans : res;
			break;
		}

		n++;
	}
	return;
}

void findSmall(int n) {
	for (int i = 0; i < diff && n >= 0; i++) {
		int len = valid(n);

		if (len) {
			int res = len + N - n;
			ans = ans < res ? ans : res;
			break;
		}

		n--;
	}
	return;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	// all buttons are broken
	if (M == 10) {
		printf("%d", N - 100 >= 0 ? N - 100 : 100 - N);
		return 0;
	}

	// input info. on broken buttons
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		btn[num] = true;
	}

	ans = N - 100 > 0 ? N - 100 : 100 - N;
	diff = ans;

	findBig(N);
	findSmall(N - 1);

	// print the answer
	printf("%d", ans);

	return 0;
}
