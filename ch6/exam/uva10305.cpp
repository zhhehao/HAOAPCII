# include <cstdio>
# include <cstring>

const int maxn = 100 + 5;

int g[maxn][maxn], n, m, v[maxn], ans[maxn], cnt;

void solve(int x) {
	for (int i = 1; i <= n; i++)
		if (g[x][i] == 1)
			solve(i);
	if (v[x] == 0) {
		ans[cnt++] = x;
		v[x] = 1;
	}
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	while (scanf("%d%d", &n, &m) == 2 && n) {
		memset(g, 0, sizeof(g));
		memset(ans, 0, sizeof(ans));
		memset(v, 0, sizeof(v));
		cnt = 0;
		int x, y;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			g[x][y] = 1;
		}

		for (int i = 1; i <= n; i++)
			if (v[i] == 0)
				solve(i);

		for (int i = cnt-1; i > 0; i--)
			printf("%d ", ans[i]);
		printf("%d\n", ans[0]);
	}
	return 0;
}