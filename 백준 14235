// 백준 14235번 크리스마스 선물

#include <iostream>
#include <queue>
using namespace std;


int main() {
	int n, a;
	priority_queue<int> present;

	cin >> n;

	while (n--) {
		cin >> a;

		// 아이 만남
		if (a == 0) {
			if (present.empty()) cout << -1 << '\n';
			else {
				cout << present.top() << '\n';
				present.pop();
			}

			continue;
		}

		// 선물 충전
		while (a--) {
			int cost;
			cin >> cost;
			present.push(cost);
		}
	}

	return 0;
}
