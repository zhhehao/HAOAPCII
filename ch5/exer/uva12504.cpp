# include <iostream>
# include <map>
# include <cctype>
# include <set>
# include <string>
# include <sstream>
using namespace std;

map <string, string> old_dict, new_dict;
set <string> sp, sm, sc, keys;

void dict_input(map <string, string>& m) {
	string buf;
	getline(cin ,buf);
	for (int i = 0; i < buf.length(); i++)
		if (!isalnum(buf[i]))
			buf[i] = ' ';
	stringstream ss(buf);
	string key, value;
	while (ss >> key >> value) {
		m[key] = value;
		keys.insert(key);
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t; cin >> t; string buf; getline(cin, buf);
	while (t--) {
		old_dict.clear();
		new_dict.clear();
		keys.clear();
		dict_input(old_dict);
		dict_input(new_dict);
		sp.clear(); sm.clear(); sc.clear();
		set <string> :: iterator it;
		for (it = keys.begin(); it != keys.end(); ++it) {
			if (new_dict.count(*it) && !old_dict.count(*it))
				sp.insert(*it);
			else if (!new_dict.count(*it) && old_dict.count(*it))
				sm.insert(*it);
			else if (new_dict.count(*it) && old_dict.count(*it) && new_dict[*it] != old_dict[*it])
				sc.insert(*it);
		}
		bool no_change = true;
		if (!sp.empty()) {
			cout << '+';
			for (it = sp.begin(); it != sp.end(); ++it) {
				if (it != sp.begin()) cout << ',';
				cout << *it;
			}
			cout << "\n";
			no_change = false;
		}
		if (!sm.empty()) {
			cout << '-';
			for (it = sm.begin(); it != sm.end(); ++it) {
				if (it != sm.begin()) cout << ',';
				cout << *it;
			}
			cout << "\n";
			no_change = false;
		}
		if (!sc.empty()) {
			cout << '*';
			for (it = sc.begin(); it != sc.end(); ++it) {
				if (it != sc.begin()) cout << ',';
				cout << *it;
			}
			cout << "\n";
			no_change = false;
		}
		if (no_change) cout << "No changes\n";
		cout << "\n";
	}
	return 0;
}