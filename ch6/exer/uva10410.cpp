# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

const int maxn = 1000 + 5;

vector <int> ans[maxn], b, d;
int n;

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%d", &n) == 1) {
		b.resize(0); d.resize(0);
		for (int i = 1; i <= n; i++) ans[i].resize(0);
		int node;
		for (int i = 1; i <= n; i++) {scanf("%d", &node); b.push_back(node);}
		for (int i = 1; i <= n; i++) {scanf("%d", &node); d.push_back(node);}
		if (n == 1) {printf("1:\n"); continue;}
		int bs, be, ds, de;
		while (b.size() > 1) {
			bs = be = b.size()-1;
			ds = d.size()-1;
			while (d[ds] != b[bs]) ds--;
			de = ds;
			while (be > 1 && de > 1 && b[be-1] == d[de-1]) {be--; de--;}
			// printf("%d %d %d %d\n", bs, be, ds, de);
			int root = d[de-1];
			// printf("root is %d\n", root);
			for (int i = bs; i >= be; i--) {
				ans[root].push_back(b[i]);
				b.erase(b.begin()+i);
			}
			for (int i = ds; i >= de; i--) {d.erase(d.begin()+i);}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d:", i);
			if (ans[i].size() != 0) {
				for (int j = 0; j < ans[i].size(); j++) printf(" %d", ans[i][j]);
				sort(ans[i].begin(), ans[i].end());
			}
			printf("\n");
		}
	}
	return 0;
}