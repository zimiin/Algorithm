// 6416 트리인가?

#include <cstdio> 
#include <vector>
using namespace std;

class Info {
public:
	bool flag;
	int in;
	vector<int> out;
	
	Info() {
		flag = false;
		in = 0;
	}	
};

vector<pair<int,int> > q;
vector<Info> g;
vector<bool> visited;
int len = 0, root;
bool is_tree = true;

int getmax(int a, int b) { return a > b ? a : b; }

void dfs(int cur) {
	if(visited[cur]) return;
	
	visited[cur] = true;
	
	for(int i = 0; i < g[cur].out.size(); i++) {
		dfs(g[cur].out[i]);
	}
}

int main() {
	for(int c = 1; ; c++) {
		q.clear();
		g.clear();
		visited.clear();
		len = 0;
		root = 0;
		is_tree = true;
		
		while(true) {
			int from, to;
			scanf("%d%d", &from, &to);
			
			if(from == -1 && to == -1) return 0;
			if(from == 0 && to == 0) break;
			
			q.push_back(make_pair(from, to));
			
			len = getmax(getmax(from, to), len);
		}
		
		if (q.size() == 0) {
			printf("Case %d is a tree.\n", c);
			continue;
		}
		
		g.resize(len + 1);
		visited.resize(len + 1, 0);
		
		// make tree
		for(int i = 0; i < q.size(); i++) {
			int from = q[i].first;
			int to = q[i].second;
			
			// check whether node 'to' already has incoming vertex
			if(g[to].in != 0) {
				is_tree = false;
				break;
			}
			
			// from --> to
			g[from].out.push_back(to);
			g[to].in = from; 
			
			g[from].flag = true;
			g[to].flag = true;
		}
		
		// check whether g graph is a tree
		// check no. of nodes which has indegree 0
		int cnt = 0;
		for (int i = 1; i <= len; i++) {
			if(!g[i].flag) continue;
			
			if(g[i].in == 0 ) {
				root = i;
				cnt++;
				
				if (cnt > 1) {
					is_tree = false;
					break;
				}
			}
		}
		
		// dfs
		dfs(root);
		
		// check whether all nodes were visited
		for (int i = 1; i <= len; i++) {
			if (!g[i].flag) continue;
			
			if (!visited[i]) {
				is_tree = false;
				break;
			}
		}
		
		if (is_tree) {
			printf("Case %d is a tree.\n", c);	
		} else {
			printf("Case %d is not a tree.\n", c);	
		}
	}
	
	return 0;
}
