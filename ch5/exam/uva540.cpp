/*
** use vector<queue<int>> to simulate team queue, use map<name, gid> and map<gid, pos> to save status
*/

# include <cstdio>
# include <map>
# include <vector>
# include <queue>
using namespace std;

vector <queue<int> > teamqueue;
map <int, int> element_group;
map <int, int> group_positon;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t, kase = 1;
	while (scanf("%d", &t) == 1 && t) {
		teamqueue.resize(0);
		element_group.clear();
		group_positon.clear();
		int gid = 0, g_cnt;
		while (t--) {
			scanf("%d", &g_cnt);
			int element_name;
			for (int i = 0; i < g_cnt; i++) {
				scanf("%d", &element_name);
				element_group[element_name] = gid;
			}
			gid++;
		}
		char operation[10];
		int name, cur = 0;
		printf("Scenario #%d\n", kase++);
		for (;;) {
			scanf("%s", operation);
			if (operation[0] == 'S') break;
			if (operation[0] == 'E') {
				scanf("%d", &name);
				if (group_positon.count(element_group[name])) {
					teamqueue[group_positon[element_group[name]]].push(name);
				}
				else {
					queue<int> q;
					while (!q.empty()) q.pop();
					q.push(name);
					teamqueue.push_back(q);
					group_positon[element_group[name]] = teamqueue.size() - 1;
				}
			}
			else {
				if (teamqueue[cur].size() == 1)
					group_positon.erase(element_group[teamqueue[cur].front()]);
				printf("%d\n", teamqueue[cur].front());
				teamqueue[cur].pop();
				if (teamqueue[cur].empty())
					cur++;
			}
		}
		printf("\n");
	}
	return 0;
}