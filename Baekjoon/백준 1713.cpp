// 1713번 후보 추천하기

#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	int no;	// 학생 번호
	int rcmd;	// 추천수
	int time;	// 최초 추천 시각

	Student() {
		no = 0;
		rcmd = 0;
		time = 0;
	}

	Student(int no, int rcmd, int time) {
		this->no = no;
		this->rcmd = rcmd;
		this->time = time;
	}
};

bool cmpNo(Student* a, Student* b) {
	if (a->no < b->no) return true;
	else return false;
}

bool cmpRcmdTime(Student* a, Student* b) {
	if (a->rcmd > b->rcmd) return true;
	else if (a->rcmd < b->rcmd) return false;

	// rcmd == s.rcmd
	if (a->time > b->time) return true;
	else return false;
}

int N, R;

Student* frame[100];	// 액자에 사진이 걸린 학생 정보
int fSize = 0;	// 사진 수

int in_frame(int no) {
	for (int i = 0; i < fSize; i++) {
		if (frame[i]->no == no) return i;
	}

	return -1;
}

void solution() {
	cin >> R;

	for (int r = 0; r < R; r++) {
		int no;
		cin >> no;

		int index = in_frame(no);

		// 이미 추천됨
		if (index != -1) {
			frame[index]->rcmd++;
			continue;
		}

		// 추천 안됨
		// 사진 틀 자리 남음
		if (fSize < N) {
			frame[fSize] = new Student(no, 1, r);
			fSize++;
			continue;
		}

		// 사진 틀 자리 없음
		sort(frame, frame + fSize, cmpRcmdTime);

		delete frame[fSize - 1];
		frame[fSize - 1] = new Student(no, 1, r);
	}
}

void print() {
	// sort the result and print it
	sort(frame, frame + fSize, cmpNo);

	for (int i = 0; i < fSize; i++) {
		cout << frame[i]->no << ' ';
	}
}

int main() {
	cin >> N;
	
	solution();
	print();

	return 0;
}
