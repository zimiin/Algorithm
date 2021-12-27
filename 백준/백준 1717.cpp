// 1717번 집합의 표현

#include <iostream>
using namespace std;

int n, m;
int p[1000010];

int findf(int a) {
	if (a == p[a]) return a;

	p[a] = findf(p[a]);
	return p[a];
}

void unionf(int a, int b) {
	a = findf(a);
	b = findf(b);
	p[a] = b;
}

int main() {
	scanf("%d %d", &n, &m);

	// initialize
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}

	while (m--) {
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) {
			unionf(a, b);
		}
		else {	// cmd == 1
			if (findf(a) == findf(b)) {
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}

	return 0;
}
