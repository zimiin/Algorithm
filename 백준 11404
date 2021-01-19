// 11404번 플로이드

#include <iostream>
using namespace std;

#define INF 20000000

int n, m;
int dist[110][110];

void floyd() {
	// 모든 도시의 쌍에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값
	for (int mid = 1; mid <= n; mid++) {
		for (int s = 1; s <= n; s++) {
			if (s == mid) continue;
			for (int e = 1; e <= n; e++) {
				if (e == mid) continue;
				int tmp = dist[s][mid] + dist[mid][e];
				if (tmp < dist[s][e]) {
					dist[s][e] = tmp;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	
	// initialize
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = INF;
		}
	}

	// input
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (dist[a][b] > c) {
			dist[a][b] = c;
		}
	}

	floyd();

	// 결과 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) {
				printf("0 ");
			}
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}
