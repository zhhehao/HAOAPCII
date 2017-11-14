# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <stack>
using namespace std;

const int maxn = 30 + 2;
int q[maxn], s[maxn], n;
string line;
vector <int> ans;

void flip(int p) {
    int tmp[maxn];
    for (int i = 0; i <= p; i++)
        tmp[i] = q[i];
    for (int i = 0, j = p; i <= p; i++, j--)
        q[i] = tmp[j];
}

void solve() {
    int p = n-1;
    while (p >= 0) {
        if (q[p] == s[p]) {
            p--; continue;
        }
        int k = 0;
        while (q[k] != s[p]) k++;
        if (k == 0) {
            flip(p);
            ans.push_back(p+1);
            p--;
            continue;
        }
        flip(k);
        ans.push_back(k+1);
        flip(p);
        ans.push_back(p+1);
        p--;
    }
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (getline(cin, line)) {
        stringstream ss(line);
        n = 0;
        while (ss >> q[n]) n++;
        memcpy(s, q, sizeof(q));
        sort(s, s+n);
        ans.resize(0);
        for (int i = 0; i < n-1; i++) printf("%d ", q[i]);
        printf("%d\n", q[n-1]);
        solve();
        for (int i = 0; i < ans.size(); i++) printf("%d ", n-ans[i]+1);
        printf("0\n");
    }
    return 0;
}
