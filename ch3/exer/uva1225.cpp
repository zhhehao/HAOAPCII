# include <cstdio>
# include <cstring>
using namespace std;

int ans[10];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++) {
			int number = i;
			while(number > 0) {
				ans[number % 10]++;
				number /= 10;
			}
		}
		for (int i = 0; i < 9; i++) {
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[9]);
	}
	return 0;
}
