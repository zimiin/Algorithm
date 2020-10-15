// 백준 1697 숨바꼭질

#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000 + 1
int N, K;

int answer() {
	if (N == K) return 0;

	bool visited[MAX] = { 0 };
	queue<int> q;
	int qFront, sec = 0;
	int next[3];

	// BFS
	visited[N] = true;
	q.push(N);
	while (!q.empty()) {
		int times = q.size();
		for (int count = 0; count < times; count++) {
			qFront = q.front();
			q.pop();

			next[0] = qFront - 1;
			next[1] = qFront + 1;
			next[2] = qFront * 2;

			for (int i = 0; i < 3; i++) {
				if (next[i] >= 0 && next[i] < MAX && !visited[next[i]]) {
					if (next[i] == K) return sec + 1;

					visited[next[i]] = true;
					q.push(next[i]);
				}
			}
		}

		sec++;
	}

	return -1;
}

int main() {
	cin >> N >> K;
	cout << answer();
}
