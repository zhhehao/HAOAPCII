# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <cctype>
using namespace std;

const int maxn = 1000 + 5;

map <char, int> arr_index;
map <string, int> arr_value;
vector <string> program;

int get_value(string& s ) {
	if (isdigit(s[0])) return stoi(s);
	string s_in = s.substr(2, s.length()-3);
	if (isdigit(s_in[0])) {
		int ind = stoi(s_in);
		// index out range
		if (arr_index[s[0]] <= ind) return -1;
		string key = s[0] + to_string(ind);
		if (!arr_value.count(key)) return -1;
		return arr_value[key];
	}
	else {
		int get_ind = get_value(s_in);
		if (get_ind < 0) return -1;
		if (arr_index[s[0]] <= get_ind) return -1;
		string key2 = s[0] + to_string(get_ind);
		if (!arr_value.count(key2)) return -1;
		return arr_value[key2];
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	string buf;
	for (;;) {
		// init
		program.resize(0);
		arr_index.clear();
		arr_value.clear();
		// get input
		getline(cin, buf);
		if (buf[0] == '.') break;
		program.push_back(buf);
		for (;;) {
			getline(cin, buf);
			if (buf[0] == '.') break;
			else program.push_back(buf);
		}
		// process program by line
		bool no_bug = true;
		for (int i = 0; i < program.size(); i++) {
			int pos = program[i].find('=');
			// declaraiton
			if (pos < 0) {
				int ind = stoi(program[i].substr(2, program[i].find(']')-2));
				// handle declare like a[0]
				if (ind == 0)
					arr_index[program[i][0]] = -1;
				else
					arr_index[program[i][0]] = ind;
			}
			// assignment
			else {
				string left_str = program[i].substr(0, pos);
				string right_str = program[i].substr(pos+1);
				int right = get_value(right_str);
				if (right < 0) {cout << i+1 << "\n"; no_bug = false; break;}
				string left_in = left_str.substr(2, left_str.length()-3);
				int left = get_value(left_in);
				if (left < 0 || left >= arr_index[left_str[0]]) {cout << i+1 << "\n"; no_bug = false; break;}
				arr_value[left_str[0] + to_string(left)] = right;
			}
		}
		if (no_bug) cout << "0\n";
	}
	return 0;
}