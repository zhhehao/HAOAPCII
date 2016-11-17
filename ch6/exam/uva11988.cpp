# include <cstdio>
# include <cstring>
# include <cctype>
using namespace std;

const int maxn = 100000 + 10;
char ans[maxn];
int next[maxn];

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	char buf[maxn];
	while (scanf("%s", buf) == 1) {
		memset(ans, '\0', sizeof(ans));
		memset(next, 0, sizeof(next));
		int pos = 1, last = 1;
		int len = strlen(buf);
		for (int i = 0; i < len; i++) {
			ans[pos] = buf[i];
			if (isalpha(buf[i]) || buf[i] == '_') {
				next[pos] = next[pos-1];
				if (next[pos] == 0) last = pos;
				next[pos-1] = pos;
			}
			else if (buf[i] == '[') {
				next[pos] = next[0];
				next[0] = pos;
			}
			else if (buf[i] == ']') {
				next[pos] = 0;
				next[last] = pos;
				last = pos;
			}
			pos++;
		}

		pos = 0;
		while (next[pos] != 0) {
			if (ans[next[pos]] != '[' && ans[next[pos]] != ']')
				printf("%c", ans[next[pos]]);
			pos = next[pos];
		}
		printf("\n");
	}
	return 0;
}