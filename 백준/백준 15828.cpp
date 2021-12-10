// 백준 15828번 라우터

#include <iostream>
#include <queue>
using namespace std;


int main() {
	int N;	// 버퍼의 크기
	queue<int> buffer;	// 라우터 버퍼
	int in;	// input

	cin >> N;
	
	// 처리해야 할 정보
	while (true) {
		cin >> in;

		// 입력의 끝
		if (in == -1) {
			break;
		}
		// 패킷 처리
		else if (in == 0) {
			buffer.pop();
			continue;
		}

		// 패킷 들어옴
		// 버퍼 꽉 참
		if (buffer.size() == N) {
			continue;
		}

		// 버퍼에 저장
		buffer.push(in);
	}

	// 버퍼에 데이터 없음
	if (buffer.empty()) {
		cout << "empty";
		return 0;
	}

	// 버퍼 내용 출력
	while (!buffer.empty()) {
		cout << buffer.front() << " ";
		buffer.pop();
	}

	return 0;
}
