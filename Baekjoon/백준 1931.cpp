// 1931 회의실 배정

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) return a.first < b.first ? true : false;
	else return false;
}

int main() {
	int N;
	vector<pair<int, int>> time;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		time.push_back(make_pair(start, end));
	}

	sort(time.begin(), time.end(), cmp);

	int next = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (next <= time[i].first) {
			next = time[i].second;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
