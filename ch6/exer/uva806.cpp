# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
using namespace std;

const int maxn = 64 + 5;
const int five[] = {1, 5, 25, 125, 625, 3125};

char g[maxn][maxn], n;
vector <int> ans;

int count_black(int x, int y, int w) {
	int xend = x + w, yend = y + w, rec = 0;
	for (int i = x; i < xend; i++)
		for (int j = y; j < yend; j++)
			if (g[i][j] == '1') rec++;
	return rec;
}

bool is_black(int x, int y, int w) {
	int xend = x + w, yend = y + w;
	for (int i = x; i < xend; i++)
		for (int j = y; j < yend; j++)
			if (g[i][j] == '0') return false;
	return true;
}

bool is_white(int x, int y, int w) {
	int xend = x + w, yend = y + w;
	for (int i = x; i < xend; i++)
		for (int j = y; j < yend; j++)
			if (g[i][j] == '1') return false;
	return true;
}

void get_ans(int x, int y, int w, int l, int v) {
	if (l > 0 && is_black(x, y, w)) {ans.push_back(v); return;}
	if (!is_white(x, y, w/2)) get_ans(x, y, w/2, l+1, v+five[l]);
	if (!is_white(x, y+w/2, w/2)) get_ans(x, y+w/2, w/2, l+1, v+five[l]*2);
	if (!is_white(x+w/2, y, w/2)) get_ans(x+w/2, y, w/2, l+1, v+five[l]*3);
	if (!is_white(x+w/2, y+w/2, w/2)) get_ans(x+w/2, y+w/2, w/2, l+1, v+five[l]*4);
}

void fill_color(int x, int y, int w, char c) {
	int xend = x + w, yend = y + w;
	for (int i = x; i < xend; i++)
		for (int j = y; j < yend; j++)
			g[i][j] = c;
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	int kase = 0;
	while (scanf("%d", &n) == 1 && n != 0) {
		if (kase++) printf("\n");
		printf("Image %d\n", kase);
		memset(g, '\0', sizeof(g));
		if (n > 0) {
			for (int i = 1; i <= n; i++) scanf("%s", g[i]+1);
			int b_cnt = count_black(1, 1, n);
			if (b_cnt == 0) {printf("Total number of black nodes = 0\n"); continue;}
			if (b_cnt == n*n) {printf("0\nTotal number of black nodes = 1\n"); continue;}
			ans.resize(0);
			get_ans(1, 1, n, 0, 0);
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size()-1; i++) {
				printf("%d", ans[i]);
				if (i % 12 == 11) printf("\n");
				else printf(" ");
			}
			printf("%d\nTotal number of black nodes = %d\n", ans[ans.size()-1], ans.size());
		}
		else {
			n *= -1;
			int num; scanf("%d", &num);
			if (num == 0) {
				scanf("%d", &num);
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) printf("*");
					printf("\n");
				}
				continue;
			}
			if (num == -1) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) printf(".");
					printf("\n");
				}
				continue;
			}
			fill_color(1, 1, n, '.');
			int w, x, y, d;
			do {
				w = n; x = 1; y = 1;
				do {
					d = num % 5; num /= 5; w /= 2;
					switch (d) {
						case 1:
							break;
						case 2:
							y += w; break;
						case 3:
							x += w; break;
						case 4:
							x += w; y += w; break;
					}
				} while (num != 0);
				fill_color(x, y, w, '*');
			} while (scanf("%d", &num) == 1 && num != -1);
			for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) printf("%c", g[i][j]);
					printf("\n");
			}
		}
	}
	return 0;
}