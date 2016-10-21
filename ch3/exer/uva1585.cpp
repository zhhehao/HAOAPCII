# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 85
char buf[maxn];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", buf);
		int len = strlen(buf), ans = 0, score = 0;
		for (int i = 0; i < len; i++) {
			if (buf[i] == 'O') {
				score++;
				ans += score;
			}
			else
				score = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}