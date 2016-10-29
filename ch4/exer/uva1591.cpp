/*
** because 0 <= a, b <= 31, so enum it.
*/

# include <cstdio>
# include <climits>
using namespace std;

long long n, sp, sq, minK, minA, minB, k;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while (scanf("%d%d%d", &n, &sp, &sq) != EOF) {
		minK = LONG_MAX;
		for (int a = 0; a < 32; a++) {
			for (int b = 0; b < 32; b++) {
				k = (((n-1)*sp + ((n-1)*sp << a)) >> b) + sq;
				if (k >= n*sq && k < minK) {
					minK = k;
					minA = a;
					minB = b;
				}
				// else if (k == minK && (a < minA || (a == minA && b < minB))) {
				// 	minA = a;
				// 	minB = b;
				// }
			}
		}
		printf("%lld %lld %lld\n", minK, minA, minB);
	}
	return 0;
}
