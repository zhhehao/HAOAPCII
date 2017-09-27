# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

const int maxn = 1000 + 10;
int T, N, g[26][26], in[26], out[26], ck;

bool check_degree(vector <int> v) {
    if (in[v[0]] - out[v[0]] == 1) {
        if (in[v[1]] - out[v[1]] == -1)
            return true;
        return false;
    }
    else if (in[v[0]] - out[v[0]] == -1) {
        if (in[v[1]] - out[v[1]] == 1)
            return true;
        return false;
    }
    return false;
}

void ck_chk(int x, int y) {
    g[x][y]--;
    for (int i = 0; i < 26; i++) {
        if (g[i][x] != 0) {
            ck_chk(i, x);
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (g[y][i] != 0) {
            ck_chk(y, i);
            break;
        }
    }
    ck++;
}

bool check_connected() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (g[i][j] != 0) {
                ck_chk(i, j);
                goto end;
            }
        }
    }
    end:
    if (ck == N)
        return true;
    else
        return false;
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        char buff[maxn];
        bool is_opened = true;
        memset(g, 0, sizeof(g));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for (int i = 0; i < N; i++) {
            scanf("%s", buff);
            int x = buff[0] - 'a', y = buff[strlen(buff)-1] - 'a';
            g[x][y]++; in[y]++; out[x]++;
        }

        // check in and out
        int cnt = 0;
        vector <int> v;
        for (int i = 0; i < 26; i++) {
            if (in[i] == out[i]) continue;
            cnt++;
            v.push_back(i);
        }
        // printf("cnt is %d\n", cnt);
        ck = 0;
        if (cnt == 0 || (cnt == 2 && check_degree(v))) {
            if (!check_connected())
                is_opened = false;
        }
        else {
            is_opened = false;
        }

        if (is_opened) {
            printf("Ordering is possible.\n");
        }
        else {
            printf("The door cannot be opened.\n");
        }
    }
    return 0;
}
