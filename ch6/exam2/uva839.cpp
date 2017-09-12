# include <cstdio>
# include <cstring>
using namespace std;

int n, kase;

int dfs() {
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    if (wl == 0) wl = dfs();
    if (wr == 0) wr = dfs();
    if (wl < 0 || wr < 0) return -1;
    if (wl * dl != wr * dr) return -1;
    else return wl + wr;
}

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    scanf("%d", &n); kase = 0;
    while (n--) {
        if (kase++) printf("\n");
        int ans = dfs();
        if (ans < 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
