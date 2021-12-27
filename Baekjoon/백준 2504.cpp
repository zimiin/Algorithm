// 2504번 괄호의 값

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Element {
public:
	bool isValue;
	int value;
	char command;

	Element() { }
	Element(int value) { isValue = true; this->value = value; }
	Element(char command) { isValue = false; this->command = command; }
};

string in;

int solution() {
	stack<Element> stk;
	Element e;

	for (int i = 0; in[i]; i++) {
		if (in[i] == '(' || in[i] == '[') {
			stk.push(*(new Element(in[i])));
		}
		else if (in[i] == ')') {
			int sum = 0;
			bool isValid = false;

			while (!stk.empty()) {
				e = stk.top();
				stk.pop();

				if (e.isValue) {
					sum += e.value;
					continue;
				}

				if (e.command == '(') {
					isValid = true;
					if (sum == 0) stk.push(*(new Element(2)));
					else stk.push(*(new Element(sum * 2)));
					break;
				}
				else return 0;
			}

			if (!isValid) return 0;
		}
		else if (in[i] == ']') {
			int sum = 0;
			bool isValid = false;

			while (!stk.empty()) {
				e = stk.top();
				stk.pop();

				if (e.isValue) {
					sum += e.value;
					continue;
				}

				if (e.command == '[') {
					isValid = true;
					if (sum == 0) stk.push(*(new Element(3)));
					else stk.push(*(new Element(sum * 3)));
					break;
				}
				else return 0;
			}

			if (!isValid) return 0;
		}
	}

	int res = 0;
	while (!stk.empty()) {
		if (!stk.top().isValue) return 0;

		res += stk.top().value;
		stk.pop();
	}

	return res;
}

int main() {
	cin >> in;
	cout << solution();
	return 0;
}
