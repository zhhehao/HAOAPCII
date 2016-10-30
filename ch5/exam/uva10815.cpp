/*
** using string in stl
*/

# include <iostream>
# include <string>
# include <set>
# include <sstream>
# include <cctype>
using namespace std;

set <string> dict;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	string line;
	dict.clear();
	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i]))
				line[i] = tolower(line[i]);
			else
				line[i] = 32;
		}
		stringstream ss(line);
		string str;
		while (ss >> str) {
			dict.insert(str);
		}
	}

	set <string>::iterator it;

	for (it = dict.begin(); it != dict.end(); ++it)
		cout << *it << endl;
	return 0;
}
