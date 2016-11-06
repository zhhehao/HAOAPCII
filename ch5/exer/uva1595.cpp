# include <cstdio>
# include <map>
# include <vector>
# include <algorithm>
using namespace std;

const int maxn = 1000 + 10;

map <int, int> mp;
vector <int> vp[maxn];
vector <int> ans;

void get_sym(vector <int>& v, vector <int>& a) {
	if (v.size() == 1) a.push_back(v[0]);
	else if (v.size() == 2) a.push_back((v[0]+v[1])/2);
	else {
		int sym = (v[0] + v[v.size()-1]) / 2;
		for (int i = 1, j = v.size()-2; i < j; i++, j--)
			if (sym != (v[i] + v[j]) / 2) {
				a.push_back(30000);
				return;
			}
		a.push_back(sym);
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int x, y, cnt = 0;
		mp.clear();
		ans.resize(0);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			x = (x << 1);
			if (mp.count(y)) vp[mp[y]].push_back(x);
			else {
				mp[y] = cnt++;
				vp[mp[y]].resize(0);
				vp[mp[y]].push_back(x);
			}
		}
		for (int i = 0; i < cnt; i++) {
			sort(vp[i].begin(), vp[i].end());
			// printf("size is %d\n", vpb[i].size());
		}
		bool is_have = true;
		get_sym(vp[0], ans);
		if (ans[0] == 30000) {is_have = false; goto output;}

		for (int i = 1; i < cnt; i++) {
			get_sym(vp[i], ans);
			if (ans[i] == 30000 || ans[i] != ans[0]) {
				is_have = false;
				break;
			}
		}

output:
		if (is_have) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
