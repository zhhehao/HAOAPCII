# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 100000

char s[maxn], t[maxn];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while(scanf("%s%s", s, t) != EOF) {
		bool is_match = true;
		int slen =  strlen(s), tlen = strlen(t);
		if (slen > tlen) {
			is_match = false;
			goto output;
		}
		for (int i = 0, j = 0; i < slen; i++) {
			while(s[i] != t[j]) {
				j++;
				if (j == tlen) {
					is_match = false;
					goto output;
				}
			}
			j++;
			if (j == tlen && i != slen - 1) {
				is_match = false;
				break;
			}
		}
output:
		if (is_match)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}