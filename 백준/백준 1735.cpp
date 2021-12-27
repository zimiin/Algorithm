 // 1735번 분수 합 
 
 #include <cstdio>
 using namespace std;
 
 int n1, n2, d1, d2;	// numerator, denominator
 int nans, dans; 
 
 int main() {
 	scanf("%d%d%d%d", &n1, &d1, &n2, &d2);
 	
 	nans = n1 * d2 + n2 * d1;
 	dans = d1 * d2;
 	
 	int gcd = nans, remain = dans;
 	while(remain > 0) {
	 	int tmp = remain;
 		remain = gcd % remain;
		gcd = tmp; 			
	}
 	
 	printf("%d %d", nans / gcd, dans / gcd);
 	return 0;
 } 
