// 1072번 게임

#include <iostream>
using namespace std;

int main() {
	long long X, Y;
	long long rate;

	cin >> X >> Y;
	rate = Y * 100 / X;
	
	if (rate >= 99) {
		cout << -1;
		return 0;
	}

	long long low = 1, high = 1000000000, mid;
	long long ans = 0;
	long long curRate;

	while (low <= high) {
		mid = (low + high) / 2;

		curRate = (Y + mid) * 100 / (X + mid);
		if (curRate > rate) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans;

	return 0;
}
