# include <cstdio>
# include <algorithm>
using namespace std;

const int maxn = 4000 + 10;
int t, n, kase, L[4][maxn], sum[maxn*maxn];

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    scanf("%d", &t);
    kase = 0;
    while (t--) {
        if (kase++) printf("\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &L[j][i]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum[cnt++] = L[0][i] + L[1][j];
            }
        }
        sort(sum, sum+cnt);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += upper_bound(sum, sum+cnt, -L[2][i]-L[3][j]) - lower_bound(sum, sum+cnt, -L[2][i]-L[3][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
