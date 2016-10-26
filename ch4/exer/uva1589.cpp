/*
** There are 2 boards. one for pieces, one for control distribution of red.
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

}

void setChariot(int x, int y) {

}

void setHorse(int x, int y) {

}

void setCannon(int x, int y) {

}

void getCheckMate() {

}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

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