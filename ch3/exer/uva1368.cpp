# include <cstdio>
# include <cstring>
using namespace std;

# define maxm 52
# define maxn 1005

char dna[maxm][maxn];
int mark[4][maxn];

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d%d", &m, &n);
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < m; i++) {
			scanf("%s", dna[i]);
			for (int j = 0; j < n; j++) {
				switch(dna[i][j]) {
					case 'A':
						mark[0][j]++;
						break;
					case 'C':
						mark[1][j]++;
						break;
					case 'G':
						mark[2][j]++;
						break;
					case 'T':
						mark[3][j]++;
						break;
				}
			}
		}
		int ce = 0;
		for (int i = 0; i < n; i++) {
			int max = 0;
			for (int j = 1; j < 4; j++) {
				if (mark[j][i] > mark[max][i])
					max = j;
				}
			switch(max) {
				case 0:
					printf("A");
					break;
				case 1:
					printf("C");
					break;
				case 2:
					printf("G");
					break;
				case 3:
					printf("T");
					break;
			}
			ce += (m - mark[max][i]);
		}
		printf("\n%d\n", ce);
	}
	return 0;
}
