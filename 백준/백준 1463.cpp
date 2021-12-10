// 1463 1로 만들기

#include <cstdio> 
using namespace std;

#define MAX 1000010
int nums[MAX * 3], n;

int main() {
	scanf("%d", &n);
	
	for (int i = 2; i <= n; i++) {
		nums[i] = MAX;
	}
	
	for (int i = 1; i < n; i++) {
		if (nums[i * 3] > nums[i] + 1) nums[i * 3] = nums[i] + 1;
		if (nums[i * 2] > nums[i] + 1) nums[i * 2] = nums[i] + 1;
		if (nums[i + 1] > nums[i] + 1) nums[i + 1] = nums[i] + 1;
	}
	
	printf("%d", nums[n]);
	
	return 0;
}
