# include <cstdio>
# include <cstring>

const int maxn = 100 + 10;
int L[maxn], R[maxn], Lmark, Rmark;

void solve(int p) {
    int v; scanf("%d", &v);
    if (v == -1) return;
    if (p < 0 && -p > Lmark) Lmark = -p;
    if (p >= 0 && p > Rmark) Rmark = p;
    solve(p-1); solve(p+1);
    if (p < 0) L[-p] += v;
    else R[p] += v;
}

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    int kase = 1, root;
    while (scanf("%d", &root) && root != -1) {
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        Lmark = Rmark = 0;
        R[0] = root;
        solve(-1); solve(1);
        printf("Case %d:\n", kase++);
        for (int i = Lmark; i > 0; i--) printf("%d ", L[i]);
        for (int i = 0; i < Rmark; i++) printf("%d ", R[i]);
        printf("%d\n\n", R[Rmark]);
    }
    return 0;
}
