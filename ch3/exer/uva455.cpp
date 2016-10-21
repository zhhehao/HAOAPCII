# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 85
char buf[maxn];

bool is_period(int cur) {
	int len = strlen(buf);
	bool res = true;
	for (int i = cur; i < len; i += cur) {
		bool is_failed = false;
		for (int j = 0; j < cur; j++) {
			if (buf[j] != buf[i+j]) {
				is_failed = true;
				break;
			}
		}
		if (is_failed) {
			res = false;
			break;
		}
	}
	return res;
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", buf);
		int period = strlen(buf);
		for (int i = 1; i < period; i++) {
			if (buf[i] == buf[0] && period % i == 0 && is_period(i)) {
				period = i;
				break;
			}
		}
		if (kase++)
			printf("\n");
		printf("%d\n", period);
	}
	return 0;
}
