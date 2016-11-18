# include <cstdio>

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t, dep, idx; scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &dep, &idx);
		int pos = 1, end = (1<<dep) - 1;
		for (;;) {
			if (idx % 2 == 1) {pos *= 2; idx = (idx+1)/2;}
			else {pos = pos*2+1; idx /= 2;}
			if (pos > end) break;
		}
		printf("%d\n", pos / 2);
	}
	return 0;
}