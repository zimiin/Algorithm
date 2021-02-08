// 5376번 소수를 분수로

#include <cstdio> 
#include <cmath>
using namespace std;
typedef long long ll;

int tc;
ll len1, len2, no1, no2;
ll num, denom, gcd;
char in_num[20];

ll getnum(char c) { return (ll)c - '0'; }

ll getgcd(ll a, ll b) {
	while (b != 0) {
		ll tmp = a;
		a = b;
		b = tmp % b;
	}	
	
	return a;
}

int main() {
	scanf("%d", &tc);
	
	for (int c = 0; c < tc; c++) {
		scanf("%s", in_num);
		
		// 0.6(142857) len1 : 1, len2 : 7, no1 : 6, no2 : 6142857
		len1 = 0; len2 = 0; no1 = 0; no2 = 0;
		int i = 2;
		
		// 괄호 전 
		for (; in_num[i]; i++) {
			if (in_num[i] == '(') {
				i++;
				break;
			}
			
			len1++; len2++;
			no1 = no1 * 10 + getnum(in_num[i]);
			no2 = no2 * 10 + getnum(in_num[i]);
		}
		
		// 괄호 
		for (; in_num[i]; i++) {
			if (in_num[i] == ')') {
				break;
			}
			
			len2++;
			no2 = no2 * 10 + getnum(in_num[i]);
		}
		
		if (len1 == len2) {
			// 유한소수 
			num = no1;
			denom = pow(10, len1);
		}
		else {
			// 무한소수 
			num = no2 - no1;
			denom = pow(10, len2) - pow(10, len1);
		} 
		
		// 약분
		gcd = getgcd(num, denom);
		
		printf("%lld/%lld\n", num / gcd, denom / gcd);
	}
	
	return 0;
}
