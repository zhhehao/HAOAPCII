# include <cstdio>
# include <cctype>
# include <cstring>
# include <map>
using namespace std;

# define maxn 85
char buf[maxn], molar_name[maxn];
int molar_count[maxn];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	map <char, float> mass;
	mass['C'] = 12.01;
	mass['H'] = 1.008;
	mass['O'] = 16.00;
	mass['N'] = 14.01;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", buf);
		memset(molar_count, 0, sizeof(molar_count));
		int cur = 0, molar_len = strlen(buf);
		float ans = 0.0;
		for (int i = 0; i < molar_len; ) {
			int num = 0;
			molar_name[cur] = buf[i];
			if ((i+1) == molar_len || isalpha(buf[i+1])) {
				molar_count[cur] = 1;
				i++;
			}
			else {
				i++;
				while(isdigit(buf[i])) {
					num = num * 10 + (buf[i] - '0');
					i++;
					if (i == molar_len)
						break;
				}
				molar_count[cur] = num;
			}
			cur++;
		}
		for (int i = 0; i < cur; i++)
			ans += mass[molar_name[i]] * (float)molar_count[i];
		printf("%.3f\n", ans);
	}
	return 0;
}