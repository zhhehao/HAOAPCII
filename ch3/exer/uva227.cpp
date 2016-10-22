# include <cstdio>
# include <cctype>
using namespace std;

char board[5][10];
bool illegal;
int ex, ey;

int init() {
	fgets(board[0], 10, stdin);
	if (board[0][0] == 'Z')
		return 1;
	for (int i = 1; i < 5; i++) {
		fgets(board[i], 10, stdin);
	}
	// for (int i = 0; i < 5; i++)
	// 	printf("%s", board[i]);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] != 32) continue;
			ex = i;
			ey = j;
			return 0;
		}
	}
}

void move(char command) {
	int x, y;
	switch (command) {
		case 'A':
			x = ex - 1;
			y = ey;
			break;
		case 'B':
			x = ex + 1;
			y = ey;
			break;
		case 'L':
			x = ex;
			y = ey - 1;
			break;
		case 'R':
			x = ex;
			y = ey + 1;
			break;
	}
	if (x < 0 || x > 4 || y < 0 || y > 4) {
		illegal = true;
	}
	else {
		board[ex][ey] = board[x][y];
		board[x][y] = 32;
		ex = x;
		ey = y;
	}
}

void pr(int kase) {
	if (kase != 1)
		printf("\n");
	printf("Puzzle #%d:\n", kase);
	if (illegal)
		printf("This puzzle has no final configuration.\n");
	else {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%c ", board[i][j]);
			}
			printf("%c\n", board[i][4]);
		}
	}
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int kase = 1;
	for(;;) {
		if (init() == 1) break;
		char c;
		illegal = false;
		while((c = getchar()) != '0') {
			if (illegal || !isalpha(c)) continue;
			move(c);
		}
		getchar();
		pr(kase++);
	}
	return 0;
}
