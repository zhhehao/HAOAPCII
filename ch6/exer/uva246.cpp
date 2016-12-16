# include <cstdio>
# include <vector>
# include <deque>
# include <set>
using namespace std;

vector <deque<int> > p;
set <vector <deque<int> > > v;

int main(void) {

# ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
# endif
	int num;
	while (scanf("%d", &num) == 1 && num != 0) {
		p.resize(0); v.clear(); deque <int> c;
		for (int i = 0; i < 8; i++) p.push_back(c);
		p[1].push_back(num);
		for (int i = 2; i <= 7; i++) {scanf("%d", &num); p[i].push_back(num);}
		for (int i = 1; i <= 7; i++) {scanf("%d", &num); p[i].push_back(num);}
		for (int i = 15; i <= 52; i++) {scanf("%d", &num); p[0].push_back(num);}
		v.insert(p);
		int d_cnt = 14, cur = 1, x1, x2, x3, sum;
		bool go_next;
		for (;;) {
			// printf("cur is %d\n", cur);
			p[cur].push_back(p[0].front()); //printf("%d ", p[cur].back());
			p[0].pop_front(); d_cnt++;
checkagain:
			go_next = true;
			if (p[cur].size() == 3) {
				x1 = p[cur].front(); p[cur].pop_front();
				sum = x1+p[cur].front()+p[cur].back();
				if (sum == 10 || sum == 20 || sum == 30) {
					p[0].push_back(x1);
					p[0].push_back(p[cur].front());
					p[0].push_back(p[cur].back());
					p[cur].pop_front();
					p[cur].pop_front();
				}
				else {
					p[cur].push_front(x1);
				}
			}
			else if (p[cur].size() > 3) {
				x1 = p[cur].front(); p[cur].pop_front();
				x3 = p[cur].back(); p[cur].pop_back();
				sum = x1 + p[cur].front() + x3;
				if (sum == 10 || sum == 20 || sum == 30) {
					p[0].push_back(x1);
					p[0].push_back(p[cur].front());
					p[0].push_back(x3);
					p[cur].pop_front();
					go_next = false;
				}
				if (go_next) {
					sum = x1 + p[cur].back() + x3;
					if (sum == 10 || sum == 20 || sum == 30) {
						p[0].push_back(x1);
						p[0].push_back(p[cur].back());
						p[cur].pop_back();
						p[0].push_back(x3);
						go_next = false;
					}
				}
				if (go_next) {
					p[cur].push_front(x1);
					x2 = p[cur].back(); p[cur].pop_back();
					sum = p[cur].back() + x2 + x3;
					if (sum == 10 || sum == 20 || sum == 30) {
						p[0].push_back(p[cur].back());
						p[cur].pop_back();
						p[0].push_back(x2);
						p[0].push_back(x3);
						go_next = false;
					}
				}
				if (go_next) {
					p[cur].push_back(x2);
					p[cur].push_back(x3);
				}
				if (!go_next && p[cur].size() >= 3) goto checkagain;
			}
			if (p[0].size() == 52) {printf("Win : %d\n", d_cnt);break;}
			if (p[0].size() == 0) {printf("Loss: %d\n", d_cnt); break;}
			if (v.count(p)) {printf("Draw: %d\n", d_cnt); break;} else v.insert(p);
			if (cur == p.size()-1) cur = 1;
			else cur++;
			while (p[cur].size() == 0) {
				cur++;
				if (cur == p.size()) cur = 1;
			}
		}
	}
	return 0;
}