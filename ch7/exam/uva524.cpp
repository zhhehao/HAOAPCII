# include <cstdio>
# include <cstring>

int n, pt[35], ans[20], vis[20];
int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve(int cur) {
    if (cur == n) {
        for (int i = 0; i < n-1; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[n-1]);
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (vis[i] == 1) continue;
            if (cur == n-1) {
                if (pt[ans[cur-1]+i] != 1 || pt[i+1] != 1) continue;
            }
            if (pt[ans[cur-1]+i] != 1) continue;
            vis[i] = 1;
            ans[cur] = i;
            solve(cur+1);
            vis[i] = 0;
        }
    }
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    memset(pt, 0, sizeof(pt));
    for (int i = 0; i < 11; i++) pt[p[i]] = 1;
    int kase = 0;
    while (scanf("%d", &n) == 1) {
        if (kase++) printf("\n");
        printf("Case %d:\n", kase);
        memset(ans, 0, sizeof(ans));
        memset(vis, 0, sizeof(vis));
        ans[0] = 1;
        solve(1);
    }
    return 0;
}
