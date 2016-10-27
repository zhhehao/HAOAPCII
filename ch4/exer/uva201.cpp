/*
** use a struct array to simulate the graphic and cal
** pay attention, input h and v is different meaning.
*/

# include <cstdio>
# include <cstring>
using namespace std;

# define MAXN 11

struct Dots {
	int h, v;
	Dots (int h = 0, int v = 0) {
		this->h = h;
		this->v = v;
	}
};

int checkSide(int x1, int y1, int x2, int y2, char dir, const Dots dot[MAXN][MAXN]) {
	if (dir == 'H') {
		for (int i = y1; i < y2; i++) {
			if (dot[x1][i].h == 0)
				return 0;
		}
		return 1;
	}
	else {
		for (int i = x1; i < x2; i++) {
			if (dot[i][y1].v == 0)
				return 0;
		}
		return 1;
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, m, kase = 0;
	while(scanf("%d", &n) != EOF) {
		scanf("%d", &m);
		Dots square[MAXN][MAXN];

		char buf[3];
		int x, y;
		for (int i = 0; i < m; i++) {
			memset(buf, '\0', sizeof(buf));
			scanf("%s%d%d", buf, &x, &y);
			if (buf[0] == 'H')
				square[x][y].h = 1;
			else
				square[y][x].v = 1;
		}

		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= n; j++) {
		// 		printf("(%d, %d) ", square[i][j].h, square[i][j].v);
		// 	}
		// 	printf("\n");
		// }

		if (kase++)
			printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", kase);

		bool no_squares = true;

		for (int size = 1; size < n; size++) {
			int size_cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i+size > n || j+size > n) continue;
					if (!checkSide(i, j, i, j+size, 'H', square)) continue;
					if (!checkSide(i, j, i+size, j, 'V', square)) continue;
					if (!checkSide(i+size, j, i+size, j+size, 'H', square)) continue;
					if (!checkSide(i, j+size, i+size, j+size, 'V', square)) continue;
					size_cnt++;
					no_squares = false;
				}
			}
			if (size_cnt)
				printf("%d square (s) of size %d\n", size_cnt, size);
		}


		if(no_squares)
			printf("No completed squares can be found.\n");
	}
	return 0;
}
