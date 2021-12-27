// 1920번 수 찾기

#include <cstdio> 
#include <algorithm>
#include <vector>
using namespace std;

int n[100000];
int noN, noM;

bool findf(int no) {
	int s = 0, e = noN - 1, m;
	m = (s + e)	/ 2;
	
	while (s <= e) {
		if (n[m] < no) s = m + 1;
		else if (n[m] > no) e = m - 1;
		else return true;
		
		m = (s + e) / 2;
	}
	
	return false;
}

int main() {
	// N에 들어있는 수 체크 
	scanf("%d", &noN);
	for (int i = 0; i < noN; i++) {
		scanf("%d", &n[i]);
	}
	
	sort(n, n + noN);
	
	// 답 확인
	scanf("%d", &noM);
	for (int i = 0; i < noM; i++) {
		int no;
		scanf("%d", &no);
		
		if (findf(no)) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}
