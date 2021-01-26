// 15649번 N과 M (1)

#include <cstdio>
using namespace std;

int n, m;
int seq[10];
bool used[10];

void solution(int depth) {
	if (depth > m) {
		for (int i = 1; i <= m; i++) {
			printf("%d ", seq[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			seq[depth] = i;
			used[i] = true;
			solution(depth + 1);
			used[i] = false;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	solution(1);

	return 0;
}
