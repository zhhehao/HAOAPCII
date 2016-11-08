# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <sstream>
# include <cctype>
# include <set>
# include <algorithm>
using namespace std;

const int maxn = 100 + 5;
const int maxm = 600000;

vector <string> article[maxn];
map <string, int> dict[maxn];
set <int> terms[maxm];

int n, cnt, m;

void input(void) {
	string buf;
	cnt = 0;
	cin >> n; getline(cin, buf);
	for (int i = 0; i < n; i++) {
		article[i].resize(0);
		dict[i].clear();
		for (;;) {
			getline(cin, buf);
			if (buf[0] == '*') break;
			article[i].push_back(buf);
			int line_num = article[i].size()-1;
			for (int j = 0; j < buf.length(); j++)
				if (!isalpha(buf[j])) buf[j] = ' ';
				else buf[j] = tolower(buf[j]);
			stringstream ss(buf);
			string term;
			while (ss >> term) {
				// cout << i << ":" << term + "\n";
				if (dict[i].count(term)) {
					terms[dict[i][term]].insert(line_num);
				}
				else {
					dict[i][term] = cnt++;
					terms[dict[i][term]].clear();
					terms[dict[i][term]].insert(line_num);
				}
			}
			// cout << "dict:" << i << "'s size is " << dict[i].size() << endl;
		}
	}
	// cout << "cnt is " << cnt << endl;
}

bool search_not(string& s) {
	string term = s.substr(4);
	bool is_printed = false, is_find = false;
	for (int i = 0; i < n; i++) {
		if (!dict[i].count(term)) {
			if (is_printed) cout << "----------\n";
			for (int j = 0; j < article[i].size(); j++)
				cout << article[i][j] << "\n";
			is_printed = true;
			is_find = true;
		}
	}
	return is_find;
}

bool search_and(string& s) {
	int pos = s.find("A");
	string t1 = s.substr(0, pos-1);
	string t2 = s.substr(pos+4);
	bool is_printed = false, is_find = false;
	set <int> s1, s2; s1.clear(); s2.clear();
	for (int i = 0; i < n; i++) {
		if (dict[i].count(t1) && dict[i].count(t2)) {
			if (is_printed) cout << "----------\n";
			set <int>& s1 = terms[dict[i][t1]];
			set <int>& s2 = terms[dict[i][t2]];
			vector <int> ans; ans.resize(0);
			set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ans, ans.begin()));
			for (int j = 0; j < ans.size(); j++)
				cout << article[i][ans[j]] << "\n";
			is_printed = true;
			is_find = true;
		}
	}
	return is_find;
}

bool search_or(string& s) {
	int pos = s.find("O");
	string t1 = s.substr(0, pos-1);
	string t2 = s.substr(pos+3);
	bool is_printed = false, is_find = false;
	for (int i = 0; i < n; i++) {
		if (dict[i].count(t1) || dict[i].count(t2)) {
			if (is_printed) cout << "----------\n";
			if (dict[i].count(t1) && !dict[i].count(t2)) {
				set <int> :: iterator it;
				set <int>& s1 = terms[dict[i][t1]];
				for (it = s1.begin(); it != s1.end(); ++it)
					cout << article[i][*it] << "\n";
			}
			else if (!dict[i].count(t1) && dict[i].count(t2)) {
				set <int> :: iterator it;
				set <int>& s2 = terms[dict[i][t2]];
				for (it = s2.begin(); it != s2.end(); ++it)
					cout << article[i][*it] << "\n";
			}
			else {
				set <int>& s1 = terms[dict[i][t1]];
				set <int>& s2 = terms[dict[i][t2]];
				vector <int> ans; ans.resize(0);
				set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ans, ans.begin()));
				for (int j = 0; j < ans.size(); j++)
					cout << article[i][ans[j]] << "\n";
			}
			is_printed = true;
			is_find = true;
		}
	}
	return is_find;
}

bool search_word(string& s) {
	string term = s;
	bool is_printed = false, is_find = false;
	for (int i = 0; i < n; i++) {
		if (dict[i].count(term)) {
			if (is_printed) cout << "----------\n";
			set <int>::iterator it;
			for (it = terms[dict[i][term]].begin(); it != terms[dict[i][term]].end(); ++it) {
				cout << article[i][*it] << "\n";
			}
			is_printed = true;
			is_find = true;
		}
	}
	return is_find;
}

void solve(void) {
	string buf;
	cin >> m;
	getline(cin, buf);
	for (int i = 0; i < m; i++) {
		bool not_find = false;
		getline(cin, buf);
		// cout << buf << endl;
		if (buf[0] == 'N') {
			if (!search_not(buf))
				not_find = true;
		}
		else if (buf.find("A") != string::npos) {
			if (!search_and(buf))
				not_find = true;
		}
		else if (buf.find("O") != string::npos) {
			if (!search_or(buf))
				not_find = true;
		}
		else {
			if (!search_word(buf))
				not_find = true;
		}
		if (not_find)
			cout << "Sorry, I found nothing.\n";
		cout << "==========\n";
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	input();
	solve();
	return 0;
}
