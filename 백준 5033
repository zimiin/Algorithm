// 5033 Money Matters

#include <cstdio>
using namespace std;

#define MAX 10000

int p[MAX], o[MAX], n, m;
int res[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}
}

int find(int cur) {
	if (cur == p[cur]) return cur;
	
	p[cur] = find(p[cur]);
	return p[cur];
}

void unionf(int x, int y) {
	x = find(x);
	y = find(y);
	
	p[y] = x;
}

int main() {
	init();
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &o[i]);
	}
	
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		
		if (p[from] != from) {
			unionf(to, from);
		}
		else p[from] = find(p[to]);
	}
	
	// sum of money in a group
	for (int i = 0; i < n; i++) {
		int root = find(i);
		res[root] += o[i];
	}
	
	for (int i = 0; i < n; i++) {		
		if (res[i] != 0) {
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	
	printf("POSSIBLE");	
	return 0;
}
