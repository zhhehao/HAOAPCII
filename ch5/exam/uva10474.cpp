/*
** use vector can solve this problem
*/

# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

vector <int> marbles;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, q, kase = 1;
	while(scanf("%d%d", &n, &q) && n) {
		int number;
		marbles.resize(0);
		while(n--) {
			scanf("%d", &number);
			marbles.push_back(number);
		}
		sort(marbles.begin(), marbles.end());
		printf("CASE# %d:\n", kase++);
		while(q--) {
			scanf("%d", &number);
			int ans = 0;
			vector <int>::iterator it = find(marbles.begin(), marbles.end(), number);
			if (it != marbles.end())
				ans = it - marbles.begin() + 1;

			if (ans)
				printf("%d found at %d\n", number, ans);
			else
				printf("%d not found\n", number);
		}
	}
	return 0;
}
