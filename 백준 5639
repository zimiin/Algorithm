// 5639번 이진 검색 트리

#include <cstdio> 
using namespace std;

struct Node {
	int val;
	Node* lchld;
	Node* rchld;
	
	Node() {
		val=0;
		lchld=NULL;
		rchld=NULL;
	}
	Node(int val) {
		this->val=val;
		lchld=NULL;
		rchld=NULL;
	}
};

Node* t;
int vals[10000];
int valLen=0;

void insert_node(Node* cur, int idx) {
	if(vals[idx] < cur->val) {
		if(cur->lchld != NULL) {
			insert_node(cur->lchld, idx);
		}
		else {
			cur->lchld = new Node(vals[idx]);
			return;
		}
	}
	else {
		if(cur->rchld != NULL) {
			insert_node(cur->rchld, idx);
		}
		else {
			cur->rchld = new Node(vals[idx]);
			return;
		}
	}
}

void traversal(Node* cur) {	
	if(cur->lchld != NULL) {
		traversal(cur->lchld);
	}
	
	if(cur->rchld != NULL) {
		traversal(cur->rchld);
	}
	
	printf("%d\n", cur->val);
}

int main() {
	//freopen("test.txt", "r", stdin);
	
	while(scanf("%d", &vals[valLen])!=EOF) {
		valLen++;
	}
	
	t = new Node(vals[0]);
	for(int i=1;i<valLen;i++) {
		insert_node(t, i);		
	}
	
	traversal(t);
	
	return 0;
}
