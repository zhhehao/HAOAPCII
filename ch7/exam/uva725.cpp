# include <cstdio>
# include <cstring>
# include <set>
# include <string>
# include <iostream>
using namespace std;

int chk[10], n, cnt;
char ans[50];
set <string> s;

bool chk_num(int num) {
    if (num < 10000) chk[0]++;
    if (chk[0] > 1) return false;
    int dig;
    while (num > 0) {
        dig = num % 10;
        chk[dig]++;
        if (chk[dig] > 1) return false;
        num /= 10;
    }
    return true;
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif
    int kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        s.clear();
        cnt = 0; memset(ans, '\0', sizeof(ans));
        for (int dnu = 1234; dnu <= 98765; dnu++) {
            int nu = dnu * n;
            if (nu > 98765) continue;
            memset(chk, 0, sizeof(chk));
            if (!chk_num(dnu)) continue;
            if (!chk_num(nu)) continue;
            // printf("cnt is %d\n", cnt);
            // printf("%d %d\n", nu, dnu);
            sprintf(ans, "%05d / %05d = %d\n", nu, dnu, n);
            string str = string(ans);
            s.insert(str);
            cnt++;
        }
        if (kase++) printf("\n");
        if (cnt) {
            set <string>::iterator it;
            for (it = s.begin(); it != s.end(); ++it)
                cout << *it;
        }
        else
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
