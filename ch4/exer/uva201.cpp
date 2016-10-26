/*
** use a struct array to simulate the graphic and cal
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

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
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
				square[x][y].v = 1;
		}

		if (kase++)
			printf("\n**********************************\n");
		printf("Problem #%d\n\n", kase);

		bool no_squares = true;

		for (int i = 1; i <= n; i++) {

		}


		if(no_squares)
			printf("No completed squares can be found.\n");
	}
	return 0;
}
