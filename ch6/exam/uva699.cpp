# include <cstdio>
# include <cstring>

const int maxn = 1000;

int L[maxn], R[maxn], lcnt, rcnt;

void solve(int p) {
	int node; scanf("%d", &node);
	if (node != -1) {
		int pos = p - 1;
		if (pos < 0) {
			pos *= -1;
			if (pos > lcnt) lcnt = pos;
			L[pos] += node;
			solve(pos*-1);
		}
		else {
			if (pos > rcnt) rcnt = pos;
			R[pos] += node;
			solve(pos);
		}
	}
	scanf("%d", &node);
	if (node != -1) {
		int pos = p + 1;
		if (pos < 0) {
			pos *= -1;
			if (pos > lcnt) lcnt = pos;
			L[pos] += node;
			solve(pos*-1);
		}
		else {
			if (pos > rcnt) rcnt = pos;
			R[pos] += node;
			solve(pos);
		}
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int root, kase = 1;
	while (scanf("%d", &root) == 1 && root != -1) {
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		lcnt = rcnt = 0;
		R[0] += root;
		solve(0);

		printf("Case %d:\n", kase++);
		if (lcnt != 0) {
			for (int i = lcnt; i > 0; i--) {
				printf("%d ", L[i]);
			}
		}
		for (int i = 0; i <= rcnt; i++) {
			if (i != 0) printf(" ");
			printf("%d", R[i]);
		}
		printf("\n\n");
	}
	return 0;
}