// 11279번 최대 힙

#include <cstdio> 
using namespace std;

int t[100001];
int s=0, n;

void print() {
	for(int i=1;i<=s;i++) printf("%d ", t[i]);
	printf("\n");
}
void swap(int& a, int& b) {
	int tmp=a;
	a=b;
	b=tmp;
}

int pop() {
	int top = t[1];
	
	t[1] = t[s];
	s--;
	
	int c = 1;
	
	while (true) {
		int m = c * 2;
		if (m > s) break;
		
		if(m + 1 <= s) {
			m = t[m + 1] > t[m] ? m + 1 : m;
		}
		
		if(t[c] < t[m]) {
			swap(t[c], t[m]);
			c = m;
		}
		else break;
	}
	
	return top;
}

void push(int x) {
	s++;
	t[s] = x;
	
	int p = s / 2;
	int c = s;
	
	while(c > 1 && t[c] > t[p]) {		
		swap(t[c], t[p]);
		c = p;
		p /= 2;
	}
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int cmd;
		scanf("%d", &cmd);
		
		if(cmd==0) {
			if(s==0) printf("0\n");
			else printf("%d\n", pop());
		}
		else {
			push(cmd);
		}
	}
	
	return 0;
}
