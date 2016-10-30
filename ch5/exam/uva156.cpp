/*
** use map to stat
*/

# include <cctype>
# include <iostream>
# include <sstream>
# include <map>
# include <vector>
# include <algorithm>
using namespace std;

vector <string> value, key;
map <string, int> dict;

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	value.resize(0);
	key.resize(0);
	dict.clear();
	string buf, str;
	while (cin >> buf) {
		if (buf[0] == '#') break;
		stringstream ss(buf);
		while (ss >> str) {
			value.push_back(str);
		}
	}
	sort(value.begin(), value.end());

	for (int i = 0; i < value.size(); i++) {
		str = value[i];
		for (int j = 0; j < str.length(); j++)
			str[j] = tolower(str[j]);
		sort(str.begin(), str.end());
		key.push_back(str);
	}

	for (int i = 0; i < key.size(); i++) {
		if (dict.count(key[i]))
			dict[key[i]]++;
		else
			dict[key[i]] = 1;
	}

	for (int i = 0; i < value.size(); i++)
		if (dict[key[i]] == 1)
			cout << value[i] << endl;

	return 0;
}
