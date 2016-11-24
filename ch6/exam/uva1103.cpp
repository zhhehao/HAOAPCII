# include <cstdio>
# include <cstring>
# include <cctype>
# include <vector>
# include <algorithm>
using namespace std;

const int maxn = 200 + 5;

int img[maxn][maxn], h, w, kase, rec;
int h2b[16][4] = {
	{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
	{0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
	{1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
	{1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1} };
char am[6] = {'W', 'A', 'K', 'J', 'S', 'D'};

void input(void) {
	memset(img, 0, sizeof(img));
	char buf[55];
	for (int i = 0; i < h; i++) {
		scanf("%s", buf);
		for (int j = 0; j < w; j++) {
			if (buf[j] == '0') continue;
			int start = j * 4, cur;
			if (isdigit(buf[j])) cur = buf[j] - '0';
			else cur = buf[j] - 'a' + 10;
			for (int k = 0; k < 4; k++)
				img[i][start+k] = h2b[cur][k];
		}
	}
}

void fill_color(int x, int y) {
	int wd = 4 * w;
	img[x][y] = 2;
	if (x+1 < h && img[x+1][y] == 0) fill_color(x+1, y);
	if (x-1 >= 0 && img[x-1][y] == 0) fill_color(x-1, y);
	if (y+1 < wd && img[x][y+1] == 0) fill_color(x, y+1);
	if (y-1 >= 0 && img[x][y-1] == 0) fill_color(x, y-1);
}

void set_bg_color(void) {
	int wd = 4 * w;
	for (int i = 0; i < wd; i++) {
		if (img[0][i] == 0)
			fill_color(0, i);
		if (img[h-1][i] == 0)
			fill_color(h-1, i);
	}
	for (int i = 0; i < h; i++) {
		if (img[i][0] == 0)
			fill_color(i, 0);
		if (img[i][wd-1] == 0)
			fill_color(i, wd-1);
	}
}

void fill_symbol(int x, int y) {
	int wd = 4 * w;
	img[x][y] = 2;
	if (x+1 < h) {
		if (img[x+1][y] == 1) fill_symbol(x+1, y);
		else if (img[x+1][y] == 0) {fill_color(x+1, y); rec++;}
	}
	if (x-1 >= 0) {
		if (img[x-1][y] == 1) fill_symbol(x-1, y);
		else if (img[x-1][y] == 0) {fill_color(x-1, y); rec++;}
	}
	if (y+1 < wd) {
		if (img[x][y+1] == 1) fill_symbol(x, y+1);
		else if (img[x][y+1] == 0) {fill_color(x, y+1); rec++;}
	}
	if (y-1 >= 0) {
		if (img[x][y-1] == 1) fill_symbol(x, y-1);
		else if (img[x][y-1] == 0) {fill_color(x, y-1); rec++;}
	}
}

int get_letter(int x, int y) {
	int wd = 4*w;
	rec = 0;
	fill_symbol(x, y);
	return rec;
}

void solve(void) {
	vector <char> ans; ans.resize(0);
	int wd = 4*w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < wd; j++) {
			if (img[i][j] == 1)
				ans.push_back(am[get_letter(i, j)]);
		}
	}
	sort(ans.begin(), ans.end());
	printf("Case %d: ", kase++);
	for (int i = 0; i < ans.size(); i++)
		printf("%c", ans[i]);
	printf("\n");
}

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	kase = 1;
	while (scanf("%d%d", &h, &w) == 2 && h) {
		input();
		// set bg color to number '2'
		set_bg_color();
		solve();
	}
	return 0;
}