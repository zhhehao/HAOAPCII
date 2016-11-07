# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <sstream>
# include <cctype>
using namespace std;

const int maxn = 100 + 5;
const int maxm = 600000;

vector <string> article[maxn];
map <string, int> dict[maxn];
vector <int> terms[maxm];

int n, cnt, m;

void input(void) {
	string buf;
	cnt = 0;
	cin >> n; getline(cin, buf);
	for (int i = 0; i < n; i++) {
		article[i].resize(0);
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
			dict[i].clear();
			while (ss >> term) {
				if (dict[i].count(term)) {
					terms[dict[i][term]].push_back(line_num);
				}
				else {
					dict[i][term] = cnt++;
					terms[dict[i][term]].resize(0);
					terms[dict[i][term]].push_back(line_num);
				}
			}
		}
	}
}

void search_and(string& s) {

}

void search_or(string& s) {

}

void search_not(string& s) {

}

void search_word(string& s) {

}

void solve(void) {
	string buf;
	cin >> m;
	getline(cin, buf);
	for (int i = 0; i < m; i++) {
		getline(cin, buf);
		if (buf.find("AND") > 0)
			search_and(buf);
		else if (buf.find("OR") > 0)
			search_or(buf);
		else if (buf[0] == 'N')
			search_not(buf);
		else
			search_word(buf);
		cout << "==========\n";
	}
}

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	input();
	solve();
	return 0;
}