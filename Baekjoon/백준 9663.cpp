// 9663번 N-Queen

#include <cstdio> 
#include <cmath>
using namespace std;

#define MAX 15

int n, ans = 0;
int col[MAX];

bool promising(int row) {
	bool flag = true;
	for(int r=0; r < row && flag; r++) {
		if((col[r] == col[row]) || ((row - r) == abs(col[row] - col[r]))) {
			flag = false;	
		}
	}
	return flag;
}

void nQueen(int row) {	
	if (promising(row)) {
		if (row == n - 1) {
			ans++;
			return;
		}
		
		for(int c=0; c<n; c++) {
			col[row + 1] = c;
			nQueen(row + 1);
		}
	}
}


int main() {
	scanf("%d",&n);
	
	for(int c=0; c<n; c++) {
		col[0]=c;
		nQueen(0);
	}
	
	printf("%d", ans);
	return 0;
}
