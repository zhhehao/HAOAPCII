# include <cstdio>
# include <cstring>

const int maxn = 100 + 5;
int n, m, t, c[maxn], g[maxn][maxn], ans[maxn];

void solve(int u) {
    c[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[u][i] == 1 && c[i] == 0)
            solve(i);
    }
    ans[t--] = u;
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);

    while (scanf("%d%d", &n, &m) == 2 && n) {
        memset(g, 0, sizeof(g));
        memset(c, 0, sizeof(c));
        int n1, n2;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &n1, &n2);
            g[n1][n2] = 1;
        }
        t = n;
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) solve(i);
        }
        for (int i = 1; i < n; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
    return 0;
}
