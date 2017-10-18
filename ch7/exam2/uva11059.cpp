# include <cstdio>
# include <cstring>

# define LL long long

const int maxn = 18 + 2;
int n, seq[maxn];
LL ans_max, pro_max;

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int kase = 1;
    while (scanf("%d", &n) == 1) {
        ans_max = 0;
        for (int i = 0; i < n; i++) scanf("%d", &seq[i]);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pro_max = 1;
                for (int k = i; k <= j; k++) {
                    pro_max *= seq[k];
                }
                if (pro_max > ans_max) ans_max = pro_max;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", kase++, ans_max);
    }
    return 0;
}
