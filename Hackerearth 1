#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

int main() {
	priority_queue<int> pq;
	int N;			// 배열 크기
	int A[MAX];		// 입력 배열
	int tmp[3];		// 곱 계산 시 사용
	long long mul;	// 각 인덱스에서의 곱 저장
	

	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	// -1 프린트
	cout << "-1\n" << "-1\n";

	// 큐에 삽입
	pq.push(A[0]);
	pq.push(A[1]);

	// 2번 인덱스부터 최대 3개 숫자의 곱 출력
	for (int i = 2; i < N; i++) {
		pq.push(A[i]);

		// 최댓값 3개의 곱 계산
		mul = 1;
		for (int i = 0; i < 3; i++) {
			tmp[i] = pq.top();
			pq.pop();

			mul *= tmp[i];
		}

		// 큐에 다시 넣어줌
		for (int i = 0; i < 3; i++) pq.push(tmp[i]);

		cout << mul << '\n';
	}

	return 0;
}
