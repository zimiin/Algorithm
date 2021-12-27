// 2517번 달리기

#include <iostream>
#include <vector>
using namespace std;

class Runner {
public:
	int ability;
	int rank;

	Runner() {
		ability = 0;
		rank = 0;
	}

	Runner(int ability, int rank) {
		this->ability = ability;
		this->rank = rank;
	}
};

int N;
Runner runners[500000];
Runner temp[500000];	// use when sorting

int res[500001];	// save result

void input() {
	cin >> N;

	int in;
	for (int i = 0; i < N; i++) {
		cin >> in;
		runners[i].ability = in;
		runners[i].rank = i + 1;
		res[i + 1] = i + 1;
	}
}

void merge(int s, int m, int e) {
	int p1 = s, p2 = m + 1;
	int idx = s;

	while (p1 <= m && p2 <= e) {
		if (runners[p2].ability > runners[p1].ability) {
			res[runners[p2].rank] -= (m - p1 + 1);
			temp[idx++] = runners[p2++];
		}
		else {
			temp[idx++] = runners[p1++];
		}
	}

	while (p1 <= m) {
		temp[idx++] = runners[p1++];
	}

	while (p2 <= e) {
		temp[idx++] = runners[p2++];
	}

	// copy the result to vector runners
	for (idx = s; idx <= e; idx++) {
		runners[idx] = temp[idx];
	}
}

void mergeSort(int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
	
		mergeSort(s, mid);
		mergeSort(mid + 1, e);
		merge(s, mid, e);
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		cout << res[i] << '\n';
	}
}

int main() {
	input();
	mergeSort(0, N - 1);
	print();
	return 0;
};
