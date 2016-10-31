/*
** transfer data staructure is a good skill
*/

# include <cstdio>
# include <map>
# include <set>
# include <map>
# include <stack>
# include <vector>
# include <algorithm>
using namespace std;

map <set<int>, int> id_db;
vector <set<int>> set_db;
stack <int> s;

int getID(set <int> ss) {
	if (id_db.count(ss))
		return id_db[ss];
	set_db.push_back(ss);
	return id_db[ss] = set_db.size() - 1;
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		id_db.clear();
		set_db.resize(0);
		while (!s.empty()) s.pop();
		char command[10];
		while(n--) {
			scanf("%s", command);
			if (command[0]== 'P'){
				set <int> empty;
				s.push(getID(empty));
			}
			else if (command[0] == 'D'){
				s.push(s.top());
			}
			else {
				set <int> s1 = set_db[s.top()];
				s.pop();
				set <int> s2 = set_db[s.top()];
				s.pop();
				set <int> s_ans;
				if (command[0] == 'U')
					set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s_ans, s_ans.begin()));
				else if (command[0] == 'I')
					set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s_ans, s_ans.begin()));
				else {
					s_ans = s2;
					s_ans.insert(getID(s1));
				}
				s.push(getID(s_ans));
			}
			printf("%d\n", set_db[s.top()].size());
		}
		printf("***\n");
	}
	return 0;
}