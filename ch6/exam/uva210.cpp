# include <iostream>
# include <string>
# include <sstream>
# include <queue>
# include <deque>
# include <cstring>
using namespace std;

const int maxn = 100000;

int n, q1, q2, q3, q4, q5, q0;

struct Program {
	int name, value;
};

queue <Program> program_db[maxn];
deque <int> ready_queue;
queue <int> blocked_queue;
int var[26];

bool is_locked;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t, kase = 0; cin >> t;
	while (t--) {
		if (kase++) cout << "\n";
		cin >> n >> q1 >> q2 >> q3 >> q4 >> q5 >> q0;
		is_locked = false;
		memset(var, 0, sizeof(var));
		string buf;
		getline(cin, buf); // remove a "\n"
		Program pp;
		for (int i = 0; i < n; i++) {
			for (;;) {
				getline(cin, buf);
				if (buf[2] == '=') {
					pp.name = buf[0] - 'a';
					stringstream ss(buf); string nouse;
					ss >> nouse >> nouse >> pp.value;
				}
				else if (buf[2] == 'i') {pp.name = -1; pp.value = buf[6]-'a';}
				else if (buf[2] == 'c') pp.name = -2;
				else if (buf[2] == 'l') pp.name = -3;
				else if (buf[2] == 'd') pp.name = -4;
				program_db[i].push(pp);
				if (pp.name == -4) break;
			}
			ready_queue.push_back(i);
		}
		while (!ready_queue.empty()) {
			int p = ready_queue.front(), q = q0;
			ready_queue.pop_front();
			while (q > 0) {
				Program &buf = program_db[p].front();
				if (buf.name >= 0) {
					// if (q < q1) break;
					q -= q1;
					var[buf.name] = buf.value;
				}
				else if (buf.name == -1) {
					// if (q < q2) break;
					q -= q2;
					cout << p+1 << ": " ;
					cout << var[buf.value] << "\n";
				}
				else if (buf.name == -2) {
					// if (q < q3) break;
					q -= q3;
					if (is_locked) {
						blocked_queue.push(p);
						goto end;
					}
					else {
						is_locked = true;
					}
				}
				else if (buf.name == -3) {
					// if (q < q4) break;
					q -= q4;
					is_locked = false;
					if (!blocked_queue.empty()) {
						ready_queue.push_front(blocked_queue.front());
						blocked_queue.pop();
					}
				}
				else if (buf.name == -4) {
					// if (q < q5) break;
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
