/*
** iterate columns and use map to verify struct (r1, r2)
** string can be transfer to int for simplify compare
*/

# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <sstream>
# include <cstdio>
using namespace std;

const int maxn = 10000 + 5;
const int maxm = 10 + 2;

int database[maxn][maxm];

map <string, int> mcode;
vector <string> vcode;

struct DB_val {
	int v1, v2;
	bool operator < (const DB_val& b) const {
		if (v1 == b.v1)
			return v2 < b.v2;
		else
			return v1 < b.v1;
	}
};

map <DB_val, int> mchk;

int code(string s) {
	if (mcode.count(s))
		return mcode[s];
	vcode.push_back(s);
	return mcode[s] = vcode.size() - 1;
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, m;
	while (cin >> n >> m) {
		mcode.clear();
		vcode.resize(0);
		string line;
		getline(cin, line); // eat a "\n"
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			for (int j = 0; j < line.length(); j++) {
				if (line[j] == ' ')
					line[j] = '.';
				else if (line[j] == ',')
					line[j] = ' ';
			}
			stringstream ss(line);
			string str;
			for (int k = 0; k < m; k++) {
				ss >> str;
				database[i][k] = code(str);
			}
		}

		int c1, c2, r;
		bool is_found = false;
		for (int c1 = 0; c1 < m; c1++) {
			for (int c2 = c1+1; c2 < m; c2++) {
				mchk.clear();
				for (int r = 0; r < n; r++) {
					DB_val dv;
					dv.v1 = database[r][c1];
					dv.v2 = database[r][c2];
					if (mchk.count(dv)) {
						printf("NO\n%d %d\n%d %d\n", mchk[dv]+1, r+1, c1+1, c2+1);
						is_found = true;
						goto end;
					}
					mchk[dv] = r;
				}
			}
		}

end:
		if (!is_found)
			printf("YES\n");
	}
	return 0;
}