# include <cstdio>
# include <cstring>
# include <queue>
using namespace std;

const int maxn = 8 + 2;

struct Grid {
	int x, y;
};

int dx[8][2] = {
	{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
	{-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};

int b[maxn][maxn], v[maxn][maxn], ans;
char s[5], e[5];

void solve(void) {
	int sx = s[0]-'a', sy = s[1]-'1';
	int ex = e[0]-'a', ey = e[1]-'1';
	queue <Grid> q;
	Grid g; g.x = sx; g.y = sy; b[sx][sy] = 0;
	v[sx][sy] = 1;
	q.push(g);
	while (!q.empty()) {
		Grid bg = q.front(); q.pop();
		if (bg.x == ex && bg.y == ey) {
			ans = b[bg.x][bg.y]; break;
		}
		for (int i = 0; i < 8; i++) {
			int nx = bg.x + dx[i][0], ny = bg.y + dx[i][1];
			if (nx < 0 || ny < 0 || nx > 7 || ny > 7 || v[nx][ny] == 1) continue;
			Grid ng;
			ng.x = nx; ng.y = ny; b[ng.x][ng.y] = b[bg.x][bg.y] + 1;
			v[ng.x][ng.y] = 1;
			q.push(ng);
		}
	}
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%s%s", s, e) == 2) {
		ans = 0;
		memset(b, 0, sizeof(b));
		memset(v, 0, sizeof(v));
		solve();

		printf("To get from %s to %s takes %d knight moves.\n", s, e, ans);
	}
	return 0;
}