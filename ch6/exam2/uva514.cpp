# include <cstdio>
# include <cstring>
# include <stack>
using namespace std;

const int maxn = 1000 + 10;
int n;
int ori[maxn], obj[maxn];

int main(void) {

    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    while (scanf("%d", &n) == 1 && n) {
        int first;
        while (scanf("%d", &first) == 1 && first) {
            memset(ori, 0, sizeof(ori));
            memset(obj, 0, sizeof(obj));
            obj[1] = first; ori[1] = 1;
            for (int i = 2; i <= n; i++) {scanf("%d", &obj[i]); ori[i] = i;}
            stack <int> station;
            int p = 1;
            bool is_success = true;
            for (int i = 1; i <= n; i++) {
                if (!station.empty() && obj[i] == station.top()) {station.pop(); continue;}
                if (p <= n && obj[i] == ori[p]) {p++; continue;}
                while (ori[p] != obj[i]) {
                    station.push(ori[p]);
                    p++;
                    if (p > n) {is_success = false; goto end;}
                }
                p++;
            }
            end:
            if (is_success) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
