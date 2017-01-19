# include <cstdio>
# include <cstring>
# include <set>
using namespace std;

const int maxn = 26 + 2;

// nb用来存储图，g用来存储递归的节点，s_g用来找出节点并排序
// ans用来存储结果，ansk用来存储最小带宽，n是节点的数量
int g[10][2], nb[maxn][maxn], ans[10], ansk, n, p[10];
char buf[100];
set <int> s_g;

// 用来把input转化并存储在nb数组中
void setg(int s, int e) {
    int p1 = buf[s]-'A', p2;
    s_g.insert(p1);
    for (int i = s+2; i <= e; i++) {
        p2 = buf[i]-'A';
        s_g.insert(p2);
        nb[p1][p2] = 1;
        nb[p2][p1] = 1;
    }
}

void solve(int d, int k) {
    int nk = k;
    if (d > 1) {
        for (int j = d-2; j >= 0; j--) {
            if (nb[p[d-1]][p[j]] == 1) {
                int dd = d-1-j;
                if (dd >= nk) nk = dd;
            }
        }
        if (nk >= ansk) return;
        if (d == n) {
            for (int i = 0; i < n; i++)
                ans[i] = p[i];
            ansk = nk;
        }
    }
    for (int i = 0; i < n; i++) {
        if (g[i][1] == 0) {
            p[d] = g[i][0];
            g[i][1] = 1;
            solve(d+1, nk);
            g[i][1] = 0;
        }
    }
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif
    for (;;) {
        fgets(buf, 100, stdin);

        if (buf[0] == '#') break;
        memset(g, 0, sizeof(g));
        memset(p, 0, sizeof(p));
        memset(nb, 0, sizeof(nb));
        memset(ans, 0, sizeof(ans));
        ansk = 10; n = 0;
        int cur = 0, len = strlen(buf)-1, se = 0; s_g.clear();
        while (cur < len) {
            while (buf[cur] != ';' && cur != len) cur++;
            setg(se, cur-1);
            cur++; se = cur;
        }
        n = s_g.size();
        set <int>::iterator it; cur = 0;
        for (it = s_g.begin(); it != s_g.end(); ++it) g[cur++][0] = *it;

        // 以上完成了input的转换，下面开始递归枚举并剪枝求解。
        solve(0, 0);

        // 以下输出结果
        for (int i = 0; i < n; i++) printf("%c ", ans[i]+'A');
        printf("-> %d\n", ansk);
    }
    return 0;
}
