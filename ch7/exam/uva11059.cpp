# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

int n, s[20], kase;

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    kase = 1;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &s[i]);
        long long ans = -1;
        for (int i = 0; i < n; i++) {
            long long rec = s[i];
            ans = max(ans, rec);
            for (int j = i+1; j < n; j++) {
                rec *= s[j];
                ans = max(ans, rec);
            }
        }
        printf("Case #%d: The maximum product is ", kase++);
        if (ans < 0)
            printf("0.\n\n");
        else
            printf("%lld.\n\n", ans);
    }
    return 0;
}
