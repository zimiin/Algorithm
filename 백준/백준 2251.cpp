// 2251번 물통

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define MAX 200 + 1

int A, B, C;	// size of each water bottle
bool possCase[MAX][MAX][MAX] = { 0 };	// possible cases
queue<pair<pair<int, int>, int>> q;	// use when traversing

void solution() {
	// initial case
	q.push(make_pair(make_pair(0, 0), C));

	while (!q.empty()) {
		int curA = q.front().first.first;
		int curB = q.front().first.second;
		int curC = q.front().second;
		q.pop();

		if (possCase[curA][curB][curC]) continue;
		possCase[curA][curB][curC] = true;

		// A to B
		if (curA + curB > B) q.push(make_pair(make_pair(curA + curB - B, B), curC));
		else q.push(make_pair(make_pair(0, curA + curB), curC));

		// A to C
		if (curA + curC > C) q.push(make_pair(make_pair(curA + curC - C, curB), C));
		else q.push(make_pair(make_pair(0, curB), curA + curC));

		// B to A
		if (curB + curA > A) q.push(make_pair(make_pair(A, curB + curA - A), curC));
		else q.push(make_pair(make_pair(curB + curA, 0), curC));

		// B to C
		if (curB + curC > C) q.push(make_pair(make_pair(curA, curB + curC - C), C));
		else q.push(make_pair(make_pair(curA, 0), curB + curC));

		// C to A
		if (curC + curA > A) q.push(make_pair(make_pair(A, curB), curC + curA - A));
		else q.push(make_pair(make_pair(curC + curA, curB), 0));

		// C to B
		if (curC + curB > B) q.push(make_pair(make_pair(curA, B), curC + curB - B));
		else q.push(make_pair(make_pair(curA, curC + curB), 0));
	}
}

void print() {
	bool ans[MAX] = { 0 };

	for (int b = 0; b < MAX; b++) {
		for (int c = 0; c < MAX; c++) {
			if (possCase[0][b][c]) ans[c] = true;
		}
	}

	for (int c = 0; c < MAX; c++) {
		if (ans[c]) cout << c << " ";
	}
	
	cout << endl;
}

int main() {
	cin >> A >> B >> C;
	solution();
	print();
	return 0;
}
