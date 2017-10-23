# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <set>
# include <algorithm>
# include <cstring>
# include <cstdio>
using namespace std;

string line;
int node_cnt[26], k, ans[8], pre[8];
set <int> g[26], c;
vector <int> node;

void _input() {
    for (int i = 0; i < line.size(); i++)
        if (line[i] == ';')
            line[i] = ' ';

    memset(node_cnt, 0, sizeof(node_cnt));
    for (int i = 0; i < 26; i++) g[i].clear();
    node.resize(0); c.clear();
    stringstream ss(line);
    string word;
    while (ss >> word) {
        int n1 = word[0]-'A', n2;
        if (c.count(n1) == 0) {
            c.insert(n1);
            node.push_back(n1);
        }
        for (int i = 2; i < word.size(); i++) {
            n2 = word[i] - 'A';
            if (c.count(n2) == 0) {
                c.insert(n2);
                node.push_back(n2);
            }
            g[n1].insert(n2);
            g[n2].insert(n1);
        }
    }

    sort(node.begin(), node.end());
    for (int i = 0; i < 26; i++) {
        node_cnt[i] = g[i].size();
    }

    // for (int i = 0; i < 26; i++)
    //     printf("%d ", g[i].size());
    // printf("\n");

    memset(ans, 0, sizeof(ans));
    k = 10;
}

int calk(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if ((g[pre[i]].count(pre[n]) != 0) && result < n-i)
            result = n - i;
    }
    return result;
}

void perm(int n, int k1) {
    if (n == node.size() && k1 < k) {
        k = k1;
        memcpy(ans, pre, sizeof(ans));
        return;
    }
    for (int i = 0; i < node.size(); i++) {
        int ok = 1;
        for (int j = 0; j < n; j++) {
            if (node[i] == pre[j]) {
                ok = 0; break;
            }
        }
        if (!ok) continue;
        pre[n] = node[i];
        int k2 = 0;
        if (n > 0 && (k2 = calk(n)) >= k) continue;
        if (k2 > k1)
            perm(n+1, k2);
        else
            perm(n+1, k1);
    }
}

void _solve() {
    perm(0, 0);
}

void _output() {
    for (int i = 0; i < node.size(); i++) {
        printf("%c ", ans[i]+'A');
    }
    printf("-> %d\n", k);
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    while (getline(cin, line) && line[0] != '#') {
        _input();
        _solve();
        _output();
    }
    return 0;
}
