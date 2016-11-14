# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

char ans[maxn][45];
int fib[2][maxn];

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	memset(ans, '\0', sizeof(ans));
	memset(fib, 0, sizeof(fib));
	int cur_start = 0, cur_end = 0;
	ans[0][0] = '1'; ans[1][0] = '1';
	fib[0][0] = 1; fib[1][0] = 1;
	int cur;
	for (int i = 2; i < 100000; i++) {
		cur = i % 2;
		int p1 = 0, p2, sum;
		for (int j = cur_start; j <= cur_end; j++) {
			sum = fib[0][j] + fib[1][j] + p1;
			p2 = sum % 10;
			fib[cur][j] = p2;
			p1 = sum / 10;
		}
		if (p1 > 0) {
			cur_end++;
			fib[cur][cur_end] = p1;
		}
		if (cur_end - cur_start > 50) cur_start++;
		int len = min(cur_end - cur_start + 1, 40);
		int cnt = cur_end;
		for (int j = 0; j < len; j++) {
			ans[i][j] = fib[cur][cnt--] + '0';
		}
	}

	// for (int i = 0; i <= 100000; i++)
	// 	printf("%d - %s\n", i, ans[i]);

	int t, kase = 1; scanf("%d", &t);
	char buf[45];
	while (t--) {
		scanf("%s", buf);
		bool is_find = false;
		printf("Case #%d: ", kase++);
		for (int i = 0; i < 100000; i++) {
			int len = strlen(buf);
			bool is_match = true;
			for (int j = 0; j < len; j++) {
				if (buf[j] != ans[i][j]) {
					is_match = false;
					break;
				}
			}
			if (is_match) {
				printf("%d\n", i);
				is_find = true;
				break;
			}
		}
		if (!is_find)
			printf("-1\n");
	}
	return 0;
}