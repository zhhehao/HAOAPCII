# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int n, m, L[maxn], R[maxn], sw;

void left_change(int b1, int b2) {
	if (L[b2] == b1) return;
	int l1 = L[b1], r1 = R[b1];
	R[l1] = r1; L[r1] = l1;
	int l2 = L[b2];
	R[l2] =  b1; L[b1] = l2; R[b1] = b2; L[b2] = b1;
}

void right_change(int b1, int b2) {
	if (R[b2] == b1) return;
	int l1 = L[b1], r1 = R[b1];
	R[l1] = r1; L[r1] = l1;
	int r2 = R[b2];
	L[r2] = b1; R[b1] = r2; R[b2] = b1; L[b1] = b2;
}

void swap_change(int b1, int b2) {
	int l1 = L[b1], l2 = L[b2];
	int r1 = R[b1], r2 = R[b2];
	R[l1] = b2; L[r1] = b2; L[b2] = l1; R[b2] = r1;
	R[l2] = b1; L[r2] = b1; L[b1] = l2; R[b1] = r2;
}

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int kase = 1;
	while (scanf("%d%d", &n, &m) == 2) {
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		for (int i = 1; i <= n; i++) {
			L[i] = i - 1;
			R[i] = i + 1;
		}
		L[0] = n; R[0] = 1; R[n] = 0; sw = 0;
		int c, b1, b2;
		for (int i = 0; i < m; i++) {
			scanf("%d", &c);
			if (c != 4) scanf("%d%d", &b1, &b2);
			if (sw == 1 && c < 3) c = (c == 1) ? 2 : 1;
			switch (c) {
				case 1: left_change(b1, b2); break;
				case 2: right_change(b1, b2); break;
				case 3: swap_change(b1, b2); break;
				case 4: sw = (sw == 0) ? 1 : 0;
			}
		}

		long long ans = 0;
		int cnt = 0;
		if (sw == 0) {
			for (int i = R[0]; i != 0; i = R[i]) {
				if (cnt == 0) ans += i;
				cnt = (cnt == 0) ? 1 : 0;
			}
		}
		else {
			for (int i = L[0]; i != 0; i = L[i]) {
				if (cnt == 0) ans += i;
				cnt = (cnt == 0) ? 1 : 0;
			}
		}

		printf("Case %d: %lld\n", kase++, ans);
	}
	return 0;
}
