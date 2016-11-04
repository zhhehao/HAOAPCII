# include <cstdio>
# include <set>
# include <algorithm>
using namespace std;

struct Exchange {
	int x, y;
	bool operator < (const Exchange& b) const {
		if (x == b.x)
			return y < b.y;
		else
			return x < b.x;
	}
};

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1 && n) {
		set <Exchange> fe;
		fe.clear();
		Exchange e;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &e.x, &e.y);
			if (e.x > e.y) swap(e.x, e.y);
			if (fe.count(e)) fe.erase(e);
			else fe.insert(e);
		}
		if (fe.empty()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
