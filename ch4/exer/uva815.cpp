/*
** line all square and sorted it from lower to higher and calculate
*/

# include <cstdio>
# include <vector>
# include <algorithm>
# include <climits>
using namespace std;

# define EPS 1e-6

vector <int> land;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int m, n, volume, kase = 1;
	while (scanf("%d%d", &m, &n) == 2 && m) {
		land.resize(0);
		int unit;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &unit);
				land.push_back(unit);
			}
		}
		scanf("%d", &volume);
		sort(land.begin(), land.end());
		int base = land[0];
		for (int i = 0; i < land.size(); i++)
			land[i] -= base;
		land.push_back(INT_MAX);
		double level, percent = 0;
		level = (double)base;
		int cur = 0;
		double total = 0;
		for (;;) {
			cur++;
			// printf("cur is %d\n", cur);
			if (cur == land.size()-1) {
				level += ((volume-total) / (cur*100)+land[cur-1]);
				percent = 100.0;
				break;
			}
			if (total >= volume) {
				level += (land[cur-1]-(total-volume)/((cur-1)*100));
				percent = (double)(cur-1)/(n*m)*100;
				break;
			}
			total += ((land[cur]-land[cur-1]) * cur * 100);
		}
		printf("Region %d\n", kase++);
		printf("Water level is %.2f meters.\n", level + EPS);
		printf("%.2f percent of the region is under water.\n\n", percent + EPS);
	}
	return 0;
}
