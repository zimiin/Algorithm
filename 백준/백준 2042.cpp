// 2042번 구간합

#include <iostream>
#include <math.h>
using namespace std;

int N;	// 수의 개수
long long nums[2<<21];

int M, K;		// 각각 변경, 합 구하는 개수
long long a, b, c;	// 명령

int S;	// 리프노드 수

void print() {
	for (int i = 0; i < 2 * S; i++) cout << nums[i] << " ";
	cout << endl;
}

void input() {
	cin >> N >> M >> K;

	S = 1;
	while (S < N) S *= 2;
	
	for (int i = 0; i < N; i++) {
		cin >> nums[S + i];
	}
}

void makeTree() {
	for (int i = S - 1; i > 0; i--) {
		nums[i] = nums[i * 2] + nums[i * 2 + 1];
	}
}

void update(int node, int left, int right, int index, long long diff) {
	if (left > index || right < index) return;

	nums[node] += diff;

	if (left != right) {
		int mid = (left + right) / 2;
		update(node * 2, left, mid, index, diff);
		update(node * 2 + 1, mid + 1, right, index, diff);
	}
}

long long query(int node, int left, int right, int qLeft, int qRight) {
	if (qRight < left || right < qLeft) return 0;

	if (qLeft <= left && right <= qRight) return nums[node];

	int mid = (left + right) / 2;
	return query(node * 2, left, mid, qLeft, qRight) 
		+ query(node * 2 + 1, mid + 1, right, qLeft, qRight);
}

int main() {
	input();
	makeTree();

	for (int i = 0; i < M + K; i++) {
		// 명령 받기
		cin >> a >> b >> c;

		// 값 업데이트
		if (a == 1) {
			update(1, 1, S, b, c - nums[S - 1 + b]);
		}
		// 구간 합 구하기
		else {
			cout << query(1, 1, S, b, c) << '\n';
		}
	}

	return 0;
}
