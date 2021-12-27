// 2805번 나무 자르기

#include <iostream>
using namespace std;

int N, M;
int trees[1000000];
int maxheight = 0;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];

		if (trees[i] > maxheight) maxheight = trees[i];
	}
}

long long length(int h) {
	long long sum = 0;
	
	for (int i = 0; i < N; i++) {
		if (trees[i] > h) sum += trees[i] - h;
	}

	return sum;
}

int solution() {
	int H;	// 톱날의 높이
	int low = 0, high = maxheight, mid;
	
	while (low <= high) {
		mid = (low + high) / 2;
		long long len = length(mid);

		if (len >= M) {
			H = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return H;
}

int main() {
	input();
	cout << solution();
	return 0;
}
