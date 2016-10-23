# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 12
int cur_board[maxn][maxn], rows, cols;
char word_board[maxn][maxn];

void getInput() {
	getchar(); // remove "\n"
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%c", &word_board[i][j]);
		}
		getchar(); // remove "\n"
	}
}

void getCur() {
	memset(cur_board, 0, sizeof(cur_board));
	int num = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (word_board[i][j] == '*')
				cur_board[i][j] = -1;
			else if (i-1 < 0 || word_board[i-1][j] == '*' || j-1 < 0 || word_board[i][j-1] == '*')
				cur_board[i][j] = num++;
		}
	}
}

void putAcross() {
	printf("Across\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols;) {
			while(j < cols && cur_board[i][j] <= 0)
				j++;
			if (j == cols)
				break;
			printf("%3d.", cur_board[i][j]);
			while(j < cols && word_board[i][j] != '*') {
				printf("%c", word_board[i][j]);
				j++;
			}
			printf("\n");
		}
	}
}

void putDown() {
	printf("Down\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols;) {
			while(j < cols && cur_board[i][j] <= 0)
				j++;
			if (j == cols)
				break;
			printf("%3d.", cur_board[i][j]);
			int curRow = i;
			while(curRow < rows && word_board[curRow][j] != '*') {
				printf("%c", word_board[curRow][j]);
				cur_board[curRow][j] = 0;
				curRow++;
			}
			printf("\n");
		}
	}
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int kase = 0;
	while(scanf("%d%d",&rows, &cols) && rows) {
		getInput();
		getCur();
		if(kase++)
			printf("\n");
		printf("puzzle #%d:\n", kase);
		putAcross();
		putDown();
	}
	return 0;
}
