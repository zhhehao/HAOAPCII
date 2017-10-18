# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

int k, cnt;

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (scanf("%d", &k) == 1) {
        cnt = 0;
        vector <int> x, y;
        int start = k+1, end = 2*k;
        for (int i = start; i <= end; i++) {
            if (k*i % (i-k) == 0) {
                int xt = k*i/(i-k);
                if (xt >= i) {
                    cnt++;
                    x.push_back(xt);
                    y.push_back(i);
                }
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < x.size(); i++) {
            printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
        }
    }
    return 0;
}
