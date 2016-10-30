/*
** use vector to simulate, use status array to record position.
** four commands, actually only one.
*/

# include <cstdio>
# include <vector>
# include <cstring>
using namespace std;

const int maxn = 28;

struct Position {
	int x, y;
};

Position pos[maxn];
vector <int> block[maxn];

void putOutput(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		if (block[i].size()) {
			for (int j = 0; j < block[i].size(); j++)
				printf(" %d", block[i][j]);
		}
		printf("\n");
	}
}

void restore(int b) {
	int x = pos[b].x, y = pos[b].y;
	for (int i = block[x].size()-1; i > y; i--) {
		block[block[x][i]].push_back(block[x][i]);
		pos[block[x][i]].x = block[x][i];
		pos[block[x][i]].y = 0;
		block[x].pop_back();
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		block[i].push_back(i);
		pos[i].x = i;
		pos[i].y = 0;
	}
	char c1[10], c2[10];
	memset(c1, '\0', sizeof(c1));
	memset(c2, '\0', sizeof(c2));
	int b1, b2;
	for (;;) {
		scanf("%s", c1);
		if (c1[0] == 'q') {
			putOutput(n);
			break;
		}
		else {
			scanf("%d%s%d", &b1, c2, &b2);
			if (b1 == b2 || pos[b1].x == pos[b2].x) continue;
			if (c1[0] == 'm')
				restore(b1);
			if (c2[1] == 'n')
				restore(b2);
			int sx = pos[b1].x, sy = pos[b1].y;
			for (int i = sy; i < block[sx].size(); i++) {
				pos[block[sx][i]].x = pos[b2].x;
				pos[block[sx][i]].y = block[pos[b2].x].size();
				block[pos[b2].x].push_back(block[sx][i]);
			}
			block[sx].resize(sy);
		}
	}

	return 0;
}
