# include <cstdio>
# include <cstring>
# include <stack>
# include <cctype>
using namespace std;

# define LL long long

const int maxn = 100;

struct Matrix {
	int r, c;
};

Matrix mat[26];

void input(void) {
	memset(mat, 0, sizeof(mat));
	int n; scanf("%d", &n); char ch[2];
	for (int i = 0; i < n; i++) {
		scanf("%s", &ch);
		scanf("%d%d", &mat[ch[0]-'A'].r, &mat[ch[0]-'A'].c);
	}
}

void solve(void) {
	char buf[maxn]; fgets(buf, maxn, stdin);
	while (fgets(buf, maxn, stdin)) {
		LL ans = 0; int len = strlen(buf)-1;
		stack <Matrix> ss; bool is_error = false;
		for (int i = 0; i < len; i++) {
			if (isalpha(buf[i])) ss.push(mat[buf[i]-'A']);
			else if (buf[i] == ')') {
				Matrix m1, m2;
				m2 = ss.top(); ss.pop();
				m1 = ss.top(); ss.pop();
				if (m1.c != m2.r) {
					printf("error\n");
					is_error = true;
					break;
				}
				else {
					ans += m1.r * m1.c * m2.c;
					Matrix m3; m3.r = m1.r; m3.c = m2.c;
					ss.push(m3);
				}
			}
		}
		if (!is_error) printf("%lld\n", ans);
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	input();
	solve();
	return 0;
}