// 10826번 스택
#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
using namespace std;

template<typename T>
class Node {
public:
	T value;
	Node* front;

	Node() { value = NULL; front = NULL; }
	Node(T value, Node* front) { this->value = value; this->front = front; }
};

template<typename T>
class Stack {
public:
	Node<T>* topNode;
	int size;

	Stack();
	void push(T value);
	T pop();
	int getSize() { return size; }
	bool empty() {
		if (size == 0) return true;
		return false;
	}
	T top();
};

template<typename T>
T Stack<T>::top() {
	if (size < 1) return -1;
	return topNode->value;
}

template<typename T>
Stack<T>::Stack() {
	topNode = new Node<T>(NULL, NULL);
	size = 0;
}

template<typename T>
void Stack<T>::push(T value) {
	topNode = new Node<T>(value, topNode);
	size++;
}

template<typename T>
T Stack<T>::pop() {
	if (size < 1) return -1;

	T value = topNode->value;

	Node<T>* willDel = topNode;
	topNode = topNode->front;
	size--;

	delete willDel;
	return value;
}

int main() {
	int N;
	cin >> N;

	Stack<int> stk;
	char cmd[6];

	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);

		if (!strcmp(cmd, "push")) {
			int num;
			scanf("%d", &num);

			stk.push(num);
		}
		else if (!strcmp(cmd, "pop")) {
			printf("%d\n", stk.pop());
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", stk.getSize());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", stk.empty());
		}
		else {	// top
			printf("%d\n", stk.top());
		}
	}

	return 0;
}
