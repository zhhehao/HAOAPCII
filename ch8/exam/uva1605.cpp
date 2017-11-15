# include <cstdio>
# include <cstring>

int n, kase;
const int c[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102,
                 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
                 117, 118, 119, 120, 121, 122};
int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    kase = 0;
    while(scanf("%d", &n) == 1) {
        if (kase++) printf("\n");
        printf("2 %d %d\n", n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", c[i]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", c[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
