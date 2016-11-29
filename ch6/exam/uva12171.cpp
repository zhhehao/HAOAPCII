# include <cstdio>
# include <cstring>
# include <queue>
# include <algorithm>
# include <set>
# include <vector>
using namespace std;

const int maxn = 100 + 10;
int s[maxn][maxn][maxn],b[55][6];
int area, volume, xm, ym, zm;

vector <int> xl, yl, zl;
set <int> xs, ys, zs;

int dx[6][3] = {{0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}};

struct Block {
	int x, y, z;
};

void input(void) {
	memset(s, 0, sizeof(s));
	memset(b, 0, sizeof(b));
	xl.resize(0); yl.resize(0); zl.resize(0);
	xs.clear(); ys.clear(); zs.clear();
	area = volume = 0;
	int n; scanf("%d", &n);
	// scanf all boxes and put in array b
	// also put all x, y, z value to array xl, yl, zl
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &b[i][0], &b[i][1], &b[i][2]);
		scanf("%d%d%d", &b[i][3], &b[i][4], &b[i][5]);
		if (!xs.count(b[i][0])) {xl.push_back(b[i][0]); xs.insert(b[i][0]);}
		if (!ys.count(b[i][1])) {yl.push_back(b[i][1]); ys.insert(b[i][1]);}
		if (!zs.count(b[i][2])) {zl.push_back(b[i][2]); zs.insert(b[i][2]);}
		if (!xs.count(b[i][0]+b[i][3])) {xl.push_back(b[i][0]+b[i][3]); xs.insert(b[i][0]+b[i][3]);}
		if (!ys.count(b[i][1]+b[i][4])) {yl.push_back(b[i][1]+b[i][4]); ys.insert(b[i][1]+b[i][4]);}
		if (!zs.count(b[i][2]+b[i][5])) {zl.push_back(b[i][2]+b[i][5]); zs.insert(b[i][2]+b[i][5]);}
	}
	// sort
	sort(xl.begin(), xl.end());
	sort(yl.begin(), yl.end());
	sort(zl.begin(), zl.end());
	xm = xl[xl.size()-1]+1; ym = yl[yl.size()-1]+1; zm = zl[zl.size()-1]+1;
	// fill all boxes blocks to 1
	for (int i = 0; i < n; i++) {
		int x1 = 0; while (xl[x1] != b[i][0]) x1++;
		int x2 = x1; while (xl[x2] != b[i][0]+b[i][3]) x2++;
		x1++;
		int y1 = 0; while (yl[y1] != b[i][1]) y1++;
		int y2 = y1; while (yl[y2] != b[i][1]+b[i][4]) y2++;
		y1++;
		int z1 = 0; while (zl[z1] != b[i][2]) z1++;
		int z2 = z1; while (zl[z2] != b[i][2]+b[i][5]) z2++;
		z1++;
		for (int o = x1; o <= x2; o++) {
			for (int p = y1; p <= y2; p++) {
				for (int q = z1; q <= z2; q++) {
					s[o][p][q] = 1;
				}
			}
		}
	}
	// cal all x, y, z length
	for (int i = xl.size()-1; i > 0; i--) xl[i] -= xl[i-1];
	xl.push_back(1);
	for (int i = yl.size()-1; i > 0; i--) yl[i] -= yl[i-1];
	yl.push_back(1);
	for (int i = zl.size()-1; i > 0; i--) zl[i] -= zl[i-1];
	zl.push_back(1);
}

void solve() {
	queue <Block> q;
	Block bb; bb.x = 0; bb.y = 0; bb.z = 0;
	q.push(bb);
	s[0][0][0] = 2;
	while (!q.empty()) {
		Block bq = q.front(); q.pop();
		volume += (xl[bq.x]*yl[bq.y]*zl[bq.z]);
		// printf("%d %d %d: %d\n", bq.x, bq.y, bq.z, xl[bq.x]*yl[bq.y]*zl[bq.z]);
		for (int i = 0; i < 6; i++) {
			Block bn;
			bn.x = bq.x + dx[i][0];
			bn.y = bq.y + dx[i][1];
			bn.z = bq.z + dx[i][2];
			if (bn.x < 0 || bn.x > xl.size()-1) continue;
			if (bn.y < 0 || bn.y > yl.size()-1) continue;
			if (bn.z < 0 || bn.z > zl.size()-1) continue;
			if (s[bn.x][bn.y][bn.z] == 0) {
				q.push(bn);
				s[bn.x][bn.y][bn.z] = 2;
			}
			else if (s[bn.x][bn.y][bn.z] == 1) {
				switch(i) {
					case 0: area += xl[bq.x]*zl[bq.z]; break;
					case 1: area += xl[bq.x]*zl[bq.z]; break;
					case 2: area += yl[bq.y]*zl[bq.z]; break;
					case 3: area += yl[bq.y]*zl[bq.z]; break;
					case 4: area += xl[bq.x]*yl[bq.y]; break;
					case 5: area += xl[bq.x]*yl[bq.y]; break;
				}
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
		input();
		solve();
		printf("%d %d\n", area, xm*ym*zm - volume);
	}
	return 0;
}