// 7569번 토마토

#include <iostream>
#include <queue>
using namespace std;

class coord {
public:
	int x;
	int y;
	int z;

	coord() {
		x = 0;
		y = 0;
		z = 0;
	}

	coord(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int M, N, H;
int tmt[100][100][100];
int unripeTmt = 0;

queue<coord> q;

int nx[6] = {0, 0, 0, 1, 0, -1};
int ny[6] = {0, 0, -1, 0, 1, 0};
int nz[6] = {1, -1, 0, 0, 0, 0};

bool in_range(int x, int y, int z) {
	if (x < M && y < N && z < H && x >= 0 && y >= 0 && z >= 0) {
		return true;
	}
	return false;
}

int solution() {
	if (unripeTmt == 0) {
		return 0;
	}

	coord cur;
	coord next;

	int day = 0;
	while (!q.empty()) {
		for (int i = q.size(); i > 0; i--) {
			cur.x = q.front().x;
			cur.y = q.front().y;
			cur.z = q.front().z;
			q.pop();

			for (int adj = 0; adj < 6; adj++) {
				next.x = cur.x + nx[adj];
				next.y = cur.y + ny[adj];
				next.z = cur.z + nz[adj];

				if (!in_range(next.x, next.y, next.z)) {
					continue;
				}

				if (tmt[next.z][next.y][next.x] == 0) {
					q.push(next);
					tmt[next.z][next.y][next.x] = 1;
					unripeTmt--;
				}
			}
		}
		day++;
		if (unripeTmt == 0) return day;
	}

	return -1;
}

int main() { 
	coord in;

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tmt[i][j][k];

				if (tmt[i][j][k] == 0) unripeTmt++;
				else if (tmt[i][j][k] == 1) {
					in.x = k;
					in.y = j;
					in.z = i;

					q.push(in);
				}
			}
		}
	}

	cout << solution();

	return 0;
}
