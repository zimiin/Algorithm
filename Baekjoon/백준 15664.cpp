// 15664번 N과 M (10)

#include <cstdio> 
#include <algorithm>
using namespace std;

int n, m, nums[8], used[8], res[8];

void recur(int idx, int len, int res[]) {
	if (len == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	
	int before = -1;
	for (int i = idx; i < n; i++) {
		if (before == nums[i]) continue;
		if (used[i]) continue;
		
		res[len] = nums[i];
		used[i] = true;
		
		recur(i + 1, len + 1, res);
		
		used[i] = false;
		before = nums[i];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	sort(nums, nums + n);
	
	recur(0, 0, res);
	
	return 0;
}
