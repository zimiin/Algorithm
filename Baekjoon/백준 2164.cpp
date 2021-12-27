// 백준 2164번 카드 2

#include <iostream>
#include <queue>
using namespace std;


int main() {
	int N;
	queue<int> q;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	for (int i = 1; i < N; i++) {
		int num;

		// 카드 버리기
		q.pop();

		// 앞장 마지막으로 보내기
		num = q.front();
		q.pop();
		q.push(num);
	}

	cout << q.front();

	return 0;
}
