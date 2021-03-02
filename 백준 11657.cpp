// 11657번 타임머신
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define INF 50000000000

int n, m;
vector<pair<int, ll>> adj[510];
ll dist[510];

void print() {
	printf("weight!!!\n");
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", dist[i]);
	}
}

int main() {
	//freopen("11657_1.txt", "r", stdin);
	scanf("%d%d", &n, &m);

	// 그래프 구성
	for (int i = 0; i < m; i++) {
		int a, b; ll c;
		scanf("%d%d%lld", &a, &b, &c);

		adj[a].push_back(make_pair(b, c));
	}
	
	// 거리 무한대 초기화
	dist[1] = 0;
	for (int i = 2; i <= n; i++) {
		dist[i] = INF;
	}
	
	// 거리 업데이트 N-1번 진행
	for (int i = 0; i < n - 1; i++) {
		for (int cur = 1; cur <= n; cur++) {
			if (dist[cur] == INF) continue;

			for (int j = 0; j < adj[cur].size(); j++) {
				int nxt = adj[cur][j].first;
				ll new_w = dist[cur] + adj[cur][j].second;
				//printf("cur:%d nxt:%d nxtW:%lld newW:%lld\n", cur, nxt, dist[nxt], new_w);
				if (dist[nxt] > new_w) {
					dist[nxt] = new_w;
				}
			}
		}
	}

	// 음의 사이클 존재 여부 확인
	bool hasNegCycle = false;
	for (int cur = 1; cur <= n; cur++) {
		if (dist[cur] == INF) continue;

		for (int j = 0; j < adj[cur].size(); j++) {
			int nxt = adj[cur][j].first;
			ll new_w = dist[cur] + adj[cur][j].second;

			if (dist[nxt] > new_w) {
				hasNegCycle = true;
				break;
			}
		}

		if (hasNegCycle) break;
	}

	// 결과 출력
	// 음의 사이클 있다면 -1, 아니면 모든 거리정보
	if (hasNegCycle) printf("-1");
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}

	return 0;
}
