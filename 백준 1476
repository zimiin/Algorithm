// 1476 날짜 계산

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

#define MAX_E 15
#define MAX_S 28
#define MAX_M 19

int E, S, M;
int year;

int main() {
	scanf("%d %d %d", &E, &S, &M);

	for (year = 1;; year++) {
		if (!((year - E) % MAX_E) && !((year - S) % MAX_S) && !((year - M) % MAX_M)) {
			break;
		}
	}

	printf("%d", year);

	return 0;
}
