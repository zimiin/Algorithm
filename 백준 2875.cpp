// 2875 대회 or 인턴
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int team = fmin(N / 2, M);

	K -= N - team * 2;
	K -= M - team;

	if (K > 0) {
		team -= ceil((float)K / 3);
	}

	if (team < 0) cout << 0;
	else cout << team;

	return 0;
}
