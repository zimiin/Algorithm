// 2824번 최대공약수

#include <cstdio> 
#include <map>
#include <vector>
using namespace std;
typedef long long ll;

#define MAX 32000
#define MAX_GCD 1000000000

int n, m;
map<int, int> a, b;
ll gcd = 1;
bool visited[MAX], flag = 0;
vector<ll> prime;

void get_prime() {	
	for (int i = 2; i < MAX; i++) {
		if (visited[i]) continue;
		
		prime.push_back(i);
		for (int j = i * 2; j < MAX; j += i) {
			visited[j] = 1;
		}
	}
}

int getmin(int a, int b) { return a < b ? a : b; }

int main() {
	get_prime();
	
	scanf("%d", &n);
	while (n--) {
		int in;
		scanf("%d", &in);
		
		// prime factorization
		for (int i = 0; i < prime.size() && prime[i] * prime[i] <= in; i++) {
			while (in % prime[i] == 0) {
				a[prime[i]]++;
				in /= prime[i];
			}
		}
		
		a[in]++;
	}
	
	scanf("%d", &m);
	while (m--) {
		int in;
		scanf("%d", &in);
		
		// prime factorization
		for (int i = 0; i < prime.size() && prime[i] * prime[i] <= in; i++) {
			while (in % prime[i] == 0) {
				b[prime[i]]++;
				in /= prime[i];
			}
		}
		
		b[in]++;
	}
	
	// 최대공약수 구하기
	for (map<int,int>::iterator it = a.begin(); it != a.end(); it++) {
		int cur = it->first;
		
		int minNo = getmin(a[cur], b[cur]);

		while (minNo--) {
			gcd *= cur;

			if (gcd >= MAX_GCD) {
				flag = true;
				gcd %= MAX_GCD;
			}
		}
	}
	
	if (flag) printf("%09lld", gcd);
	else printf("%lld", gcd);
	
	return 0;
}
