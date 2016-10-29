/*
** simulate use set, struct, vector
*/

# include <cstdio>
# include <set>
# include <vector>
using namespace std;

struct Students {
	int a, b, c;
};

vector <Students> stu;
set <vector<int>> status;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int N, kase = 1;
	while (scanf("%d", &N) && N) {
		stu.resize(0);
		status.clear();
		while (N--) {
			Students s;
			scanf("%d%d%d", &s.a, &s.b, &s.c);
			stu.push_back(s);
		}
		vector <int> vstatus;
		int ans = -1;
		bool can_sleep;

		for (int time = 1;; time++) {
			int awake_cnt = 0;
			vstatus.resize(0);
			for (int i = 0; i < stu.size(); i++) {
				// printf("a is %d, b is %d, c is %d\n", stu[i].a, stu[i].b, stu[i].c);
				vstatus.push_back(stu[i].c);
				if (stu[i].c <= stu[i].a)
					awake_cnt++;
			}
			// printf("awake is %d\n", awake_cnt);
			if (awake_cnt == stu.size()) {
				ans = time;
				break;
			}
			if (status.count(vstatus))
				break;
			else
				status.insert(vstatus);

			if (awake_cnt < stu.size() - awake_cnt)
				can_sleep = true;
			else
				can_sleep = false;

			for (int i = 0; i < stu.size(); i++) {
				if (!can_sleep && stu[i].c == stu[i].a) {
					stu[i].c == 1;
				}
				else {
					stu[i].c ++;
					if (stu[i].c > stu[i].a + stu[i].b)
						stu[i].c = 1;
				}
			}
		}

		printf("Case %d: %d\n", kase++, ans);
	}
	return 0;
}
