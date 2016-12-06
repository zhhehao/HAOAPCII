# include <cstdio>
# include <cstring>

const int maxn = 128 + 5;

int n, m, d[10], kase;
char term[maxn], vva[10];

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	kase = 1;
	while (scanf("%d", &n) == 1 && n) {
		char ch[5];
		for (int i = 0; i < n; i++) {
			scanf("%s", ch);
			d[i] = ch[1] - '0';
		}
		scanf("%s", term);
		scanf("%d", &m);
		printf("S-Tree #%d:\n", kase++);
		for (int i = 0; i < m; i++) {
			int w = (1<<n), cur = 0;
			scanf("%s", vva);
			for (int j = 0; j < n; j++) {
				w /= 2;
				if (vva[j] == '1')
					cur += w;
			}
			printf("%c", term[cur]);
		}
		printf("\n\n");
	}
	return 0;
}