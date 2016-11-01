/*
**
*/

# include <cstdio>
# include <vector>
# include <climits>
# include <cstring>
# include <cctype>
# include <algorithm>
using namespace std;

struct Player {
	char name[21];
	int place, rd[4][1];
	double money;
	bool is_tie, is_amateur;
};

vector <Player> player;

struct Place {
	int score, id;
	char name[21];
	bool operator < (const Place& b) const {
		if (score == b.score) {
			for (int i = 0; i < 20; i++) {
				if (name[i] == b.name[i]) continue;
				return name[i] < b.name[i];
			}
		}
		else
			return score < b.score;
	}
};

vector <Place> round2;
vector <Place> round4;
vector <Place> dq;

int getScore(char* a) {
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (isalpha(*(a+i)))
			return INT_MAX;
		if (isdigit(*(a+i)))
			ans = ans*10 + *(a+i) - '0';
	}
	return ans;
}

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		// init container
		player.resize(0);
		round2.resize(0);
		round4.resize(0);
		dq.resize(0);
		// get purse and prize percentage
		double prize[71];
		for (int i = 0; i < 71; i++) scanf("%f", &prize[i]);
		// get player information
		int n;
		scanf("%d", &n);
		getchar(); // remove a "\n"
		for (int i = 0; i < n; i++) {
			Player p;
			p.is_amateur = false;
			for (int j = 0; j < 20; j++) {
				p.name[j] = getchar();
				if (p.name[j] == '*')
					p.is_amateur = true;
			}
			p.name[20] = '\0';
			// printf("Name is %s\n", p.name);
			char score[3];
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++)
					score[k] = getchar();
				p.rd[j][0] = getScore(score);
				if (p.rd[j][0] == INT_MAX)
					break;
			}
			p.money = 0.0;
			player.push_back(p);
			// get all players with first, second no DQ
			if (p.rd[0][0] != INT_MAX && p.rd[1][0] != INT_MAX) {
				Place pl;
				for (int k = 0; k < 21; k++)
					pl.name[k] = p.name[k];
				pl.score = p.rd[0][0] + p.rd[1][0];
				pl.id = player.size() - 1;
				round2.push_back(pl);
			}
			getchar();
		}
		// get first 70 players
		sort(round2.begin(), round2.end());
		int size;
		if (round2.size() > 70) {
			size = 70;
			while (round2[size].score == round2[69].score) {
			size++;
			if (size > round2.size())
				break;
			}
			round2.resize(size);
		}

		for (int i = 0; i < round2.size(); i++) {
			Place pp;
			if (player[round2[i].id].rd[2][0] != INT_MAX && player[round2[i].id].rd[3][0] != INT_MAX) {
				pp.score = 0;
				for (int j = 0; j < 4; j++) pp.score += player[round2[i].id].rd[j][0];
				pp.id = round2[i].id;
				for (int k = 0; k < 21; k++)
					pp.name[k] = round2[i].name[k];
				round4.push_back(pp);
			}
			else {
				pp.score = INT_MAX;
				pp.id = round2[i].id;
				dq.push_back(pp);
			}
		}
		sort(round4.begin(), round4.end());

		for (int i = 0; i < round4.size(); i++) {
			if (i > 0 && (round4[i].score == round4[i-1].score))
				player[round4[i].id].place = player[round4[i-1].id].place;
			else
				player[round4[i].id].place = i+1;
		}


		if (kase++) printf("\n");
		printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
		for (int i = 0; i < 71; i++) printf("-");
		printf("\n");

		for (int i = 0; i < round4.size(); i++) {
			int id = round4[i].id;
			printf("%s ", player[id].name);
			printf("%-10d", player[id].place);
			printf("%-5d%-5d%-5d%-5d%-10d$%9.2f\n", player[id].rd[0][0], player[id].rd[1][0], player[id].rd[2][0], player[id].rd[3][0], round4[i].score, player[id].money);
		}


		// printf("players are %d, round2 are %d, round4 are %d, dq are %d\n", player.size(), round2.size(), round4.size(), dq.size());
		// for (int i = 0; i < round2.size(); i++)
		// 	printf("(%d,%d) ", round2[i].score, round2[i].id);
		// printf("\n");
		// for (int i = 0; i < round4.size(); i++)
		// 	printf("(%d,%d) ", round4[i].score, round4[i].id);
		// printf("\n");
		// for (int i = 0; i < dq.size(); i++)
		// 	printf("(%d,%d) ", dq[i].score, dq[i].id);
		// printf("\n");
	}
	return 0;
}
