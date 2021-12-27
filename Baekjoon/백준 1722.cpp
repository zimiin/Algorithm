// 1722번 순열의 순서

#include <iostream>
using namespace std;

int N;	// 수의 개수

long long facto[21];
bool visited[21];

void cal_facto() {
	facto[0] = 1;

	for (int i = 1; i < 21; i++) {
		facto[i] = facto[i - 1] * i;
	}
}

void find_kthNum(long long k) {
	int result[20];

	for (int step = 1; step <= N; step++) {
		int no = 1;
		while (k > facto[N - step]) {
			k -= facto[N - step];
			no++;
		}

		int idx = 1;
		for (; idx <= N; idx++) {
			if (!visited[idx]) no--;
			if (no == 0) {
				visited[idx] = true;
				break;
			}
		}

		result[step - 1] = idx;
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
}

void find_seq(int seq[]) {
	long long order = 0;

	for (int step = 1; step <= N; step++) {
		visited[seq[step]] = true;
		
		int small = 0;
		for (int idx = 1; idx < seq[step]; idx++) {
			if (!visited[idx]) small++;
		}

		order += facto[N - step] * small;
	}

	cout << order + 1;
}

int main() {
	cin >> N;

	int cmd;
	cin >> cmd;

	// calculate factorial
	cal_facto();

	// execute command
	if (cmd == 1) {
		long long k;	
		cin >> k;

		// find the kth number and print it
		find_kthNum(k);
	}
	else {
		int input[21];
		for (int i = 1; i <= N; i++) {
			cin >> input[i];
		}

		// find the order of input sequence and print it
		find_seq(input);
	}

	return 0;
}
