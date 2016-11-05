# include <iostream>
# include <string>
# include <set>
using namespace std;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	string s, s1, s2;
	set <string> dict;
	dict.clear();
	while (cin >> s) dict.insert(s);
	set <string>::iterator it;
	for (it = dict.begin(); it != dict.end(); ++it) {
		string str = *it;
		if (str.length() < 2) continue;
		for (int pos = 1; pos < str.length(); pos++) {
			s1 = str.substr(0, pos);
			s2 = str.substr(pos);
			if (dict.count(s1) && dict.count(s2)) {
				cout << str + "\n";
				break;
			}
		}
	}
	return 0;
}
