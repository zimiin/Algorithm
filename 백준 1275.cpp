// 1275번 커피숍2

#pragma warning(disable: 4996)

#include <iostream>
#include <algorithm>
using namespace std;

long long nums[2 << 18] = { 0 };
int N, Q, S;
long long x, y, a, b;

void init() {
	scanf("%d %d", &N, &Q);

	S = 1;
	while (S < N) S *= 2;

	for (int i = 0; i < N; i++) {
		scanf("%lld", &nums[S + i]);
	}
}

void make_tree() {
	for (int i = S - 1; i > 0; i--) {
		nums[i] = nums[i * 2] + nums[i * 2 + 1];
	}
}

void print() {
	for (int i = 0; i < 2 * S; i++) {
		printf("%lld ", nums[i]);
	}
	printf("\n");
}

long long query(int node, int left, int right, int qLeft, int qRight) {
	if (qLeft <= left && right <= qRight) {
		return nums[node];
	}
	else if (qRight < left || right < qLeft) {
		return 0;
	}
	
	int mid = (left + right) / 2;
	return query(node * 2, left, mid, qLeft, qRight)
		+ query(node * 2 + 1, mid + 1, right, qLeft, qRight);
}

void update(int node, int left, int right, int index, long long diff) {
	if (index < left || right < index) return;

	nums[node] += diff;

	if (left == right) return;
	
	int mid = (left + right) / 2;
	update(node * 2, left, mid, index, diff);
	update(node * 2 + 1, mid + 1, right, index, diff);
}

int main() {
	init();
	make_tree();
	
	for (int i = 0; i < Q; i++) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (x > y) swap(x, y);

		printf("%lld\n", query(1, 1, S, x, y));
		update(1, 1, S, a, b - nums[S + a - 1]);
	}
	return 0;
}
