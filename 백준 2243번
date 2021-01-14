// 2243번 사탕상자

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

int candies[2 << 20];
int n;
int A, B, C;

int S = 2 << 19;

void update(int node, int left, int right, int index, int diff) {
	if (index < left || right < index) {
		return;
	}

	candies[node] += diff;

	if (left == right) return;

	int mid = (left + right) / 2;
	update(node * 2, left, mid, index, diff);
	update(node * 2 + 1, mid + 1, right, index, diff);
}

int query(int node, int left, int right, int noCandy) {
	if (noCandy <= 0 || noCandy > candies[node]) {
		return 0;
	}

	if (left == right) {
		return left;
	}

	int mid = (left + right) / 2;
	return query(node * 2, left, mid, noCandy)
		+ query(node * 2 + 1, mid + 1, right, noCandy - candies[node * 2]);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &A, &B);
		
		// 사탕 꺼내기
		if (A == 1) {
			int idx = query(1, 1, S, B);
			printf("%d\n", idx);

			update(1, 1, S, idx, -1);
		}
		// 사탕 넣기
		else {
			scanf("%d", &C);			
			update(1, 1, S, B, C);
		}
	}

	return 0;
}
