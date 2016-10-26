/*
** b is board, n is numbers of pieces;
** r, c are black general's positon.
** Point p be used to storage red pieces.
*/
# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 10

int b[12][11];
int n, r, c;

struct Point {
	int x, y;
	char name;
};

Point p[maxn];

void putMate() {
	bool is_checkmate = false;
	if (r == 1 && c == 4)
		if (b[1][5] > 0 && b[2][4] > 0) is_checkmate = true;
	else if (r == 1 && c == 5)
		if (b[1][4] > 0 && b[1][6] > 0 && b[2][5] > 0) is_checkmate = true;
	else if (r == 1 && c == 6)
		if (b[1][5] > 0 && b[2][6] > 0) is_checkmate = true;
	else if (r == 2 && c == 4)
		if (b[1][4] > 0 && b[3][4] > 0 && b[2][5] > 0) is_checkmate = true;
	else if (r == 2 && c == 5)
		if (b[2][4] > 0 && b[2][6] > 0 && b[1][5] > 0 && b[3][5] > 0) is_checkmate = true;
	else if (r == 2 && c == 6)
		if (b[1][6] > 0 && b[3][6] > 0 && b[2][5] > 0) is_checkmate = true;
	else if (r == 3 && c == 4)
		if (b[2][4] > 0 && b[3][5] > 0) is_checkmate = true;
	else if (r == 3 && c == 5)
		if (b[3][4] > 0 && b[3][6] > 0 && b[2][5] > 0) is_checkmate = true;
	else if (r == 3 && c == 6)
		if (b[2][6] > 0 && b[3][5] > 0) is_checkmate = true;
end:
	if (is_checkmate)
		printf("YES\n");
	else
		printf("NO\n");
}

void checkControl() {
	for (int i = 0; i < n; i++) {
		if (p[i].name == 'G') {
			bool is_blocked = false;
			for (int j = 3; j < p[i].x; j++) {
				if (b[j][p[i].y] < 0) {
					is_blocked = true;
					break;
				}
			}
			if (is_blocked) continue;
			if (b[2][p[i].y] < 0)
				if (b[3][p[i].y] == 0)
					b[3][p[i].y] = 1;
			else if (b[1][p[i].y] < 0) {
				if (b[3][p[i].y] == 0)
					b[3][p[i].y] = 1;
				if (b[2][p[i].y] == 0)
					b[2][p[i].y] = 1;
			}
			else {
				if (b[3][p[i].y] == 0)
					b[3][p[i].y] = 1;
				if (b[2][p[i].y] == 0)
					b[2][p[i].y] = 1;
				if (b[1][p[i].y] == 0)
					b[1][p[i].y] = 1;
			}
		}
		else if (p[i].name == 'R') {
			int rx = p[i].x, ry = p[i].y;
			for (int j = rx - 1; j > 0; j--) {
				if (b[j][ry] == -1) break;
				b[j][ry] = 1;
			}
			for (int j = rx + 1; j < 11; j++) {
				if (b[j][ry] == -1) break;
				b[j][ry] = 1;
			}
		}
		else if (p[i].name == 'H') {

		}
		else if (p[i].name == 'C') {

		}
	}
}

void getRedPieces() {
	char t[3];
	for (int i = 0; i < n; i++) {
		memset(t, '\0', sizeof(t));
		scanf("%s%d%d", t, &p[i].x, &p[i].y);
		p[i].name = t[0];
		b[p[i].x][p[i].y] = -1;
	}
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	while(scanf("%d%d%d", &n, &r, &c) == 3 && n) {
		memset(b, 0, sizeof(b));
		getRedPieces();
		checkControl();
		putMate();
	}
	return 0;
}