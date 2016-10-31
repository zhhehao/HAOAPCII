/*
** use stl to complete this
*/

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

vector <string> vstr;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	while (cin >> n) {
		vstr.resize(0);
		int len = 0;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s.length() > len)
				len = s.length();
			vstr.push_back(s);
		}
		sort(vstr.begin(), vstr.end());
		for (int i = 0; i < 60; i++)
			cout << '-';
		cout << "\n";
		int col = 62 / (len+2);
		int step = (n % 2 == 0) ? n / col : n / col + 1;
		for (int i = 0; i < step ; i++) {
			int next = i;
			for (;;) {
				if (next + step >= n) {
					cout.width(len);
					cout.fill(' ');
					cout.setf(ios::left);
					cout << vstr[next] << "\n";
					break;
				}
				else {
					cout.width(len+2);
					cout.fill(' ');
					cout.setf(ios::left);
					cout << vstr[next];
				}
				next += step;
			}
		}
	}
	return 0;
}
