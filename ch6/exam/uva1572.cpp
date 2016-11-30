# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

const int maxn = 52 + 5;

int g[maxn][maxn], c[maxn], n;

int dfs(int x) {
	c[x] = -1;
	for (int i = 0; i < 52; i++) {
		if (g[x][i] == 1) {
			// int j = (i > 25) ? i-25 : i+25;
			if (c[i] < 0) return -1;
			if (c[i] == 0) {
				if (dfs(i) < 0)
					return -1;
			}
		}
	}
	c[x] = 1;
	return 0;
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	while (scanf("%d", &n) == 1) {
		memset(g, 0, sizeof(g));
		memset(c, 0, sizeof(c));
		char buf[10]; vector <int> vp;
		for (int i = 0; i < n; i++) {
			scanf("%s", buf);
			vp.resize(0);
			if (buf[0] != '0') vp.push_back((buf[1] == '-') ? buf[0]-'A'+26 : buf[0]-'A');
			if (buf[2] != '0') vp.push_back((buf[3] == '-') ? buf[2]-'A'+26 : buf[2]-'A');
			if (buf[4] != '0') vp.push_back((buf[5] == '-') ? buf[4]-'A'+26 : buf[4]-'A');
			if (buf[6] != '0') vp.push_back((buf[7] == '-') ? buf[6]-'A'+26 : buf[6]-'A');
			if (vp.size() <= 1) continue;
			for (int i = 0; i < vp.size(); i++) {
				for (int j = 0; j < vp.size(); j++) {
					if (i == j) continue;
					int y = (vp[j] < 26) ? vp[j]+26 : vp[j]-26;
					g[vp[i]][y] = 1;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < 52; i++) {
			if (c[i] == 0) {
				ans = dfs(i);
				if (ans < 0)
					goto output;
			}
		}

output:
		if (ans < 0)
			printf("unbounded\n");
		else
			printf("bounded\n");
	}
	return 0;
}