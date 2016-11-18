# include <cstdio>
# include <cstring>
# include <cctype>
# include <vector>
# include <queue>
using namespace std;

const int maxn = 512;

struct Node {
	int L, R, have_value, value;
};

Node bt[maxn];
char buf[maxn];
int cnt, pos;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while (scanf("%s", buf) == 1) {
		memset(bt, 0, sizeof(bt));
		vector <int> ans; ans.resize(0);
		queue <int> leaf; while (!leaf.empty()) leaf.pop();
		bool is_incompleted = false;
		cnt = 1;
		do {
			int va; sscanf(&buf[1], "%d", &va);
			// printf("%d\n",h va);
			char *s = strchr(buf, ',');
			int len = strlen(s);
			pos = 0;
			for (int i = 0; i < len; i++) {
				if (s[i] == 'L') {
					if (bt[pos].L == 0) bt[pos].L = cnt++;
					pos = bt[pos].L;
				}
				else if (s[i] == 'R') {
					if (bt[pos].R == 0) bt[pos].R = cnt++;
					pos = bt[pos].R;
				}
			}
			if (bt[pos].have_value == 0) {
				bt[pos].value = va;
				bt[pos].have_value = 1;
			}
			else {
				is_incompleted = true;
				while (buf[1] != ')') {
					scanf("%s", buf);
				}
				goto out;
			}
		} while (scanf("%s", buf) == 1 && buf[1] != ')');

		leaf.push(0);
		while (!leaf.empty()) {
			int k = leaf.front(); leaf.pop();
			if (bt[k].have_value == 0) {
				is_incompleted = true;
				goto out;
			}
			ans.push_back(bt[k].value);
			if (bt[k].L != 0) leaf.push(bt[k].L);
			if (bt[k].R != 0) leaf.push(bt[k].R);
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
