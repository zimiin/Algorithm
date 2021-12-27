// 백준 1012번 유기농 배추

#include <iostream>
#include <queue>
using namespace std;

bool field[50][50];
int N, M;	// 배추밭 세로, 가로

// 배추밭 정보 입력
void input_field() {
	int K;	// 배추 개수
	int x, y;

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		field[y][x] = true;
	}
}

// 배추밭 출력
void print_field() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << field[i][j] << " ";
		}
		cout << "\n";
	}
}

// 인덱스 y, x가 유효한지
bool valid(int y, int x) {
	// index out of range
	if (y < 0 || y >= N || x < 0 || x >= M) return false;

	// field[y][x]가 배추가 아님
	if (!field[y][x]) return false;

	return true;
}

// field[y][x]부터 BFS수행
void BFS(int y, int x) {
	queue<pair<int, int>> q;
	int ypos[4] = {-1, 0, 1, 0};
	int xpos[4] = {0, 1, 0, -1};

	q.push(make_pair(y, x));
	field[y][x] = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + ypos[i];
			int nx = x + xpos[i];

			if (valid(ny, nx)) {
				q.push(make_pair(ny, nx));
				field[ny][nx] = 0;
			}
		}
	}
}

// 필요한 지렁이 수 계산
int count_worm() {
	int worm = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 이미 방문했거나 배추가 아님
			if (field[i][j] != 1) continue;

			// 현재 위치부터 BFS수행
			BFS(i, j);

			// 지렁이 수 증가
			worm++;
		}
	}

	return worm;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		// 배추밭 정보 입력
		input_field();
		// 필요한 지렁이 수 출력
		cout << count_worm() << "\n";
	}

	return 0;
}
