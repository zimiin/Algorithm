// 1753번 최단경로

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 300000

class Info {
public:
	int b, c;
	Info() {}
	Info(int b, int c) {
		this->b = b;
		this->c = c;
	}
};

class Dijk_Info {
public:
	int node;
	int dist;
	Dijk_Info() {}
	Dijk_Info(int node, int dist) {
		this->node = node;
		this->dist = dist;
	}
};

class comp {
public:
	bool operator() (Dijk_Info a, Dijk_Info b) {
		return a.dist > b.dist;
	}
};

int v, e, k;
vector<Info> adj[20010];
int dist[20010];

void dijk() {
	priority_queue<Dijk_Info, vector<Dijk_Info>, comp> pq;
	
	dist[k] = 0;
	pq.push(*(new Dijk_Info(k, 0)));

	while (!pq.empty()) {
		Dijk_Info cur = pq.top();
		pq.pop();

		if (cur.dist > dist[cur.node]) continue;

		for (int i = 0; i < adj[cur.node].size(); i++) {
			int b = adj[cur.node][i].b;
			int c = adj[cur.node][i].c;

			// cur.dist는 cur까지의 거리, c는 cur에서 b까지의 거리
			// dist[b]는 b까지의 거리 정보
			if (cur.dist + c < dist[b]) {
				dist[b] = cur.dist + c;
				pq.push(*(new Dijk_Info(b, dist[b])));
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &v, &e, &k);
	for (int i = 0; i < e; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back(*(new Info(b, w)));
	}

	// initialize
	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}

	// 다익스트라
	dijk();

	// 결과 출력
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else printf("%d\n", dist[i]);
	}

	return 0;
}
