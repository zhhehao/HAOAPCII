/*
** grid all real numbers
*/

# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# include <set>
# include <map>
using namespace std;

const int maxn = 200 + 5;

int city_map[maxn][maxn];
int n;

struct Building {
	double x, y, w, d, h;
	int id;
	bool operator < (const Building& b) const {
		if (y == b.y)
			return x < b.x;
		return y > b.y;
	}
};

vector <double> xais;
vector <double> hais;
vector <Building> bld;
map <int, int> bld_db;

int cmp1(const Building& a, const Building& b) {
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

void input(void) {
	bld.resize(0);
	bld_db.clear();
	xais.resize(0);
	hais.resize(0);
	memset(city_map, 0, sizeof(city_map));

	Building b;
	for (int i = 0; i < n; i++) {
		b.id = i + 1;
		scanf("%lf%lf%lf%lf%lf", &b.x, &b.y, &b.w, &b.d, &b.h);
		bld.push_back(b);
		xais.push_back(b.x);
		xais.push_back(b.x+b.w);
		hais.push_back(b.h);
	}
	sort(bld.begin(), bld.end());
	for (int i = 0; i < bld.size(); i++) {
		bld_db[bld[i].id] = i;
	}
	sort(xais.begin(), xais.end());
	sort(hais.begin(), hais.end());
	vector <double> ::iterator it = unique(xais.begin(), xais.end());
	xais.resize(distance(xais.begin(), it));
	it = unique(hais.begin(), hais.end());
	hais.resize(distance(hais.begin(), it));
	// for (int i = 0; i < hais.size(); i++)
	// 	printf("%.2f ", hais[i]);
	// printf("\n");
}

void solve(void) {
	for (int i = 0; i < n; i++) {
		int x_s, x_e, y_s = 0, h_e;
		bool get_x_s = false;
		for (int j = 0; j < xais.size(); j++) {
			if (!get_x_s && bld[i].x == xais[j]) {x_s = j; get_x_s = true;}
			if (get_x_s && bld[i].x+bld[i].w == xais[j]) {x_e = j-1; break;}
		}
		for (int j = 0; j < hais.size(); j++) {
			if (bld[i].h == hais[j]) {h_e = j; break;}
		}

		for (int j = x_s; j <= x_e; j++) {
			for (int k = y_s; k <= h_e; k++) {
				city_map[j][k] = bld[i].id;
			}
		}
	}

	// for (int i = 0; i <= hais.size(); i++) {
	// 	for (int j = 0; j <= xais.size(); j++)
	// 		printf("%d ", city_map[j][i]);
	// 	printf("\n");
	// }
}

void output(int& kase) {
	vector <Building> ans;
	set <int> set_ans;
	ans.resize(0);
	set_ans.clear();
	for (int i = 0; i <= xais.size(); i++) {
		for (int j = 0; j <= hais.size(); j++) {
			if (city_map[i][j] && !set_ans.count(city_map[i][j])) {
				ans.push_back(bld[bld_db[city_map[i][j]]]);
				set_ans.insert(city_map[i][j]);
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp1);


	if (kase++) printf("\n");
	printf("For map #%d, the visible buildings are numbered as follows:\n", kase);
	for (int i = 0; i < ans.size()-1; i++)
		printf("%d ", ans[i].id);
	printf("%d\n", ans[ans.size()-1].id);
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		input();
		solve();
		output(kase);
	}
	return 0;
}