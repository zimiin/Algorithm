// 16918 봄버맨

#include <cstdio> 
using namespace std;

int board[200][200];
int r, c, n;

int nr[4] = {0, 1, 0, -1};
int nc[4] = {1, 0, -1, 0};

void print_board() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == -1) printf(".");
			else printf("O");
		}
		printf("\n");
	}
}

void print_int_board() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
}

bool in_range(int x, int y) {
	if (x >= 0 && x < c && y >= 0 && y < r) return true;
	else return false;
}

int main() {
	scanf("%d%d%d", &r, &c, &n);
	for (int i = 0; i < r; i++) {
		char line[201];
		scanf("%s", line);
		
		for (int j = 0; j < c; j++) {			
			if (line[j] == '.') board[i][j] = -1;
			else board[i][j] = 0;
		}
	}
	
	if (n == 1) {
		print_board();
		return 0;
	}
	
	for (int time = 2; time <= n; time++) {
		
		if (!(time % 2)) {
			// 폭탄 놓기 
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] == -1) {
						board[i][j] = time;
					}
				}
			}
		}
		else {
			// 폭탄 터뜨리기 
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] == time - 3) {
						
						board[i][j] = -1;
						
						for (int k = 0; k < 4; k++) {
							int nrpos = i + nr[k];
							int ncpos = j + nc[k];
							
							if (in_range(ncpos, nrpos) && board[nrpos][ncpos] != (time - 3))
								board[nrpos][ncpos] = -1;
						}
					}
				}
			}
		}
	}
	
	print_board();
	
	return 0;
}
