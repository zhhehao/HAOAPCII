/*
** There are 2 layers boards. one for pieces, one for control distribution of red.
** When get the final control distribution, can justify checkmate or not.
*/

# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 10

int pieces_board[12][11], control_board[12][11];
int n, black_x, black_y;

struct Pieces {
	int x, y;
	char name;
};

Pieces pieces[maxn];

void setGeneral(int x, int y) {
	for (int i = x - 1; i > 0; i--) {
		control_board[i][y] = 1;
		if (pieces_board[i][y] == 1) break;
	}
}

void setChariot(int x, int y) {
	for (int i = x - 1; i > 0; i--) {
		control_board[i][y] = 1;
		if (pieces_board[i][y] == 1) break;
	}
	for (int i = x + 1; i < 11; i++) {
		control_board[i][y] = 1;
		if (pieces_board[i][y] == 1) break;
	}
	for (int i = y - 1; i > 0; i--) {
		control_board[x][i] = 1;
		if (pieces_board[x][i] == 1) break;
	}
	for (int i = y + 1; i < 10; i++) {
		control_board[x][i] = 1;
		if (pieces_board[x][i] == 1) break;
	}
}

void setHorse(int x, int y) {
	if (x > 2 && pieces_board[x-1][y] != 1) {
		if (y > 1)
			control_board[x-2][y-1] = 1;
		if (y < 9)
			control_board[x-2][y+1] = 1;
	}
	if (x < 9 && pieces_board[x+1][y] != 1) {
		if (y > 1)
			control_board[x+2][y-1] = 1;
		if (y < 9)
			control_board[x+2][y+1] = 1;
	}
	if (y > 2 && pieces_board[x][y-1] != 1) {
		if (x > 1)
			control_board[x-1][y-2] = 1;
		if (x < 10)
			control_board[x+1][y-2] = 1;
	}
	if (y < 8 && pieces_board[x][y+1] != 1) {
		if (x > 1)
			control_board[x-1][y+2] = 1;
		if (x < 10)
			control_board[x+1][y+2] = 1;
	}
}

void setCannon(int x, int y) {
	for (int i = x - 1; i > 1; i--) {
		if (pieces_board[i][y] == 1) {
			for (int j = i - 1; j > 0; j--) {
				control_board[j][y] = 1;
				if (pieces_board[j][y] == 1)
					break;
			}
			break;
		}
	}
	for (int i = x + 1; i < 10; i++) {
		if (pieces_board[i][y] == 1) {
			for (int j = i + 1; j < 11; j++) {
				control_board[j][y] = 1;
				if (pieces_board[j][y] == 1)
					break;
			}
			break;
		}
	}
	for (int i = y - 1; i > 1; i--) {
		if (pieces_board[x][i] == 1) {
			for (int j = i - 1; j > 0; j--) {
				control_board[x][j] = 1;
				if (pieces_board[x][j] == 1)
					break;
			}
			break;
		}
	}
	for (int i = y + 1; i < 9; i++) {
		if (pieces_board[x][i] == 1) {
			for (int j = i + 1; j < 10; j++) {
				control_board[x][j] = 1;
				if (pieces_board[x][j] == 1)
					break;
			}
			break;
		}
	}
}

void getCheckMate() {
	bool is_checkmate = true;
	if (black_x > 1) {
		if (control_board[black_x-1][black_y] == 0) {
			is_checkmate = false;
			goto end;
		}
	}
	if (black_x < 3) {
		if (control_board[black_x+1][black_y] == 0) {
			is_checkmate = false;
			goto end;
		}
	}
	if (black_y > 4) {
		if (control_board[black_x][black_y-1] == 0) {
			is_checkmate = false;
			goto end;
		}
	}
	if (black_y < 6) {
		if (control_board[black_x][black_y+1] == 0) {
			is_checkmate = false;
			goto end;
		}
	}

end:
	if (is_checkmate)
		printf("YES\n");
	else
		printf("NO\n");
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);

	while(scanf("%d%d%d", &n, &black_x, &black_y) == 3 && n) {
		memset(pieces_board, 0, sizeof(pieces_board));
		memset(control_board, 0, sizeof(control_board));

		char piece_name[3];
		int red_x, red_y;
		for (int i = 0; i < n; i++) {
			memset(piece_name, '\0', sizeof(piece_name));
			scanf("%s%d%d", piece_name, &red_x, &red_y);
			pieces_board[red_x][red_y] = 1;
			pieces[i].x = red_x;
			pieces[i].y = red_y;
			pieces[i].name = piece_name[0];
		}

		for (int i = 0; i < n; i++) {
			switch (pieces[i].name) {
				case 'G': setGeneral(pieces[i].x, pieces[i].y); break;
				case 'R': setChariot(pieces[i].x, pieces[i].y); break;
				case 'H': setHorse(pieces[i].x, pieces[i].y); break;
				case 'C': setCannon(pieces[i].x, pieces[i].y); break;
			}
		}

		getCheckMate();
	}
	return 0;
}
