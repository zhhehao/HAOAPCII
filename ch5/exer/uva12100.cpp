# include <cstdio>
# include <queue>
# include <vector>
# include <algorithm>
using namespace std;

vector <int> pv;
queue <int> pq;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		pv.resize(0);
		while (!pq.empty()) pq.pop();
		int job;
		for (int i = 0; i < n; i++) {
			scanf("%d", &job);
			pv.push_back(job);
			pq.push(job);
		}
		sort(pv.begin(), pv.end());

		int ans = 0;
		for (;;) {
			int cur_job = pq.front(); pq.pop();
			if (cur_job == pv[pv.size()-1]) {
				if (m == 0) {printf("%d\n", ans+1); break;}
				m--; ans++;
				pv.pop_back();
			}
			else {
				if (m == 0) m = pv.size()-1;
				else
					m--;
				pq.push(cur_job);
			}
		}
	}
	return 0;
}
