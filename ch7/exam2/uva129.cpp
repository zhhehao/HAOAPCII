# include <cstdio>
# include <cstring>

const int maxn = 80 + 5;
int n, L, ans[maxn], cnt, cur;

void _output() {
    for (int i = 0; i < cur; i++) {
        if (i % 64 == 0 && i != 0) printf("\n");
        else if (i % 4 == 0 && i != 0 && i % 64 != 0) printf(" ");
        printf("%c", ans[i]+'A');
    }
    printf("\n%d\n", cur);
}

bool is_hard(int cur) {
    if (cur == 0) return true;
    int len = cur % 2 == 1 ? (cur+1)/2 : cur/2;
    for (int i = 1; i <= len; i++) {
        int ok = 1;
        for (int j = 0; j < i; j++) {
            if (ans[cur-j] != ans[cur-i-j]) {
                ok = 0; break;
            }
        }
        if (ok)
            return false;
    }
    return true;
}

int solve() {
    if (cnt == n) {
        _output();
        return 1;
    }
    for (int i = 0; i < L; i++) {
        ans[cur] = i;
        if (is_hard(cur)) {
            cnt++;
            cur++;
            if (solve() == 1)
                return 1;
            cur--;
        }
    }
    return -1;
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (scanf("%d%d", &n, &L) == 2 && n) {
        cnt = 0; cur = 0;
        memset(ans, 0, sizeof(ans));
        solve();
    }
    return 0;
}
