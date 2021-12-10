// 11286 절댓값 힙

#include <cstdio> 
using namespace std;

int n, x;
int pq[100001], qSize = 0;

bool comp(int a, int b) {
	int absA = a < 0 ? -a : a;
	int absB = b < 0 ? -b : b;
	
	if (absA < absB) {
		return true;
	}
	else if (absA == absB) {
		return a < b ? true : false;
	}
	else {
		return false;
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void insert(int num) {
	pq[++qSize] = num;
	
	int cur = qSize, parent = cur / 2;
	while (cur > 1) {
		if (comp(pq[cur], pq[parent])) {
			swap(pq[cur], pq[parent]);
			cur = parent;
			parent = cur / 2;
		}
		else break;
	}
}

int top() {
	if (qSize == 0) return 0;
	
	int topVal = pq[1];
	pq[1] = pq[qSize];
	qSize--;
	
	int cur = 1, left = cur * 2, right = cur * 2 + 1;
	while (left <= qSize) {
		int minChild = left;
		if (right <= qSize && comp(pq[right], pq[left])) {
			minChild = right;
		}
		
		if (comp(pq[minChild], pq[cur])) {
			swap(pq[cur], pq[minChild]);
			cur = minChild;
			left = cur * 2; right = cur * 2 + 1;	
		}
		else break;
	}
	
	return topVal;
}

int main() {
	scanf("%d", &n);
	
	while (n--) {
		scanf("%d", &x);
		
		if (x != 0) {
			insert(x);
		}
		else {
			printf("%d\n", top());
		}
	}
	
	return 0;
}
