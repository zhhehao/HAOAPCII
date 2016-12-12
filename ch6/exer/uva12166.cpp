# include <cstdio>
# include <cstring>
# include <cctype>
# include <map>
# include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 1000000 + 10;
char c[maxn];

map <LL, int> stat;

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	int t; scanf("%d", &t); fgets(c, 20, stdin);
	while(t--) {
		memset(c, '\0', sizeof(c));
		fgets(c, maxn, stdin);
		if (isdigit(c[0])) {printf("0\n"); continue;}
		int level = 0; stat.clear(); LL w;
		for (int i = 0; c[i] != '\0';) {
			if (c[i] == '[')
				level++;
			else if (c[i] == ']')
				level--;
			else if (isdigit(c[i])) {
				sscanf(c+i, "%lld", &w);
				stat[w<<level]++;
				while(isdigit(c[i])) i++;
				continue;
			}
			i++;
		}
		map <LL, int>::iterator it;
		int sum = 0, max_w = 0;
		for (it = stat.begin(); it != stat.end(); ++it) {
			sum += it->second;
			max_w = max(max_w, it->second);
		}
		printf("%d\n", sum - max_w);
	}
	return 0;
}