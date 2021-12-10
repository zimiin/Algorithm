// 백준 15903번 카드 합체 놀이

#include <iostream>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator() (long long a, long long b) {
		return a > b ? 1 : 0;
	}
};

int main() {
	int n, m;
	int card[1000];
	priority_queue<long long, vector<long long>, Compare> pq;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	// 게임 진행
	while (m--) {
		long long sum = 0;
		for (int i = 0; i < 2; i++) {
			sum += pq.top();
			pq.pop();
		}

		pq.push(sum);
		pq.push(sum);
	}

	// 점수 계산
	long long score = 0;
	while (!pq.empty()) {
		score += pq.top();
		pq.pop();
	}

	cout << score;

	return 0;
}
