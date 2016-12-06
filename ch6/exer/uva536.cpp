# include <cstdio>
# include <cstring>

const int maxn = 26 + 4;

char po[maxn], io[maxn];

void solve(int p1, int p2, int i1, int i2) {
	if (p1 > p2) return;
	if (p1 == p2) {printf("%c", po[p1]); return;}
	int pos = i1; while(io[pos] != po[p1]) pos++;
	solve(p1+1, p1+pos-i1, i1, pos-1);
	solve(p1+pos-i1+1, p2, pos+1, i2);
	printf("%c", po[p1]);
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%s%s", po, io) == 2) {
		solve(0, strlen(po)-1, 0, strlen(io)-1);
		printf("\n");
	}
	return 0;
}
