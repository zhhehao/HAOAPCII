# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int n, m, L[maxn], R[maxn], sw;

void link(int x, int y) {
	R[x] = y; L[y] = x;
}

void left_change(int x, int y) {
	if (L[y] == x) return;
	int LX = L[x], RX = R[x], LY = L[y], RY = R[y];
	link(LX, RX);
	link(LY, x);
	link(x, y);
}

void right_change(int x, int y) {
	if (R[y] == x) return;
	int LX = L[x], RX = R[x], LY = L[y], RY = R[y];
	link(LX, RX);
	link(y, x);
	link(x, RY);
}


void swap_change(int x, int y) {
	int LX = L[x], RX = R[x], LY = L[y], RY = R[y];
	link(LX, y); link(y, RX);
	link(LY, x); link(x, RY);
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
				case 4: sw = (sw == 0) ? 1 : 0; break;
			}
			for (int i = 0; i <= n; i++)
				printf("%d ", L[i]);
			printf("\n");
			for (int i = 0; i <= n; i++)
				printf("%d ", R[i]);
			printf("\n");
		}

		long long ans = 0;
		int b = 0;
		if (sw == 0) {
			for (int i = 1; i <= n; i++) {
				b = R[b];
				if (i % 2 == 1) ans += b;
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				b = L[b];
				if (i % 2 == 1) ans += b;
			}
		}

		printf("Case %d: %lld\n", kase++, ans);
	}
	return 0;
}
