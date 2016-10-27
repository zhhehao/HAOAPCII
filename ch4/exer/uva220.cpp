/*
** using array to simulate board
** vector to use storage legal point
** set use to remove duplicate point
** dx, dy use to simulate 8 directions.
*/

# include <cstdio>
# include <cstring>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;

char board[10][10], player[3];

const int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

struct Position {
	int x, y;
	bool operator < (const Position &b) const {
		if (x == b.x)
			return y < b.y;
		else
			return x < b.x;
	}
};

vector <Position> pos;
set <Position> checkDup;

void is_legal_move(int x, int y) {
	char opponent = (player[0] == 'W' ? 'B' : 'W');
	for (int i = 0; i < 8; i++) {
		int newx = x + dx[i], newy = y + dy[i];
		if (newx < 1 || newx > 8 || newy < 1 || newy > 8 || board[newx][newy] != opponent) continue;
		newx += dx[i];
		newy += dy[i];
		bool legal = true;
		while(board[newx][newy] == opponent) {
			newx += dx[i];
			newy += dy[i];
			if (newx < 1 || newx > 8 || newy < 1 || newy > 8) {
				legal = false;
				break;
			}
		}
		if (legal && board[newx][newy] == '-') {
			Position p;
			p.x = newx;
			p.y = newy;
			if (!checkDup.count(p)) {
				pos.push_back(p);
				checkDup.insert(p);
			}
		}
	}
}

void list() {
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			if (board[i][j] == player[0])
				is_legal_move(i, j);
		}
	}
	if(pos.empty())
		printf("No legal move.\n");
	else {
		sort(pos.begin(), pos.end());
		for(int i = 0; i < pos.size(); i++) {
			if (i > 0)
				printf(" ");
			printf("(%d,%d)", pos[i].x, pos[i].y);
		}
		printf("\n");
		pos.resize(0);
		checkDup.clear();
	}
}

void putStat() {
	int bcnt = 0, wcnt = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (board[i][j] == 'B')
				bcnt++;
			else if (board[i][j] == 'W')
				wcnt++;
		}
	}
	printf("Black - %2d White - %2d\n", bcnt, wcnt);
}

void move(int x, int y) {
	char opponent = (player[0] == 'W' ? 'B' : 'W');
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			if (board[i][j] == player[0])
				is_legal_move(i, j);
		}
	}
	Position p;
	p.x = x;
	p.y = y;
	if (pos.empty() || !checkDup.count(p))
		swap(player[0], opponent);
	pos.resize(0);
	checkDup.clear();

	board[x][y] = player[0];

	for (int i = 0; i < 8; i++) {
		int newx = x + dx[i], newy = y + dy[i];
		if (newx < 1 || newx > 8 || newy < 1 || newy > 8 || board[newx][newy] != opponent) continue;
		int startx = newx, starty = newy;
		// printf("startx is %d, starty is %d\n", startx, starty);
		newx += dx[i];
		newy += dy[i];
		bool legal = true;
		while(board[newx][newy] == opponent) {
			newx += dx[i];
			newy += dy[i];
			if (newx < 1 || newx > 8 || newy < 1 || newy > 8) {
				legal = false;
				break;
			}
		}
		if (legal && board[newx][newy] == player[0]) {
			int endx = newx, endy = newy;
			// printf("endx is %d\n", endx);
			while(startx != endx || starty != endy) {
				board[startx][starty] = player[0];
				startx += dx[i];
				starty += dy[i];
			}
		}
	}

	putStat();
	swap(player[0], opponent);
}

void quit() {
	for(int i = 1; i <= 8; i++)
		printf("%s\n", board[i]+1);
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);

	int N, kase = 0;
	scanf("%d", &N);

	while(N--) {
		pos.resize(0);
		checkDup.clear();
		memset(board, '\0', sizeof(board));
		memset(player, '\0', sizeof(player));

		if(kase++)
			printf("\n");

		for(int i = 1; i <= 8; i++)
			scanf("%s", board[i]+1);

		scanf("%s", player);

		char command[5];
		memset(command, '\0', sizeof(command));
		for(;;) {
			scanf("%s", command);
			if (command[0] == 'L')
				list();
			else if (command[0] == 'M')
				move(command[1]-'0', command[2]-'0');
			else {
				quit();
				break;
			}
		}
	}
	return 0;
}