# include <cstdio>
# include <cstring>
# include <set>
# include <queue>
using namespace std;

# define maxn 1000
char sBuf[maxn], gBuf[maxn];

set <char> puzzle;
queue <char> guess;

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int rnd;
	while(scanf("%d", &rnd) == 1 && rnd > 0) {
		puzzle.clear();
		while(!guess.empty())
			guess.pop();
		scanf("%s%s", &sBuf, &gBuf);
		for (int i = 0; i < strlen(sBuf); i++)
			puzzle.insert(sBuf[i]);
		for (int i = 0; i < strlen(gBuf); i++)
			guess.push(gBuf[i]);
		printf("Round %d\n", rnd);

		int draw = 0;
		for(;;) {
			if (puzzle.count(guess.front())) {
				puzzle.erase(guess.front());
				guess.pop();
			}
			else {
				draw++;
				guess.pop();
			}
			if (draw == 7) {
				printf("You lose.\n");
				break;
			}
			if (puzzle.empty()) {
				printf("You win.\n");
				break;
			}
			if (guess.empty()) {
				printf("You chickened out.\n");
				break;
			}
		}
	}
	return 0;
}
