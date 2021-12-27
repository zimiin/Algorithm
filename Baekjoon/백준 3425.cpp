// 3425번 고스택

#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define MAX 1000000000

string prgrm[100001];
stack<int> stk;

int prgrmIn() {
	cin >> prgrm[0];
	if (prgrm[0] == "QUIT") return 0;
	if (prgrm[0] == "END") return 1;

	string no;
	if (prgrm[0] == "NUM") {
		cin >> no;
		prgrm[0].append(no);
	}

	int i = 0;
	do {
		i++;
		cin >> prgrm[i];

		if (prgrm[i] == "NUM") {
			cin >> no;
			prgrm[i].append(no);
		}
	} while (prgrm[i] != "END");

	return 1;
}

int exec() {
	for (int i = 0; prgrm[i] != "END"; i++) {
		if (prgrm[i] == "POP") {
			if (stk.empty()) return -1;
			stk.pop();
		}
		else if (prgrm[i] == "INV") {
			if (stk.empty()) return -1;
			
			int num = stk.top();
			stk.pop();
			stk.push(-1 * num);
		}
		else if (prgrm[i] == "DUP") {
			if (stk.empty()) return -1;

			stk.push(stk.top());
		}
		else if (prgrm[i] == "SWP") {
			if (stk.size() < 2) return -1;

			int no1 = stk.top();
			stk.pop();
			int no2 = stk.top();
			stk.pop();

			stk.push(no1);
			stk.push(no2);
		}
		else if (prgrm[i] == "ADD") {
			if (stk.size() < 2) return -1;

			long long no1 = stk.top();
			stk.pop();
			long long no2 = stk.top();
			stk.pop();

			if (no1 + no2 > MAX || no1 + no2 < -MAX) return -1;
			stk.push((int)(no1 + no2));
		}
		else if (prgrm[i] == "SUB") {
			if (stk.size() < 2) return -1;

			long long no1 = stk.top();
			stk.pop();
			long long no2 = stk.top();
			stk.pop();

			if (no2 - no1 > MAX || no2 - no1 < -MAX) return -1;
			stk.push((int)(no2 - no1));
		}
		else if (prgrm[i] == "MUL") {
			if (stk.size() < 2) return -1;

			long long no1 = stk.top();
			stk.pop();
			long long no2 = stk.top();
			stk.pop();

			if (no1 * no2 > MAX || no1 * no2 < -MAX) return -1;

			stk.push((int) no1*no2);
		}
		else if (prgrm[i] == "DIV") {
			if (stk.size() < 2) return -1;

			int no1 = stk.top();
			stk.pop();
			int no2 = stk.top();
			stk.pop();

			if (no1 == 0) return -1;

			int neg = 0;
			if (no1 < 0) neg++;
			if (no2 < 0) neg++;

			int sign = neg == 1 ? -1 : 1;

			// to positive number
			no1 = no1 < 0 ? no1 * -1 : no1;
			no2 = no2 < 0 ? no2 * -1 : no2;

			stk.push(sign*(no2 / no1));
		}
		else if (prgrm[i] == "MOD") {
			if (stk.size() < 2) return -1;

			int no1 = stk.top();
			stk.pop();
			int no2 = stk.top();
			stk.pop();

			if (no1 == 0) return -1;

			int sign = no2 < 0 ? -1 : 1;

			// to positive number
			no1 = no1 < 0 ? no1 * -1 : no1;
			no2 = no2 < 0 ? no2 * -1 : no2;

			stk.push(sign*(no2 % no1));
		}
		else { // NUM
			string no = prgrm[i].substr(3);
			stk.push(stoi(no));
		}
	}

	if (stk.size() != 1) return -1;
	else return 0;
}

int main() {
	int N;
	
	int num;
	int res;

	while (true) {
		if (!prgrmIn()) break;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> num;
			stk.push(num);

			// execute the program
			res = exec();
			if (res == -1) cout << "ERROR\n";
			else cout << stk.top() << '\n';

			// clear the stack
			while (!stk.empty()) stk.pop();
		}

		cout << endl;
	}

	return 0;
}
