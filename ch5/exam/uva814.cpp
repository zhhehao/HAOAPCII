/*
** remember, same receiver only send once.
*/

# include <iostream>
# include <cstdio>
# include <map>
# include <set>
# include <vector>
# include <string>
# include <sstream>
using namespace std;

const int maxn = 100000;

map <string, int> mta;
set <string> user[maxn];
vector <string> rcpt[maxn];
map <string, int> rcpt_map;
vector <string> data;

void get_it(void) {
	string s, smta;
	int n, cnt = 0;
	mta.clear();
	for (;;) {
		cin >> s; if (s[0] == '*') break;
		cin >> smta >> n;
		if (!mta.count(smta)) {user[cnt].clear(); mta[smta] = cnt++;}
		for (int i = 0; i < n; i++) {
			cin >> s;
			// cout << s << endl;
			user[mta[smta]].insert(s);
		}
	}
}

void get_email_address(string &s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '@') {s[i] = ' '; return;}
}

void resolve_it() {
	for(;;) {
		string s, sender, sender_mta, receiver, receiver_mta;
		cin >> s;
		if (s[0] == '*') return;
		get_email_address(s);
		stringstream ss(s);
		ss >> sender >> sender_mta;
		rcpt_map.clear();
		int cnt = 0;
		map <string, string> rm_dup; rm_dup.clear();
		for (;;) {
			cin >> s; if (s[0] == '*') break;
			get_email_address(s);
			stringstream ss(s);
			ss >> receiver >> receiver_mta;
			if (!rcpt_map.count(receiver_mta)) {
				rcpt[cnt].resize(0);
				rcpt[cnt].push_back(receiver_mta);
				rcpt_map[receiver_mta] = cnt++;
			}
			if (!rm_dup.count(receiver) || rm_dup[receiver] != receiver_mta) {
				rcpt[rcpt_map[receiver_mta]].push_back(receiver);
				rm_dup[receiver] = receiver_mta;
			}
		}
		getline(cin, s);
		data.resize(0);
		for (;;) {
			getline(cin, s); if (s[0] =='*') break;
			data.push_back(s);
		}
		// output
		// if (!user[mta[sender_mta]].count(sender)) continue;
		for (int i = 0; i < cnt; i++) {
			cout << "Connection between " << sender_mta << " and " << rcpt[i][0] << "\n";
			cout << "     HELO " << sender_mta << "\n";
			cout << "     250\n";
			cout << "     MAIL FROM:<" << sender << "@" << sender_mta << ">\n";
			cout << "     250\n";
			bool need_send = false;
			for (int j = 1; j < rcpt[i].size(); j++) {
				cout << "     RCPT TO:<" << rcpt[i][j] << "@" << rcpt[i][0] << ">\n";
				if (user[mta[rcpt[i][0]]].count(rcpt[i][j])) {
					need_send = true;
					cout << "     250\n";
				}
				else
					cout << "     550\n";
			}
			if (need_send) {
				cout << "     DATA\n     354\n";
				for (int j = 0; j < data.size(); j++)
					cout << "     " << data[j] << "\n";
				cout << "     .\n     250\n";
			}
			cout << "     QUIT\n     221\n";
		}
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	get_it();
	resolve_it();
	return 0;
}