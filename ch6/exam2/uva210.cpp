# include <iostream>
# include <string>
# include <sstream>
# include <queue>
# include <deque>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

const int maxn = 100000 + 10;
int config[7], var[26], T;
string buff;

struct Program {
    int id;
    vector <string> statement;
}

int main(void) {

# ifdef LOCAL
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
# endif

    cin >> T; getline(cin, buff);
    while (T--) {
        memset(var, 0, sizeof(var));
        for (int i = 0; i < 7; i++) cin >> config[i];

    }
    return 0;
}
