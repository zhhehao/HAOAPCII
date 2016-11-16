# include <iostream>
# include <queue>
# include <stack>
# include <string>
# include <sstream>
using namespace std;

queue <int> a, b;
stack <int> s;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	for (;;) {
		cin >> n; if (n == 0) break;
		string buf;
		getline(cin, buf);
		for (;;) {
			while (!a.empty()) a.pop();
			while (!b.empty()) b.pop();
			while (!s.empty()) s.pop();
			getline(cin, buf);
			if (buf[0] == '0') break;
			stringstream ss(buf);
			int c;
			while (ss >> c) b.push(c);
			for (int i = 1; i <=n; i++) a.push(i);
			bool ok = true;
			while (!b.empty()) {
				if (!a.empty()) {
					// cout << a.front() << "-" << b.front() << endl;
					if (b.front() == a.front()) {
						b.pop(); a.pop();
					}
					else if (b.front() > a.front()) {
						s.push(a.front()); a.pop();
					}
					else {
						if (!s.empty() && s.top() == b.front()) {
							s.pop(); b.pop();
						}
						else {
							ok = false;
							break;
						}
					}
				}
				else {
					// cout << s.top() << "+" << b.front() << endl;
					if (!s.empty() && s.top() == b.front()) {
						s.pop(); b.pop();
					}
					else {
						ok = false;
						break;
					}
				}
			}
			if (ok) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << "\n";
	}
	return 0;
}
