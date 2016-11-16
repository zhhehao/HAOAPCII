# include <iostream>
# include <string>
# include <sstream>
# include <queue>
# include <deque>
# include <map>
using namespace std;

const int maxn = 100000;

int n, q1, q2, q3, q4, q5, q0;

queue <string> program_db[maxn];
deque <int> ready_queue;
queue <int> blocked_queue;
map <char, int> var_map;

bool is_locked;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t, kase = 0; cin >> t;
	while (t--) {
		if (kase++) cout << "\n";
		cin >> n >> q1 >> q2 >> q3 >> q4 >> q5 >> q0;
		is_locked = false; var_map.clear();
		string buf;
		getline(cin, buf); // remove a "\n"
		for (int i = 0; i < n; i++) {
			for (;;) {
				getline(cin, buf);
				program_db[i].push(buf);
				if (buf[2] == 'd') break;
			}
			ready_queue.push_back(i);
		}
		while (!ready_queue.empty()) {
			int p = ready_queue.front(), q = q0;
			ready_queue.pop_front();
			while (q != 0) {
				string &buf = program_db[p].front();
				if (buf[2] == '=') {
					if (q < q1) break;
					q -= q1;
					stringstream ss(buf);
					string nouse;
					int value;
					ss >> nouse >> nouse >> value;
					var_map[buf[0]] = value;
				}
				else if (buf[2] == 'i') {
					if (q < q2) break;
					q -= q2;
					cout << p+1 << ": " ;
					if (var_map.count(buf[6]))
						cout << var_map[buf[6]] << "\n";
					else
						cout << "0\n";

				}
				else if (buf[2] == 'c') {
					if (q < q3) break;
					q -= q3;
					if (is_locked) {
						blocked_queue.push(p);
						goto end;
					}
					else {
						is_locked = true;
					}
				}
				else if (buf[2] == 'l') {
					if (q < q4) break;
					q -= q4;
					is_locked = false;
					if (!blocked_queue.empty()) {
						ready_queue.push_front(blocked_queue.front());
						blocked_queue.pop();
					}
				}
				else if (buf[2] == 'd') {
					if (q < q5) break;
					program_db[p].pop();
					goto end;
				}
				program_db[p].pop();
			}
			ready_queue.push_back(p);
end:
			continue;
		}
	}
	return 0;
}