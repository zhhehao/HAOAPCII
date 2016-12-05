# include <cstdio>
# include <cstring>
# include <cmath>
# include <set>
# include <queue>
using namespace std;

const int maxn = 1000 + 5;

struct Oppo {
	double x, y, r, L, R;
	bool operator < (const Oppo &b) const {
		if (x == b.x)
			return y < b.y;
		else
			return x < b.x;
	}
};

Oppo op[maxn];
int g[maxn][maxn], n, vis[maxn];
set <int> top, left, bottom, right;
double L, R;

void input(void) {
	memset(op, 0, sizeof(op));
	memset(g, 0, sizeof(g));
	memset(vis, 0, sizeof(vis));
	top.clear(); left.clear(); bottom.clear(); right.clear();
	L = R = 1000.0;
	for (int i = 0; i < n; i++) {
		double &x = op[i].x, &y = op[i].y, &r = op[i].r;
		scanf("%lf%lf%lf", &x, &y, &r);
		if (y+r >= 1000.0) top.insert(i);
		if (y-r <= 0.0) bottom.insert(i);
		if (x+r >= 1000.0) {
			right.insert(i);
			op[i].R = y - sqrt(r*r-(1000.0-x)*(1000.0-x));
		}
		if (x-r <= 0.0) {
			left.insert(i);
			op[i].L = y - sqrt(r*r-x*x);
		}
		for (int j = 0; j < i; j++) {
			if ((x-op[j].x)*(x-op[j].x)+(y-op[j].y)*(y-op[j].y)-(r+op[j].r)*(r+op[j].r) <= 0.0)
				g[i][j] = g[j][i] = 1;
		}
	}
}

int solve() {
	set <int>::iterator it;
	for (it = top.begin(); it != top.end(); ++it) {
		if (vis[*it] == 0) {
			queue <int> q; q.push(*it);
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				vis[cur] = 1;
				if (bottom.count(cur)) return 1;
				if (left.count(cur)) {
					if (op[cur].L < L)
						L = op[cur].L;
				}
				if (right.count(cur)) {
					if (op[cur].R < R)
						R = op[cur].R;
				}
				for (int j = 0; j < n; j++) {
					if (g[cur][j] == 1 && vis[j] == 0)
						q.push(j);
				}
			}
		}
	}
	return 0;
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%d", &n) == 1) {
		input();
		if (solve() == 1)
			printf("IMPOSSIBLE\n");
		else {
			printf("0.00 %.2f 1000.00 %.2f\n", L, R);
		}
	}
	return 0;
}