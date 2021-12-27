// 1167 트리의 지름

#pragma warning(disable: 4996)

#include <iostream>
#include <list>
using namespace std;

#define MAX 100000 + 1

int V;	// no. of nodes in a tree
list<pair<int, int>> tree[MAX];
bool visited[MAX] = { 0 };	// using when traversing
int maxNode;	// be the start node of second traversal
int maxWght = 0;	// maximum sum of weight in the path

void DFS(int node, int weight) {
	if (visited[node]) {
		return;
	}

	visited[node] = true;

	if (weight > maxWght) {
		maxWght = weight;
		maxNode = node;
	}

	list<pair<int, int>>::iterator it;
	for (it = tree[node].begin(); it != tree[node].end(); ++it) {
		DFS(it->first, weight + it->second);
	}
}

int main() {
	scanf("%d", &V);

	// build a tree
	for (int i = 0; i < V; i++) {
		int node1;
		scanf("%d", &node1);

		while (true) {
			int node2;
			scanf("%d", &node2);

			if (node2 == -1) {
				break;
			}

			int weight;
			scanf("%d", &weight);

			tree[node1].push_back(make_pair(node2, weight));
		}
	}

	// find the longest path in the tree
	DFS(1, 0);

	// set values of visited array to 0
	for (int i = 0; i <= V; i++) {
		visited[i] = 0;
	}

	// second traversal
	DFS(maxNode, 0);

	// print the answer
	printf("%d", maxWght);

	return 0;
}
