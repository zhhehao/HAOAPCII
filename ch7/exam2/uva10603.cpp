# include <cstdio>
# include <cstring>
# include <queue>
using namespace std;

const int maxn = 200 + 5;

int t, c[3], d, ans_d, ans_w;
int vis[maxn][maxn];

struct State {
    int lit[3], w;
    bool operator < (const State& b) const {
        return b.w < w;
    }
};

void solve() {
    ans_d = 0; ans_w = 0;
    memset(vis, 0, sizeof(vis));
    vis[0][0] = 1;
    priority_queue <State> s;
    State s0;
    s0.lit[0] = 0;
    s0.lit[1] = 0;
    s0.lit[2] = c[2];
    s0.w = 0;
    s.push(s0);

    while (!s.empty()) {
        State sq = s.top(); s.pop();
        State nsq;

        for (int i = 0; i < 3; i++) {
            if (sq.lit[i] == d) {
                ans_d = d;
                ans_w = sq.w;
                return;
            }
            else if (sq.lit[i] > ans_d && sq.lit[i] < d) {
                ans_d = sq.lit[i];
                ans_w = sq.w;
            }
        }

        if (sq.lit[0] != 0) {
            if (sq.lit[1] != c[1] && c[1] - sq.lit[1] >= sq.lit[0]) {
                nsq.lit[0] = 0;
                nsq.lit[1] = sq.lit[1] + sq.lit[0];
                nsq.lit[2] = sq.lit[2];
                nsq.w = sq.w + sq.lit[0];
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                    vis[nsq.lit[0]][nsq.lit[1]] = 1;
                    s.push(nsq);
                }
            }
            else if (sq.lit[1] != c[1]) {
                nsq.lit[0] = sq.lit[0] - (c[1] - sq.lit[1]);
                nsq.lit[1] = c[1];
                nsq.lit[2] = sq.lit[2];
                nsq.w = sq.w + (c[1] - sq.lit[1]);
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                        vis[nsq.lit[0]][nsq.lit[1]] = 1;
                        s.push(nsq);
                }
            }

            if (sq.lit[2] != c[2] && c[2] - sq.lit[2] >= sq.lit[0]) {
                nsq.lit[0] = 0;
                nsq.lit[2] = sq.lit[2] + sq.lit[0];
                nsq.lit[1] = sq.lit[1];
                nsq.w = sq.w + sq.lit[0];
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                    vis[nsq.lit[0]][nsq.lit[1]] = 1;
                    s.push(nsq);
                }
            }
            else if (sq.lit[2] != c[2]) {
                nsq.lit[0] = sq.lit[0] - (c[2] - sq.lit[2]);
                nsq.lit[2] = c[2];
                nsq.lit[1] = sq.lit[1];
                nsq.w = sq.w + (c[2] - sq.lit[2]);
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                        vis[nsq.lit[0]][nsq.lit[1]] = 1;
                        s.push(nsq);
                }
            }
        }

        if (sq.lit[1] != 0) {
            if (sq.lit[0] != c[0] && c[0] - sq.lit[0] >= sq.lit[1]) {
                nsq.lit[1] = 0;
                nsq.lit[0] = sq.lit[0] + sq.lit[1];
                nsq.lit[2] = sq.lit[2];
                nsq.w = sq.w + sq.lit[1];
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                    vis[nsq.lit[0]][nsq.lit[1]] = 1;
                    s.push(nsq);
                }
            }
            else if (sq.lit[0] != c[0]) {
                nsq.lit[1] = sq.lit[1] - (c[0] - sq.lit[0]);
                nsq.lit[0] = c[0];
                nsq.lit[2] = sq.lit[2];
                nsq.w = sq.w + (c[0] - sq.lit[0]);
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                        vis[nsq.lit[0]][nsq.lit[1]] = 1;
                        s.push(nsq);
                }
            }

            if (sq.lit[2] != c[2] && c[2] - sq.lit[2] >= sq.lit[1]) {
                nsq.lit[1] = 0;
                nsq.lit[2] = sq.lit[2] + sq.lit[1];
                nsq.lit[0] = sq.lit[0];
                nsq.w = sq.w + sq.lit[1];
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                    vis[nsq.lit[0]][nsq.lit[1]] = 1;
                    s.push(nsq);
                }
            }
            else if (sq.lit[2] != c[2]) {
                nsq.lit[1] = sq.lit[1] - (c[2] - sq.lit[2]);
                nsq.lit[2] = c[2];
                nsq.lit[0] = sq.lit[0];
                nsq.w = sq.w + (c[2] - sq.lit[2]);
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                        vis[nsq.lit[0]][nsq.lit[1]] = 1;
                        s.push(nsq);
                }
            }
        }

        if (sq.lit[2] != 0) {
            if (sq.lit[1] != c[1] && c[1] - sq.lit[1] >= sq.lit[2]) {
                nsq.lit[2] = 0;
                nsq.lit[1] = sq.lit[1] + sq.lit[2];
                nsq.lit[0] = sq.lit[0];
                nsq.w = sq.w + sq.lit[2];
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                    vis[nsq.lit[0]][nsq.lit[1]] = 1;
                    s.push(nsq);
                }
            }
            else if (sq.lit[1] != c[1]) {
                nsq.lit[2] = sq.lit[2] - (c[1] - sq.lit[1]);
                nsq.lit[1] = c[1];
                nsq.lit[0] = sq.lit[0];
                nsq.w = sq.w + (c[1] - sq.lit[1]);
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                        vis[nsq.lit[0]][nsq.lit[1]] = 1;
                        s.push(nsq);
                }
            }

            if (sq.lit[0] != c[0] && c[0] - sq.lit[0] >= sq.lit[2]) {
                nsq.lit[2] = 0;
                nsq.lit[0] = sq.lit[2] + sq.lit[0];
                nsq.lit[1] = sq.lit[1];
                nsq.w = sq.w + sq.lit[2];
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                    vis[nsq.lit[0]][nsq.lit[1]] = 1;
                    s.push(nsq);
                }
            }
            else if (sq.lit[0] != c[0]) {
                nsq.lit[2] = sq.lit[2] - (c[0] - sq.lit[0]);
                nsq.lit[0] = c[0];
                nsq.lit[1] = sq.lit[1];
                nsq.w = sq.w + (c[0] - sq.lit[0]);
                if (vis[nsq.lit[0]][nsq.lit[1]] == 0) {
                        vis[nsq.lit[0]][nsq.lit[1]] = 1;
                        s.push(nsq);
                }
            }
        }

    }

    return;
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &c[0], &c[1], &c[2], &d);
        solve();
        printf("%d %d\n", ans_w, ans_d);
    }
    return 0;
}
