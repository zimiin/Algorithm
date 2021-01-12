// 2143번 두 배열의 합

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000], B[1000];
vector<int> subA, subB;
int T, n, m;

void input() {
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];
}

void cal_sub() {
	// A 부 배열의 합 계산
	for (int i = 0; i < n; i++) {
		subA.push_back(A[i]);
		for (int j = i + 1; j < n; j++) {
			subA.push_back(subA.back() + A[j]);
		}
	}

	// B 부 배열의 합 계산
	for (int i = 0; i < m; i++) {
		subB.push_back(B[i]);
		for (int j = i + 1; j < m; j++) {
			subB.push_back(subB.back() + B[j]);
		}
	}
}

long long solution() {
	long long res = 0; // 결과값

	int pa = 0, pb = 0; // 각각 subA, subB 가리킴
	
	while (pa < subA.size() && pb < subB.size()) {
		if (subA[pa] + subB[pb] == T) {
			long long cntA = pa, cntB = pb;
			
			while (++cntA < subA.size() && subA[cntA] == subA[pa]);
			while (++cntB < subB.size() && subB[cntB] == subB[pb]);

			res += (cntA - pa)*(cntB - pb);
			
			pa = cntA;
			pb = cntB;
		}
		else if (subA[pa] + subB[pb] < T) {
			pa++;
		}
		else {	// subA[pa] + subB[pb] > T
			pb++;
		}
	}

	return res;
}

int main() {
	input();
	cal_sub();

	// sort subA in ascending order
	sort(subA.begin(), subA.end());
	// sort subB in descending order
	sort(subB.begin(), subB.end(), greater<int>());

	cout << solution();

	return 0;
}
