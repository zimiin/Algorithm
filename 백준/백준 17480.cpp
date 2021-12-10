// 17480번 개구쟁이 준석이

#include <iostream>
#include <set>
#include <string>

#define NUM_ALPH 'z' - 'a' + 1

using namespace std;

set<string> result;	// 만들 수 있는 모든 문자열 저장
int alph[NUM_ALPH];	// 준석이가 말한 알파벳 카드별 개수
int totalANum = 0;	// 총 알파벳카드 개수(
int subAlph[NUM_ALPH];	// substring의 알파벳 개수

int C;	// 카드의 종류의 개수
string orgStr;	// 준석이가 처음 만든 단어

// s의 알파벳 구성이 준석이가 말한 것과 같은지 확인
bool valid(string s) {
	// subAlph 0으로 초기화
	for (int i = 0; i < NUM_ALPH; i++) subAlph[i] = 0;

	// 개수 체크
	for (int i = 0; i < s.length(); i++) {
		subAlph[s[i] - 'a']++;
	}

	for (int i = 0; i < NUM_ALPH; i++) {
		if (alph[i] != subAlph[i]) {
			return false;
		}
	}

	return true;
}

// s의 [begin,end)를 역순으로 저장하는 함수
void reverse(string &s, int begin, int end) {
	string temp = s;
	
	for (int i = 0; i < end - begin; i++) {
		s[begin + i] = temp[end - i - 1];
	}
}

// 재귀함수
void recursion(string s, int begin, int end) {
	// 선택한 문자열 길이가 1이하
	if (end - begin <= 1) {
		result.insert(s);
		return;
	}

	int pos = begin + (end - begin) / 2;
	string temp;

	int count;
	if ((end - begin) % 2 == 0) count = 1;
	else count = 2;

	for (int i = 0; i < count; i++, pos++) {
		temp = s;
		
		// 앞쪽을 역순으로
		reverse(temp, begin, pos);
		recursion(temp, pos, end);

		temp = s;

		// 뒤쪽을 역순으로
		reverse(temp, pos, end);
		recursion(temp, begin, pos);
	}
}

// 정답 구하는 함수
int answer() {
	for (int i = 0; i <= orgStr.length() - totalANum; i++) {
		string sub = orgStr.substr(i, totalANum);
		
		if (valid(sub)) {
			recursion(sub, 0, totalANum);
		}
	}

	return result.size();
}



int main() {
	// 입력
	cin >> C;

	for (int i = 0; i < C; i++) {
		char ch;
		cin >> ch;
		cin >> alph[ch - 'a'];
		totalANum += alph[ch - 'a'];
	}

	cin >> orgStr;

	cout << answer() << endl;

	set<string>::iterator it;
	for (it = result.begin(); it != result.end(); it++) cout << *it << " ";

	return 0;
}
