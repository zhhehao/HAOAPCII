# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

int n, a, last;
long long ans;

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (scanf("%d", &n) == 1 && n) {
        ans = 0; last = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            ans += abs(last);
            last += a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
