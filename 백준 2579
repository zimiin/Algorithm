// 2579번 계단 오르기
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int n;
int step[310];
int max_point[310][2];	// 0은 현재가 한칸째, 1은 두칸째

int getmax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &step[i]);
	}

	// dp
	max_point[1][0] = step[1];
	max_point[2][0] = step[2];
	for (int i = 1; i < n; i++) {
		max_point[i + 1][1] = max_point[i][0] + step[i + 1];
		max_point[i + 2][0] = getmax(max_point[i][0], max_point[i][1]) + step[i + 2];
	}

	// 마지막 계단에서 둘 중 큰 값 출력
	printf("%d", getmax(max_point[n][0], max_point[n][1]));

	return 0;
}
