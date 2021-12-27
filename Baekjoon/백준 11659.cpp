// 11659번 구간 합 구하기 4

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int n, m;
int num[100010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 2; i <= n; i++) {
		num[i] += num[i - 1];
	}

	while (m-- > 0) {
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%d\n", num[j] - num[i - 1]);
	}

	return 0;
}
