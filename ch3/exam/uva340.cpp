# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

# define maxn 1050
int secret_code[maxn], guess_code[maxn];
int secret_numbers[10], guess_numbers[10];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, kase = 0;
	while(scanf("%d", &n) == 1 && n) {
		printf("Game %d:\n", ++kase);
		memset(secret_code, 0, sizeof(secret_code));
		memset(guess_code, 0, sizeof(guess_code));
		for (int i = 0; i < n; i++)
			scanf("%d", &secret_code[i]);
		for (;;) {
			for (int i = 0; i < n; i++)
				scanf("%d", &guess_code[i]);
			if (guess_code[0] == 0)
				break;
			int x = 0, y = 0;
			memset(secret_numbers, 0, sizeof(secret_numbers));
			memset(guess_numbers, 0, sizeof(guess_numbers));
			for (int i = 0; i < n; i++) {
				secret_numbers[secret_code[i]]++;
				guess_numbers[guess_code[i]]++;
				if (secret_code[i] == guess_code[i])
					x++;
			}
			for (int i = 1; i <= 9; i++) {
				y += min(secret_numbers[i], guess_numbers[i]);
			}
			y -= x;
			printf("    (%d,%d)\n", x, y);
		}
	}
	return 0;
}