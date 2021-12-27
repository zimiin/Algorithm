// 17609번 회문
 
#include <cstdio>
#include <cstring>
using namespace std;
 
int t;
char str[100001];

int minf(int a, int b) { return a < b ? a : b; }

int check(int s, int e, int deleted) {
	
	if (s >= e || deleted > 1) {
		return deleted;
	}
	
	if (str[s] == str[e]) {
		return check(s + 1, e - 1, deleted);	
	}
	else {
		return minf(check(s, e - 1, deleted + 1), check(s + 1, e, deleted + 1));
	}
}

int main() {
	scanf("%d", &t);
 	
	while (t--) {
		scanf("%s", str);
		int len = strlen(str);
		
		printf("%d\n", check(0, len - 1, 0));
	}

	return 0;
} 
