// 14476번 최대공약수 하나 빼기

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

int N;
int nums[1000000];
int lgcd[1000000];
int rgcd[1000000];

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	lgcd[0] = nums[0];
	rgcd[N - 1] = nums[N - 1];

	// calculate left and right gcds
	for (int i = 1; i < N - 1; i++) {
		lgcd[i] = gcd(lgcd[i - 1], nums[i]);
		rgcd[N - i - 1] = gcd(rgcd[N - i], nums[N - i - 1]);
	}

	// find max gcd
	int maxgcd = 0, idx = -1;
	for (int i = 0; i < N; i++) {
		int curgcd = 0;

		if (i == 0) curgcd = rgcd[1];
		else if (i == N - 1) curgcd = lgcd[N - 2];
		else curgcd = gcd(lgcd[i - 1], rgcd[i + 1]);

		if (nums[i] % curgcd != 0 && curgcd > maxgcd) {
			maxgcd = curgcd;
			idx = i;
		}
	}

	if (idx == -1) printf("-1");
	else printf("%d %d", maxgcd, nums[idx]);

	return 0;
}
