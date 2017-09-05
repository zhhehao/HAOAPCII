# include <cstdio>
# include <cstring>
using namespace std;

const int maxn = 100000 + 10;
int n, m, L[maxn], R[maxn], kase;
bool reverse;

void rm(int box) {
    R[L[box]] = R[box];
    L[R[box]] = L[box];
}

void c1(int p1, int p2) {
    R[L[p2]] = p1; L[p1] = L[p2]; R[p1] = p2; L[p2] = p1;
}

void c2(int p1, int p2) {
    L[R[p2]] = p1; R[p1] = R[p2]; L[p1] = p2; R[p2] = p1;
}

void c3(int p1, int p2) {
    if (R[p1] == p2) {
        rm(p1);
        c2(p1, p2); return;
    }
    if (L[p1] == p2) {
        rm(p1);
        c1(p1, p2); return;
    }
    int L1 = L[p1], L2 = L[p2];
    rm(p1); rm(p2);
    c2(p1, L2); c2(p2, L1);
}

void pr() {
    int cur = R[0], cnt = 0;
    while (cnt < n) {
        printf("%d ", cur);
        cur = R[cur];
        cnt++;
    }
    printf("\n");
}

int main(void) {

    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    kase = 1;
    while (scanf("%d%d", &n, &m) == 2) {
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        for (int i = 1; i <= n; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[0] = 1; R[n] = 0; reverse = false;

        int c, p1, p2;
        for (int i = 0; i < m; i++) {
            scanf("%d", &c);
            if (c != 4) scanf("%d%d", &p1, &p2);
            if (reverse) {
                if (c == 1) c = 2;
                else if (c == 2) c = 1;
            }
            switch (c) {
                case 1: if (L[p2] != p1) {rm(p1); c1(p1, p2);} break;
                case 2: if (R[p2] != p1) {rm(p1); c2(p1, p2);} break;
                case 3: c3(p1, p2); break;
                case 4: reverse = reverse ? false : true; break;
            }
        }
        long long sum = 0;
        int cur = R[0], cnt = 0;
        bool odd = true;
        while (cnt < n) {
            if (odd) {
                sum += cur;
                odd = false;
                // printf("%d\n", cur);
            }
            else odd = true;
            cnt++;
            cur = R[cur];
        }
        if (reverse && n % 2 == 0) {
            sum = (long long)n * (n + 1) / 2 - sum;
        }
        printf("Case %d: %lld\n", kase++, sum);
    }
    return 0;
}
