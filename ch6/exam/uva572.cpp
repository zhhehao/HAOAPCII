# include <cstdio>
# include <cstring>

const int maxn = 100 + 5;

int m, n, vis[maxn][maxn], ans;
char dep[maxn][maxn];

int dx[] = {-1, 0, 1};

void input(void) {
	memset(dep, '\0', sizeof(dep));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < m; i++) scanf("%s", dep[i]);
	ans = 0;
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (dx[i] == 0 && dx[j] == 0) continue;
			int nx = x + dx[i], ny = y + dx[j];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny] == 1 || dep[nx][ny] == '*') continue;
			dfs(nx, ny);
		}
}

void solve(void) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (dep[i][j] == '@' && vis[i][j] == 0) {
				ans++;
				dfs(i, j);
			}
	printf("%d\n", ans);
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%d%d", &m, &n) == 2 && m) {
		input();
		solve();
	}
	return 0;
}