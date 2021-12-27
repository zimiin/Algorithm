// 9202번 Boggle

#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
using namespace std;

class TrieNode {
public:
	TrieNode* child[26];
	bool isEnd;
	bool isHit;

	TrieNode() {
		isEnd = false;
		isHit = false;
	}

	bool hasChild(char c);
	TrieNode* getChild(char c);
	void clearHit(TrieNode* node);
};

bool TrieNode::hasChild(char c) {
	if (child[c - 'A']) return true;
	return false;
}

TrieNode* TrieNode::getChild(char c) {
	return child[c - 'A'];
}

void TrieNode::clearHit(TrieNode* node) {
	node->isHit = true;

	for (int i = 0; i < 26; i++) {
		if (node->child[i]) {
			clearHit(node->child[i]);
		}
	}
}

int w, b;
char boggle[4][4];

TrieNode* root = new TrieNode();
int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };

int point, noWords;	// 하나의 boggle에서 최대 점수, 찾은 단어의 수
char longWord[9];	// 가장 긴 단어

char curWord[9];	// 탐색 시 단어 저장용

int nr[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int nc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

bool visited[4][4] = { 0 };

void insert(char word[]) {
	TrieNode* cur = root;

	for (int i = 0; word[i]; i++) {
		int idx = word[i] - 'A';

		if (cur->child[idx] == NULL) {
			cur->child[idx] = new TrieNode();
		}
		cur = cur->child[idx];
	}
	cur->isEnd = true;
}

void in_words() {
	char word[9];

	scanf("%d", &w);
	for (int i = 0; i < w; i++) {
		scanf("%s", word);
		insert(word);
	}
}

void in_boggle() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%c", boggle[i][j]);
		}
	}
}

void updateResult(TrieNode* node, int len) {
	noWords++;
	point += score[len];
	
	if (len > strlen(longWord)) {
		strcpy(longWord, curWord);
	}
	else if (len == strlen(longWord)) {
		if (strcmp(longWord, curWord) > 0)
			strcpy(longWord, curWord);
	}
}

bool in_range(int r, int c) {
	if (r >= 0 && r < 4 && c >= 0 && c < 4) return true;
	else return false;
}

void DFS(int r, int c, int len, TrieNode* node) {
	visited[r][c] = true;
	curWord[len - 1] = boggle[r][c];
	
	if (node->isEnd && !node->isHit) {
		node->isHit = true;
		curWord[len] = '\0';
		updateResult(node, len);
	}
	
	for (int i = 0; i < 8; i++) {
		int nextR = r + nr[i];
		int nextC = c + nc[i];

		if (!in_range(nextR, nextC))
			continue;

		if (node->hasChild(boggle[nextR][nextC]) && !visited[nextR][nextC])
			DFS(nextR, nextC, len + 1, node->getChild(boggle[nextR][nextC]));
	}
	
	visited[r][c] = false;
}

void solution() {
	point = 0;
	noWords = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (root->hasChild(boggle[i][j])) 
				DFS(i, j, 1, root->getChild(boggle[i][j]));
		}
	}

	printf("%d %s %d\n", point, longWord, noWords);
	root->clearHit(root);
}

int main() {
	in_words();

	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		// boggle 입력
		in_boggle();

		// boggle에서 가능한 최대 점수, 가장 긴 단어, 찾은 단어 수 출력
		solution();
	}

	return 0;
}
