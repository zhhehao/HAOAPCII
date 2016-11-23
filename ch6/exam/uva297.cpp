# include <cstdio>
# include <cstring>

const int maxn = 32 + 2;

int img[maxn][maxn], ans, cnt;
char b1[2000], b2[2000];

void fill(int x, int y, int len) {
	for (int i = x; i < x+len; i++) {
		for (int j = y; j < y+len; j++) {
			if (img[i][j] == 0) {
				img[i][j] = 1; ans++;
			}
		}
	}
}

void solve(int x, int y, int len, char *buf) {
	char ch;
	for (int i = 0; i < 4; i++) {
		ch = *(buf+(cnt++));
		if (ch == 'p') {
			switch(i) {
				case 0: solve(x, y+len, len/2, buf); break;
				case 1: solve(x, y, len/2, buf); break;
				case 2: solve(x+len, y, len/2, buf); break;
				case 3: solve(x+len, y+len, len/2, buf); break;
			}
		}
		else if (ch == 'f') {
			switch(i) {
				case 0: fill(x, y+len, len); break;
				case 1: fill(x, y, len); break;
				case 2: fill(x+len, y, len); break;
				case 3: fill(x+len, y+len, len); break;
			}
		}
	}
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	int t; scanf("%d", &t);
	while (t--) {
		memset(img, 0, sizeof(img));
		ans = 0;
		scanf("%s%s", b1, b2);
		if ((strlen(b1)==1 && b1[0]=='f') || (strlen(b2)==1 && b2[0]=='f')) {
			ans = 1024; goto output;
		}
		if ((strlen(b1) > 1)) {
			if (b1[0] == 'p') cnt = 1;
			else cnt = 0;
			solve(1, 1, 16, b1);
		}
		if ((strlen(b2) > 1)) {
			if (b2[0] == 'p') cnt = 1;
			else cnt = 0;
			solve(1, 1, 16, b2);
		}
output:
		printf("There are %d black pixels.\n", ans);
	}
	return 0;
}