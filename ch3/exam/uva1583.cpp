# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 100010
int gen[maxn];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	memset(gen, 0, sizeof(gen));
	for (int i = 1; i < maxn; i++) {
		int a = i, b = i;
		while (b > 0) {
			a += (b % 10);
			b /= 10;
		}
		if (gen[a] == 0 || i < gen[a])
			gen[a] = i;
	}
	int n;
	scanf("%d", &n);
	while(n--) {
		int m;
		scanf("%d", &m);
		printf("%d\n", gen[m]);
	}
	return 0;
}