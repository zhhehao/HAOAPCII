# include <cstdio>
# include <map>
# include <algorithm>
# include <cstring>
using namespace std;

# define maxn 105
char sBuf[maxn], tBuf[maxn];
int s[26], t[26];
map <char, int> sMap;
map <char, int> tMap;

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while(scanf("%s%s", sBuf, tBuf) != EOF) {
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		sMap.clear();
		tMap.clear();
		int len = strlen(sBuf);
		int sCount = 0, tCount = 0;
		for (int i = 0; i < len; i++) {
			if (sMap.count(sBuf[i]) > 0) {
				s[sMap[sBuf[i]]]++;
			}
			else {
				sMap[sBuf[i]] = sCount++;
				s[sMap[sBuf[i]]]++;
			}
			if (tMap.count(tBuf[i]) > 0) {
				t[tMap[tBuf[i]]]++;
			}
			else {
				tMap[tBuf[i]] = tCount++;
				t[tMap[tBuf[i]]]++;
			}
		}
		sort(s, s+26);
		sort(t, t+26);
		if (memcmp(s, t, sizeof(s)) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
