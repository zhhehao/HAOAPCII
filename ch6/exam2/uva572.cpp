# include <cstdio>
# include <cstring>

const int maxn = 100 + 10;
int oil[maxn][maxn], m, n;
int d[2][8] = {{0, 0, -1, -1, -1, 1, 1, 1}, {1, -1, 1, -1, 0, 1, -1, 0}};

void solve(int x, int y) {
    oil[x][y] = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + d[0][i], ny = y + d[1][i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || oil[nx][ny] == 0) continue;
        solve(nx, ny);
    }
}

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    while (scanf("%d%d", &m, &n) == 2 && m) {
        char buff[maxn];
        memset(oil, 0, sizeof(oil));
        for (int i = 0; i < m; i++) {
            scanf("%s", buff);
            for (int j = 0; j < n; j++) {
                if (buff[j] == '@')
                    oil[i][j] = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (oil[i][j] == 1) {solve(i, j); ans++;}

        printf("%d\n", ans);
    }
    return 0;
}
