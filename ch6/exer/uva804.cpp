# include <cstdio>
# include <cstring>
# include <map>
using namespace std;

const int maxn = 100 + 5;
int p[maxn], nt, np, nf;
map <int, int> ti[maxn], to[maxn];

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	int kase = 1;

	while (scanf("%d", &np) == 1 && np) {
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= np; i++) scanf("%d", &p[i]);
		scanf("%d", &nt);
		for (int i = 0; i <= nt; i++) {ti[i].clear(); to[i].clear();};
		int num;
		for (int i = 1; i <= nt; i++) {
			while (scanf("%d", &num) == 1 && num != 0) {
				if (num < 0) {num *= -1; ti[i][num]++;}
				else to[i][num]++;
			}
		}
		scanf("%d", &nf);
		int fire_cnt = 0;
		map <int, int>::iterator it;
		for (int i = 1; i <= nt; i++) {
			bool can_fire = true;
			for (it = ti[i].begin(); it != ti[i].end(); ++it) {
				if (p[it->first] < it->second) {
					can_fire = false; break;
				}
			}
			if (can_fire) {
				for (it = ti[i].begin(); it != ti[i].end(); ++it) {
					p[it->first] -= it->second;
				}
				for (it = to[i].begin(); it != to[i].end(); ++it) {
					p[it->first] += it->second;
				}
				fire_cnt++;
				i = 0;
				if (fire_cnt == nf) break;
			}
		}

		printf("Case %d: ", kase++);
		if (fire_cnt < nf) printf("dead");
		else printf("still live");
		printf(" after %d transitions\n", fire_cnt);
		printf("Places with tokens:");
		for (int i = 1; i <= np; i++) {
			if (p[i] > 0)
				printf(" %d (%d)", i, p[i]);
		}
		printf("\n\n");
	}
	return 0;
}