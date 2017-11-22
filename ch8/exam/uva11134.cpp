# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
using namespace std;

const int maxn = 5000 + 10;
int n;

struct Scope {
    int s1, s2, id;
    bool operator < (const Scope& b) const {
        if (s2 != b.s2)
            return s2 < b.s2;
        else
            return s1 < b.s1;
    }
};

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (scanf("%d", &n) == 1 && n) {
        vector <Scope> vx, vy;
        int x1, y1, x2, y2;
        Scope s;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            s.s1 = x1; s.s2 = x2; s.id = i;
            vx.push_back(s);
            s.s1 = y1; s.s2 = y2; s.id = i;
            vy.push_back(s);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());

        int ans_x[maxn], ans_y[maxn];

        int ok = 1, xp, yp;
        int vis_x[maxn], vis_y[maxn];
        memset(vis_x, 0, sizeof(vis_x));
        memset(vis_y, 0, sizeof(vis_y));
        for (int i = 0; i < n; i++) {
            xp = vx[i].s1;
            while (vis_x[xp] != 0) xp++;
            if (xp > vx[i].s2) {
                ok = 0; break;
            }
            yp = vy[i].s1;
            while (vis_y[yp] != 0) yp++;
            if (yp > vy[i].s2) {
                ok = 0; break;
            }
            ans_x[vx[i].id] = xp;
            ans_y[vy[i].id] = yp;
            vis_x[xp] = 1;
            vis_y[yp] = 1;

        }

        if (ok) {
            for (int i = 0; i < n; i++)
                printf("%d %d\n", ans_x[i], ans_y[i]);
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
