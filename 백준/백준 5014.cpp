// 5014번 스타트링크

#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000000 + 1

int F, S, G, U, D;
int step[MAX];

queue<int> q;

int solution() {
	q.push(S);
	step[S] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (cur == G) break;

		if (cur + U <= F && step[cur + U] == -1) {
			step[cur + U] = step[cur] + 1;
			q.push(cur + U);
		}
		if (cur - D > 0 && step[cur - D] == -1) {
			step[cur - D] = step[cur] + 1;
			q.push(cur - D);
		}
	}

	return step[G];
}

void init() {
	for (int i = 0; i <= F; i++) {
		step[i] = -1;
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	init();

	int ans = solution();
	if (ans == -1) cout << "use the stairs";
	else cout << ans;

	return 0;
}
