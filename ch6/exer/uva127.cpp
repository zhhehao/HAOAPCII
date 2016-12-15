# include <cstdio>
# include <vector>
# include <stack>
using namespace std;

struct Card {
	char r, s;
};

vector <stack<Card> > p;
char ch[5];

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif

	while (scanf("%s", ch) == 1 && ch[0] != '#') {
		p.resize(0); Card card; int cnt = 52;
		do {
			card.r = ch[0]; card.s = ch[1];
			stack <Card> c; c.push(card);
			p.push_back(c);
			cnt--;
		} while (cnt > 0 && scanf("%s", ch) == 1);

		for (int i = 1; i < p.size(); i++) {
			if (i >= 3 && (p[i].top().r == p[i-3].top().r || p[i].top().s == p[i-3].top().s)) {
				p[i-3].push(p[i].top());
				p[i].pop();
				if (p[i].empty()) p.erase(p.begin()+i);
				i = 0;
				continue;
			}
			if (p[i].top().r == p[i-1].top().r || p[i].top().s == p[i-1].top().s) {
				p[i-1].push(p[i].top());
				p[i].pop();
				if (p[i].empty()) p.erase(p.begin()+i);
				i = 0;
				continue;
			}
		}

		printf("%d pile", p.size());
		if (p.size() > 1) printf("s");
		printf(" remaining:");
		for (int i = 0; i < p.size(); i++)
			printf(" %d", p[i].size());
		printf("\n");
	}
	return 0;
}