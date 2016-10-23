# include <cstdio>
# include <cstring>
# include <map>
using namespace std;

# define maxn 5000

int quo[maxn], mod[maxn];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int num, dnum;
	while(scanf("%d%d", &num, &dnum) != EOF) {
		printf("%d/%d = ", num, dnum);
		map <int, int> cyc;
		cyc.clear();
		memset(quo, 0, sizeof(quo));
		memset(mod, 0, sizeof(mod));
		int ipart = 0;
		if (num >= dnum) {
			ipart = num / dnum;
			num = num % dnum;
		}
		printf("%d.", ipart);

		int cal = 0, cycStart, cycEnd;
		for(;;) {
			if (num == 0) {
				quo[cal] = 0;
				cycStart = cal;
				cycEnd = cal + 1;
				break;
			}
			num *= 10;
			quo[cal] = num / dnum;
			mod[cal] = num % dnum;
			if (cyc.count(mod[cal]) > 0) {
				cycEnd = cal;
				cycStart = cyc[mod[cal]] + 1;
				break;
			}
			else {
				cyc[mod[cal]] = cal;
			}
			num = mod[cal];
			cal++;
		}
		int cycLen = cycEnd - cycStart + 1;
		if (cycEnd > 49) cycEnd = 49;
		for (int i = 0; i <= cycEnd; i++) {
			if (i == cycStart) printf("(");
			printf("%d", quo[i]);
			if (i == 49) printf("...");
			if (i == cycEnd) printf(")");
		}
		printf("\n   %d = number of digits in repeating cycle\n\n", cycLen);
	}
	return 0;
}
