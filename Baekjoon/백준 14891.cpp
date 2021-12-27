// 14891 톱니바퀴
#include <cstdio> 
using namespace std;

bool wheel[4][8];
int wheelIdx[4];

int nxtIdx(int cur, int diff) {
	return (cur + 8 + diff) % 8;
}

void moveLeft(int cur, int dir) {
	if (cur == 0) {
		wheelIdx[0] = nxtIdx(wheelIdx[0], -dir);
		return;
	}

	int nxt = cur - 1;
	int cur9 = nxtIdx(wheelIdx[cur], -2);
	int nxt3 = nxtIdx(wheelIdx[nxt], 2);

	if (wheel[cur][cur9] != wheel[nxt][nxt3]) {
		moveLeft(nxt, -dir);
	}

	wheelIdx[cur] = nxtIdx(wheelIdx[cur], -dir);
}

void moveRight(int cur, int dir) {
	if (cur == 3) {
		wheelIdx[3] = nxtIdx(wheelIdx[3], -dir);
		return;
	}

	int nxt = cur + 1;
	int cur3 = nxtIdx(wheelIdx[cur], 2);
	int nxt9 = nxtIdx(wheelIdx[nxt], -2);

	if (wheel[cur][cur3] != wheel[nxt][nxt9]) {
		moveRight(nxt, -dir);
	}

	wheelIdx[cur] = nxtIdx(wheelIdx[cur], -dir);
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &wheel[i][j]);
		}
	}

	int k;
	scanf("%d", &k);

	while (k--) {
		int dptrWhl, dir;
		scanf("%d %d", &dptrWhl, &dir);
		dptrWhl--;

		int dptrWhl12 = wheelIdx[dptrWhl];

		moveLeft(dptrWhl, dir);
		wheelIdx[dptrWhl] = dptrWhl12;
		moveRight(dptrWhl, dir);
	}

	// summarize score
	int sumScore = 0;
	for (int i = 0, score = 1; i < 4; i++, score *= 2) {
		if (wheel[i][wheelIdx[i]]) sumScore += score;
	}

	printf("%d", sumScore);

	return 0;
}
