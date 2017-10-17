# include <cstdio>
# include <cstring>

int n, num[10];

bool chk(char c[]) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 10; i++) {
        int val = c[i] - '0';
        num[val]++;
        if (num[val] > 1)
            return false;
    }
    return true;
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        if (kase++) printf("\n");
        bool no_result = true;
        char buff[20];
        int L;
        for (int i = 1234; i < 49383; i++) {
            // memset(buff, '\0', sizeof(buff));
            int b = i * n;
            if (i < 10000)
                L = sprintf(buff, "0%d%d", i, b);
            else
                L = sprintf(buff, "%d%d", i, b);
            if (L < 10) continue;
            if (L > 10) break;
            if (chk(buff)) {
                if (no_result) no_result = false;
                if (i < 10000)
                    printf("%d / 0%d = %d\n", b, i, n);
                else
                    printf("%d / %d = %d\n", b, i, n);
            }
        }
        if (no_result)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
