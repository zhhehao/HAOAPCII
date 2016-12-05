# include <cstdio>
# include <cstring>
# include <stack>
using namespace std;

const int maxn = 128 + 5;

int t;
char buf[maxn];

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	scanf("%d", &t); fgets(buf, maxn, stdin);
	while (t--) {
		fgets(buf, maxn, stdin);
		// printf("%s", buf);
		stack <char> s; while(!s.empty()) s.pop();
		bool is_correct = true;
		int len = strlen(buf) - 1;
		for (int i = 0; i < len; i++) {
			if (buf[i] == '(' || buf[i] == '[')
				s.push(buf[i]);
			else {
				if (s.empty() || (buf[i]==')'&&s.top()!='(') || (buf[i]==']'&&s.top()!='[')) {
					is_correct = false;
					break;
				}
				else
					s.pop();
			}
		}
		if (is_correct && s.empty())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
