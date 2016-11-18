# include <cstdio>
# include <cstring>
# include <cctype>
# include <vector>
# include <queue>
using namespace std;

const int maxn = 512;

int v[maxn], L[maxn], R[maxn];
char buf[maxn];

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	while (scanf("%s", buf) == 1) {
		memset(v, 0, sizeof(v));
		vector <int> ans; ans.resize(0);
		queue <int> leaf; while (!leaf.empty()) leaf.pop();
		bool is_incompleted = false;
		int end;
		do {
			int len = strlen(buf);
			for (int i = 0 ; i < len; i++)
				if (!isalnum(buf[i]))
					buf[i]= ' ';
			int value;
			char path[10];
			if (sscanf(buf, "%d%s", &value, path) == 2) {
				int pos = 1, pathlen = strlen(path);
				for (int j = 0; j < pathlen; j++) {
					if (path[j] == 'L') {pos *= 2; if (v[pos] == 0) v[pos] = -1;}
					else {pos = pos*2+1; if (v[pos] == 0) v[pos] = -1;}
				}
				v[pos] = value;
			}
			else {
				v[1] = value;
			}
		} while (scanf("%s", buf) == 1 && buf[1] != ')');

		leaf.push(1);
		end = (1<<8)-1;
		if (v[1] == 0) {
			is_incompleted = true;
			goto out;
		}
		while (!leaf.empty()) {
			int k = leaf.front(); leaf.pop();
			ans.push_back(v[k]);
			int ltree = 2*k, rtree = 2*k+1;
			if (ltree > end) continue;
			if (v[ltree] == -1 || v[rtree] == -1) {
				is_incompleted = true; goto out;
			}
			if (v[ltree] > 0) leaf.push(ltree);
			if (v[rtree] > 0) leaf.push(rtree);
		}
out:
		if (is_incompleted)
			printf("not complete\n");
		else {
			for (int i = 0; i < ans.size()-1; i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[ans.size()-1]);
		}
	}
	return 0;
}