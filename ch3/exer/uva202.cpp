# include <cstdio>
# include <map>
using namespace std;

# define maxn 5000

struct Frac{
	int quo, mod;
};
Frac frac[maxn];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int num, dnum;
	while(scanf("%d%d", &num, &dnum) != EOF) {
		printf("%d/%d = ", num, dnum);
		map <int, int> cyc;
		cyc.clear();
		int ipart = 0;
		if (num >= dnum) {
			ipart = num / dnum;
			num = num % dnum;
		}
		printf("%d.", ipart);

		int cal = 0, cycStart, cycEnd;
		for(;;) {

		}
		int cycLen = cycEnd - cycStart;
		cycEnd--;
		if (cycEnd > 49) cycEnd = 49;
		for (int i = 0; i <= cycEnd; i++)
			printf("%d", frac[i].quo);
		// for (int i = 0; i <= cycEnd; i++) {
		// 	if (i == cycStart) printf("(");
		// 	printf("%d", frac[i].quo);
		// 	if (i == 49) printf("...");
		// 	if (i == cycEnd) printf(")");
		// }
		printf("\n   %d = number of digits in repeating cycle\n\n", cycLen);
	}
	return 0;
}
