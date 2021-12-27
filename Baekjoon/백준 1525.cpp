// 1525번 퍼즐

#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

#define GOAL 123456789

bool in_range(int x, int y) {
	if (x >= 0 && x < 3 && y >= 0 && y < 3) return true;
	else return false;
}

// make next number by swaping s[a] and s[b]
int make_next(string s, int a, int b) {
	char c = s[a];
	s[a] = s[b];
	s[b] = c;

	return stoi(s);
}

int answer(int start) {
	queue<int> q;
	map<int, int> visited;
	int cur, next;
	int idx, curX, curY, nextX, nextY;
	string curStr;

	int x[] = { -1, 0, 1, 0 };
	int y[] = { 0, 1, 0, -1 };

	if (start == GOAL) return 0;

	// BFS
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		curStr = to_string(cur);
		idx = curStr.find('9');

		curX = idx / 3;
		curY = idx % 3;

		for (int i = 0; i < 4; i++) {
			nextX = curX + x[i];
			nextY = curY + y[i];

			if (!in_range(nextX, nextY)) {
				continue;
			}

			// make next number by swaping s[a] and s[b]
			next = make_next(curStr, curX * 3 + curY, nextX * 3 + nextY);
			
			// arrive at the goal number
			if (next == GOAL) {
				return visited[cur] + 1;
			}

			if (!visited.count(next)) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	return -1;
}

int main() {
	int start = 0, num;

	for (int i = 0; i < 9; i++) {
		cin >> num;
		if (num == 0) num = 9;
		start = start * 10 + num;
	}

	cout << answer(start);

	return 0;
}
