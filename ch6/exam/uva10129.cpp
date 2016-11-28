# include <cstdio>
# include <cstring>

const int maxn = 1000 + 10;

int g[26][26], n, cnt;
char str[maxn];

void solve_front(int x, int y) {
	g[x][y]--;
	cnt++;
	for (int i = 0; i < 26; i++) {
		if (g[y][i] > 0)
			solve_front(y, i);
	}
}

void solve_back(int x, int y) {
	g[x][y]--;
	cnt++;
	for (int i = 0; i < 26; i++) {
		if (g[i][x] > 0)
			solve_back(i, x);
	}
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	int t; scanf("%d", &t);
	while (t--) {
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			g[str[0]-'a'][str[strlen(str)-1]-'a']++;
		}

		cnt = 0;
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++) {
				if (g[i][j] > 0) {
					solve_front(i, j);
					g[i][j]++;
					cnt--;
					solve_back(i, j);
					goto end;
				}
			}
		}

end:
		if (cnt == n)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}