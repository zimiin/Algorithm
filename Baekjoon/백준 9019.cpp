// 9019 DSLR

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX 10000

int A, B;
bool visited[MAX];
queue<pair<string, int>> q;	// "command", "number"

int D(int cur) {
	int next = cur * 2;
	
	if (next >= MAX) return next % MAX;
	else return next;
}

int S(int cur) {
	int next = cur - 1;

	if (next == -1) return MAX - 1;
	else return next;
}

int L(int cur) {
	return (cur % 1000) * 10 + (cur / 1000);
}

int R(int cur) {
	return cur / 10 + (cur % 10) * 1000;
}

void to_false() {
	for (int i = 0; i < MAX; i++) 
		visited[i] = false;
}

void empty_q() {
	while (!q.empty())
		q.pop();
}


string answer() {
	string dslr[4] = { "D", "S", "L", "R" };
	int(*func[4]) (int num);
	
	func[0] = D;
	func[1] = S;
	func[2] = L;
	func[3] = R;

	// set visited array values to false
	to_false();
	// empty the queue
	empty_q();

	q.push(make_pair("", A));
	visited[A] = true;

	// BFS
	while (!q.empty()) {
		string cmd = q.front().first, temp;
		int num = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next = func[i](num);
			temp = cmd;

			if (next == B) return temp.append(dslr[i]);

			if (!visited[next]) {
				visited[next] = true;
				q.push(make_pair(temp.append(dslr[i]), next));
			}
		}
	}
	
	return "";
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> A >> B;
		cout << answer() << '\n';
	}

	return 0;
}
