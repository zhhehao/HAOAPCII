# include <iostream>
# include <string>
# include <sstream>
# include <vector>
using namespace std;

const int maxn = 1000 + 5;

vector <string> s[maxn];
vector <int> len;

int cnt;

void input(void) {
	len.resize(0);
	string buf, word;
	cnt = 0;
	while (getline(cin, buf)) {
		s[cnt].resize(0);
		stringstream ss(buf);
		int lcnt = 0;
		while (ss >> word) {
			s[cnt].push_back(word);
			if (lcnt >= len.size())
				len.push_back(word.length());
			else if (len[lcnt] < word.length()) {
				len[lcnt] = word.length();
			}
			lcnt++;
		}
		cnt++;
	}
}

void output(void) {
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < s[i].size() - 1; j++) {
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(len[j]+1);
			cout << s[i][j];
		}
		cout << s[i][s[i].size()-1] << "\n";
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	input();
	output();
	return 0;
}