// 1927번 최소 힙

#include <iostream>
#include <algorithm>
using namespace std;

int heap[1000001] = { 0 };
int hsize = 1;

void insNode(int value) {
	heap[hsize] = value;
	hsize++;

	int cur = hsize - 1;
	int parent = cur / 2;

	while (true) {
		if (cur == 1 || heap[parent] <= heap[cur]) {
			break;
		}

		swap(heap[parent], heap[cur]);
		cur = parent;
		parent = cur / 2;
	}
}

int delNode() {
	if (hsize < 2) return 0;

	int top = heap[1];
	heap[1] = heap[hsize - 1];
	hsize--;

	int cur = 1;

	while (true) {
		int lpos = cur * 2;
		int rpos = cur * 2 + 1;

		if (lpos >= hsize) break;

		int minVal = heap[lpos];
		int minPos = lpos;

		if (rpos < hsize && heap[rpos] < minVal) {
			minPos++;
			minVal = heap[minPos];
		}

		if (heap[cur] <= minVal) break;

		swap(heap[cur], heap[minPos]);
		cur = minPos;
	}

	return top;
}

int main() {
	int N;
	cin >> N;

	int op;
	for (int i = 0; i < N; i++) {
		scanf("%d", &op);

		if (op == 0) printf("%d\n", delNode());
		else insNode(op);
	}

	return 0;
}
