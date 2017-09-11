# include <cstdio>
# include <cstring>
# include <iostream>
# include <string>
# include <sstream>
using namespace std;

const int maxn = 100000 + 5;
int s1[maxn], s2[maxn];
int ansN, ansV;

void solve(int l1, int r1, int l2, int r2, int v) {
    // printf("%d %d %d %d %d\n", l1, r1, l2, r2, v);
    if (l1 == r1) {
        v += s1[l1];
        if (v < ansV) {ansV = v; ansN = s1[l1];}
    }
    else if (l1 < r1) {
        int r = s2[r2], p;
        for (int i = l1; i <= r1; i++)
            if (s1[i] == r) {p = i; break;}
        solve(l1, p-1, l2, l2+p-l1-1, v+r);
        solve(p+1, r1, r2-r1+p, r2-1, v+r);
    }
}

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    string buff;
    while (getline(cin, buff)) {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        ansN = 0; ansV = 90000000;
        stringstream ss(buff);
        int cnt = 0;
        while (ss >> s1[cnt++]) ;
        int len = cnt-1;
        getline(cin, buff);
        stringstream ss2(buff);
        cnt = 0;
        while (ss2 >> s2[cnt++]) ;
        if (len == 1) {
            printf("%d\n", s1[0]);
            continue;
        }
        int r = s2[len-1], p;
        for (int i = 0; i < len; i++)
            if (s1[i] == r) {p = i; break;}
        solve(0, len-1, 0, len-1, 0);
        printf("%d\n", ansN);
    }
    return 0;
}
