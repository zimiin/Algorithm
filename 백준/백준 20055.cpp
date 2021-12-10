// 20055 컨베이어 벨트 위의 로봇

#include <cstdio> 
#include <list>
using namespace std;

int n, k, a[200], isRobot[200];
int noZero, phrase, up, down;

int nxtIdx(int cur, int diff) {
	return (cur + diff + 2 * n) % (2 * n);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n * 2; i++) {
		scanf("%d", &a[i]);
	}
	
	up = 0; down = n - 1;
	while (noZero < k) {
		
		phrase++;
		
		// 벨트 회전 
		up = nxtIdx(up, -1);
		down = nxtIdx(down, -1);
		
		// 로봇 이동 
		int idx = down;
		while (idx != up) {
			if (idx == down && isRobot[idx]) {
				isRobot[idx] = 0;
			}
			else if (isRobot[idx]) {
				int nxt = nxtIdx(idx, 1);
				
				if (a[nxt] > 0 && !isRobot[nxt]) {
					isRobot[idx] = 0;
					isRobot[nxt] = 1;
					
					a[nxt]--;
					
					if (a[nxt] == 0) noZero++;
					
					if (nxt == down) {
						isRobot[nxt] = 0;
					}
				}
			}
			idx = nxtIdx(idx, -1);
		}
		
		// 로봇 올리기
		if (!isRobot[up] && a[up] > 0) {
			isRobot[up] = 1;
			a[up]--;
			if (a[up] == 0) noZero++;
		}
	}
	
	printf("%d", phrase);
	
	return 0;
}
