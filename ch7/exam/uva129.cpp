# include <cstdio>
# include <cstring>

const int maxn = 80 + 5;

int n, L, cnt;
char seq[maxn];

void pr(int d) {
    for (int i = 0; i < d; i++) {
        if (i%4 == 0 && i!=64 && i!=0) printf(" ");
        printf("%c", seq[i]);
        if (i == 63 && d > 64) printf("\n");
    }
    printf("\n%d\n", d);
}

int chk(int d) {
    int ok;
    for (int i = 1; i*2 <= d+1; i++) {
        ok = 0;
        for (int j = 0; j < i; j++) {
            if (seq[d-j-1] != seq[d-i-j-1]) {
                ok = 1; break;
            }
        }
        if (ok == 0) break;
    }
    if (ok) return 1;
    else return 0;
}

int solve(int d) {
    for (int i = 0; i < L; i++) {
        seq[d-1] = i+'A';
        if (d != 1 && seq[d-2] == i+'A') continue;
        if (d == 1 || chk(d)) {
            cnt++;
            if (cnt == n) {pr(d); return 1;}
            if (solve(d+1) == 1) return 1;
        }
    }
    return 0;
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    while (scanf("%d%d", &n, &L) == 2 && n) {
        memset(seq, '\0', sizeof(seq));
        cnt = 0;
        solve(1);
    }
    return 0;
}
