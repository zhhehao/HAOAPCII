# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

const int maxn = 100000 + 10;

struct Gate{
	int c, r;
};

struct Start{
	int node, cnt;
};

vector <Gate> g[maxn];
int ans[maxn];
int n, m, r[maxn];
int vis[maxn];

void set_dis(void) {
	r[n] = 1;
	queue <int> q; q.push(n);
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (int i = 0; i < g[node].size(); i++) {
			if (r[g[node][i].r] == 0) {
				r[g[node][i].r] = r[node] + 1;
				q.push(g[node][i].r);
				if (r[1] != 0) return;
			}
		}
	}
}

void solve(void) {
	Start ss; ss.node = 1; ss.cnt = 0; vis[1] = 1;
	queue <Start> q; q.push(ss);
	while (!q.empty()) {
		Start st = q.front(); q.pop();
		vector <int> vr; int minc = 0;
		for (int i = 0; i < g[st.node].size(); i++)
			if (r[g[st.node][i].r] != 0 && r[g[st.node][i].r] < r[st.node]) {
				if (minc == 0 || g[st.node][i].c < minc) {
					vr.resize(0);
					minc = g[st.node][i].c;
					vr.push_back(g[st.node][i].r);
				}
				else if (minc == g[st.node][i].c) vr.push_back(g[st.node][i].r);
			}
		if (ans[st.cnt] != 0 && ans[st.cnt] < minc) continue;
		ans[st.cnt++] = minc;
		if (vr.size() == 1 && vis[vr[0]] == 0) {
			st.node = vr[0];
			q.push(st);
			vis[vr[0]] = 1;
		}
		else {
			for (int i = 0; i < vr.size(); i++) {
				if (vis[vr[i]] == 0) {
					st.node = vr[i];
					q.push(st);
					vis[vr[i]] = 1;
				}
			}
		}
	}
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++) {g[i].resize(0); r[i] = 0;}
		int a, b; Gate gg;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &gg.c);
			gg.r = b; g[a].push_back(gg);
			gg.r = a; g[b].push_back(gg);
		}
		set_dis();
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		solve();
		int cnt = r[1]-1;
		printf("%d\n", cnt);
		for (int i = 0; i < cnt-1; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[cnt-1]);
	}
	return 0;
}