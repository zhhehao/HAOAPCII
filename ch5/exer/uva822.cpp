# include <cstdio>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

struct Topic {
	int tid, cnt, in_time, period;
	bool operator < (const Topic& b) const {
		return in_time < b.in_time;
	}
};

struct Staff {
	int pid, last_job, freetime, is_free;
	vector <int> joblist;
	bool operator < (const Staff& b) const {
		if (is_free != b.is_free) return is_free > b.is_free;
		if (last_job == b.last_job)
			return pid < b.pid;
		else
			return last_job < b.last_job;
	}
};

vector <Staff> vs;
vector <Topic> vt;
map <int, int> pool;
map <int, int> cost;

int n, m, done_cnt, kase, time_cnt, pool_cnt;

void input(void) {
	vt.resize(0); vs.resize(0);
	done_cnt = 0;
	pool.clear(); cost.clear();
	Topic t; int cost_time;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d%d", &t.tid, &t.cnt, &t.in_time, &cost_time, &t.period);
		vt.push_back(t);
		done_cnt += t.cnt;
		cost[t.tid] = cost_time;
	}
	scanf("%d", &m);
	Staff s;
	for (int i = 0; i < m; i++) {
		int job_cnt;
		scanf("%d%d", &s.pid, &job_cnt);
		s.last_job = -1;
		s.freetime = 0;
		s.is_free = 1;
		s.joblist.resize(0);
		int job;
		while (job_cnt--) {
			scanf("%d", &job);
			s.joblist.push_back(job);
		}
		vs.push_back(s);
	}
	// printf("%d\n", done_cnt);
	pool_cnt = done_cnt;
}

void update_topic(void) {
	sort(vt.begin(), vt.end());
	// for (int i = 0; i < vt.size(); i++)
	// 	printf("%d %d %d %d\n",time_cnt, vt[i].in_time, vt[i].tid, vt[i].cnt);
	// printf("\n");
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].in_time > time_cnt) break;
		if (vt[i].cnt == 0) continue;
		if (!pool.count(vt[i].tid)) pool[vt[i].tid] = 1;
		else pool[vt[i].tid]++;
		vt[i].cnt--;
		vt[i].in_time += vt[i].period;
		pool_cnt--;
	}
}

void update_staff(void) {
	for (int i = 0; i < vs.size(); i++)
		if (vs[i].freetime == time_cnt)
			vs[i].is_free = 1;
	sort(vs.begin(), vs.end());
}

void do_job(void) {
	for (int i = 0; i < vs.size(); i++) {
		if (vs[i].is_free != 1) break;
		for (int j = 0; j < vs[i].joblist.size(); j++) {
			if (pool.count(vs[i].joblist[j]) && pool[vs[i].joblist[j]] != 0) {
				// printf("Topic %d is allocated!\n", vs[i].joblist[j]);
				pool[vs[i].joblist[j]]--;
				done_cnt--;
				vs[i].last_job = time_cnt;
				vs[i].is_free = 0;
				vs[i].freetime = time_cnt + cost[vs[i].joblist[j]];
				break;
			}
		}
	}
	// for (int i = 0; i < vs.size(); i++){
	// 	printf("%d %d %d %d\n", time_cnt, vs[i].pid, vs[i].freetime, vs[i].is_free);
	// }
	// printf("\n");
}

bool is_done(void) {
	if (done_cnt == 0) {
		sort(vs.begin(), vs.end());
		if (vs[vs.size()-1].is_free == 1)
			return true;
		// else
			// printf("last one is %d\n", vs[vs.size()-1].pid);
	}
	return false;
}

void solve(void) {
	time_cnt = 0;
	for (;;) {
		// printf("time is %d, topics is %d, in pool is %d\n", time_cnt, done_cnt, pool.size());
		if (pool_cnt != 0) update_topic();
		update_staff();
		do_job();
		if (is_done()) break;
		time_cnt++;
	}
	printf("Scenario %d: All requests are serviced within %d minutes.\n", kase++, time_cnt);
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	kase = 1;
	while (scanf("%d", &n) == 1 && n) {
		input();
		solve();
	}
	return 0;
}