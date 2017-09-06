# include <cstdio>
# include <cstring>

int T, D, I;

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &D, &I);
        int node = 1;
        for (int i = 1; i < D; i++) {
            node = I % 2 == 0 ? node * 2 + 1 : node * 2;
            if (I == 1) continue;
            I = I % 2 == 0 ? I / 2 : I / 2 + 1;
        }
        printf("%d\n", node);
    }
    return 0;
}
