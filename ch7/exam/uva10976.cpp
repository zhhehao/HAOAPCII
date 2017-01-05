# include <cstdio>
# include <cstring>

const int maxn = 10000 + 5;

int k, cnt, x[maxn], y[maxn];

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    while (scanf("%d", &k) == 1) {
        cnt = 0;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        int end = 2*k;
        for (int i = k+1; i <= end; i++) {
            int a = k * i, b = i - k;
            if (a % b == 0) {
                x[cnt] = a / b;
                y[cnt] = i;
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
        }
    }
    return 0;
}
