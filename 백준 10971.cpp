// 10971번 외판원 순회 2

#include <iostream>
#include <limits.h>
using namespace std;

int cost[10][10];
int N;	// no. of cities
int minCost = INT_MAX;	// the minimum cost
bool visited[10] = { 0 };


void to_false() {
	for (int i = 0; i < N; i++) visited[i] = false;
}

void traversal(int cur, int depart, int c, int depth) {
	// the last city
	if (depth == N) {
		if (!cost[cur][depart]) return;

		// add cost for moving to departure city
		c += cost[cur][depart];
		if (c < minCost) minCost = c;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && cost[cur][i]) {
			visited[i] = true;
			traversal(i, depart, c + cost[cur][i], depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		// set visited array values to 0
		to_false();

		visited[i] = true;
		traversal(i, i, 0, 1);
	}

	cout << minCost;

	return 0;
}
