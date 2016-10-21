# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 105
char s[maxn];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		int len = strlen(s), ans = 0;
		for (int i = 1; i < len; i++) {
			if (s[ans] > s[i])
				ans = i;
			else if (s[ans] == s[i]) {
				int x = (ans + 1) % len, y = (i + 1) % len;
				while(s[x] == s[y]) {
					if (x == ans) break;
					x = (x + 1) % len;
					y = (y + 1) % len;
				}
				if (s[x] > s[y])
					ans = i;
			}
		}
		for (int i = 0; i < len; i++) {
			printf("%c", s[ans]);
			ans = (ans + 1) % len;
		}
		printf("\n");
	}
	return 0;
}