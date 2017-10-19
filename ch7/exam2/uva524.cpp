# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

int n, kase, vis[17];
int prime[10] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

struct Ans {
    int a[16];
};

vector <Ans> v;

bool is_prime(int x) {
    int ok = 0;
    for (int i = 0; i < 10; i++) {
        if (x == prime[i]) {
            ok = 1; break;
        }
    }
    if (ok)
        return true;
    else
        return false;
}

void solve(int cur, Ans& ans) {
    if (cur == 0) {
        ans.a[cur] = 1;
        solve(cur+1, ans);
    }
    else if (cur == n-1) {
        for (int i = 2; i <= n; i++) {
            if (vis[i] == 0 && is_prime(i+ans.a[n-2]) && is_prime(i+1)) {
                ans.a[n-1] = i;
                v.push_back(ans);
            }
        }
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (vis[i] == 0 && is_prime(i+ans.a[cur-1])) {
                vis[i] = 1;
                ans.a[cur] = i;
                solve(cur+1, ans);
                vis[i] = 0;
            }
        }
    }
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    kase = 0;
    while (scanf("%d", &n) == 1) {
        v.resize(0); memset(vis, 0, sizeof(vis));
        Ans ans;
        solve(0, ans);
        if (kase++) printf("\n");
        printf("Case %d:\n", kase);
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < n-1; j++) {
                printf("%d ", v[i].a[j]);
            }
            printf("%d\n", v[i].a[n-1]);
        }
        // for (int i = 0; i < v.size(); i++) {
        //     printf("%d ", v[i].a[0]);
        //     for (int j = n-1; j > 1; j--) {
        //         printf("%d ", v[i].a[j]);
        //     }
        //     printf("%d\n", v[i].a[1]);
        // }
    }
    return 0;
}
