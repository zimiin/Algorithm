// 2606번 바이러스

#include <iostream>
#include <list>
using namespace std;

int N;	// no. of computers
list<int> graph[100 + 1];
bool visited[100 + 1] = { 0 };

void dfs(int cur) {
	list<int>::iterator it;
	for (it = graph[cur].begin(); it != graph[cur].end(); it++) {
		if (!visited[*it]) {
			visited[*it] = true;
			dfs(*it);
		}
	}
}

int answer() {
	int count = 0;

	visited[1] = true;
	dfs(1);
	
	for (int i = 1; i <= N; i++) {
		if (visited[i]) count++;
	}

	return count - 1;
}

int main() {
	int in;
	int node1, node2;
	cin >> N >> in;

	// build the tree
	while (in--) {
		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	cout << answer();

	return 0;
} 
