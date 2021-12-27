// 5567번 결혼식

#include <cstdio> 
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt = 0;
vector<int> friends[501];
bool visited[501];

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	
	for (int i = 0; i < friends[1].size(); i++) {
		int no = friends[1][i];
		visited[no] = true;
		
		for (int j = 0; j < friends[no].size(); j++) {
			int no2 = friends[no][j];
			visited[no2] = true;
		}
	}
	
	for (int i = 2; i <= n; i++) if (visited[i]) cnt++;
	
	printf("%d", cnt);
	return 0;
}
