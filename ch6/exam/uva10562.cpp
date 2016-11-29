# include <cstdio>
# include <cstring>
# include <cctype>

const int maxn = 200 + 5;

char tree[maxn][maxn];
int n;

void solve(int y1, int y2, int x) {
	for (int i = y1; i <= y2; i++) {
		char &c = tree[x][i];
		if (c > 32 && c < 127 && c != '-' && c != '|' && c != '#') {
			printf("%c(", c);
			if (tree[x+1][i] == '|') {
				int s = i, e = i, len = strlen(tree[x+2])-1;
				while (s != 0 && tree[x+2][s] == '-') s--;
				while (e != len && tree[x+2][e] == '-') e++;
				solve(s, e, x+3);
			}
			printf(")");
		}
	}
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	int t; scanf("%d", &t); char buf[maxn];
	fgets(buf, maxn, stdin);
	while (t--) {
		n = 0; memset(tree, '\0', sizeof(tree));
		while (fgets(tree[n], maxn, stdin) && tree[n][0] != '#') n++;
		printf("(");
		if (tree[0][0] != '#')
			solve(0, strlen(tree[0]), 0);
		printf(")\n");
	}
	return 0;
}