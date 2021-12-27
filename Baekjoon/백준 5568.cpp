// 5568번 카드 놓기

#include <cstdio> 
#include <map>
using namespace std;

int card[10], n, k;
bool used[10];
map<int, int> nums;

void recur(int num, int idx) {
	if (idx == k) {
		nums[num]++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		
		used[i] = true;
		
		int tmp = num * 10;
		if (card[i] >= 10) tmp *= 10;
		
		recur(tmp + card[i], idx + 1);
		
		used[i] = false;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	
	recur(0, 0);
	
	printf("%d", nums.size());
	
	return 0;
}
