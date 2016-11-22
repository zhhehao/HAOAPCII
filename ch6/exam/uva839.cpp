# include <cstdio>

int solve() {
	int w1, d1, w2, d2;
	scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
	if (w1 == 0) w1 = solve();
	if (w2 == 0) w2 = solve();
	if (w1 == 0 || w2 == 0) return 0;
	if (w1*d1 != w2*d2) return 0;
	return w1+w2;
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t, kase = 0; scanf("%d", &t);
	while (t--) {
		if (kase++) printf("\n");
		if (solve() != 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}