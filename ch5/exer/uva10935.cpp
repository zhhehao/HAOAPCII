# include <cstdio>
# include <queue>
using namespace std;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1 && n) {
		queue <int> q;
		for (int i = 1; i <= n; i++) q.push(i);
		printf("Discarded cards:");
		int cnt = 0;
		for (;;) {
			int out = q.front();
			q.pop();
			if (q.empty()) {
				printf("\nRemaining card: %d\n", out);
				break;
			}
			if (cnt++) printf(",");
			printf(" %d", out);
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}
