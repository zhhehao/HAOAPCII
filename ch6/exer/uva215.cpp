/*
** 本题通过递归来计算单元格，同时通过访问标记来区别循环引用
*/

# include <cstdio>
# include <cstring>
# include <cctype>
# include <queue>
using namespace std;

struct Str {
   char s[80];
};

int r, c, s2[22][12], vis[22][12];
Str s1[22][12];

// 此函数用来转换字符串为有符号的数字，1代表负数，0代表正数
int get_num(char *sc, int len, int t) {
    int rec, cnt;
    if (t == 1) { // 计算负数
        rec = 0; cnt = 1;
        while (cnt < len) {
            rec = rec * 10 + *(sc+cnt) - '0';
            cnt++;
        }
        return rec * -1;
    }
    else { // 计算正数
        rec = 0; cnt = 0;
        while (cnt < len) {
            rec = rec * 10 + *(sc+cnt) - '0';
            cnt++;
        }
        return rec;
    }
}

// 计算单元格表达式的值，如果有循环引用则返回888888，否则正常返回结果
int get_value(char *sc, int len, int x, int y) {
    if (vis[x][y] == 1) return 888888;
    vis[x][y] = 1;
    queue <int> q; while(!q.empty()) q.pop();
    int cnt = 0;
    while (cnt < len) {
        if (isdigit(*(sc+cnt))) {
            int scnt = cnt;
            cnt++;
            while (isdigit(*(sc+cnt))) cnt++;
            q.push(get_num(sc+scnt, cnt-scnt, 0));
        }
        else if (*(sc+cnt) == '+') {q.push(666666); cnt++;} // 代替加号
        else if (*(sc+cnt) == '-') {q.push(333333); cnt++;} // 代替减号
        else {
            int sx = *(sc+cnt) - 'A', sy = *(sc+cnt+1) - '0';
            if (s2[sx][sy] != 999999) q.push(s2[sx][sy]);
            else {
                int value = get_value(s1[sx][sy].s, strlen(s1[sx][sy].s), sx, sy);
                if (value == 888888) return 888888;
                else q.push(value);
            }
            cnt += 2;
        }
    }
    int rec = q.front(); q.pop();
    while (!q.empty()) {
        int op = q.front(); q.pop();
        int v2 = q.front(); q.pop();
        if (op == 666666) rec += v2;
        else if (op == 333333) rec -= v2;
    }
    vis[x][y] = 0;
    return rec;
}

int solve(void) {
    bool circle = false;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (s2[i][j] == 999999) {
                int value = get_value(s1[i][j].s, strlen(s1[i][j].s), i, j);
                if (value == 888888)
                    circle = true;
                else
                    s2[i][j] = value;
            }

    if (circle) return 1;
    else return 0;
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif
    while (scanf("%d%d", &r, &c) && r) {
        memset(s2, 0, sizeof(s2));
        memset(vis, 0, sizeof(vis));
        // 初始化s1，即初始值数组
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) scanf("%s", s1[i][j].s);

        // 初始化s2，即结果数组
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (s1[i][j].s[0] == '-')
                    s2[i][j] = get_num(s1[i][j].s, strlen(s1[i][j].s), 1);
                else if (isdigit(s1[i][j].s[0]))
                    s2[i][j] = get_num(s1[i][j].s, strlen(s1[i][j].s), 0);
                else
                    s2[i][j] = 999999; // 表示此单元格的值是一个表达式
            }
        if (solve() == 1) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    if (!isdigit(s1[i][j].s[0]) && s1[i][j].s[0] != '-' && s2[i][j] == 999999)
                        printf("%c%d: %s\n", i+'A', j, s1[i][j].s);
        }
        else {
            printf(" ");
            for (int j = 0; j < c; j++) printf("     %d", j);
            printf("\n");
            for (int i = 0; i < r; i++) {
                printf("%c", i+'A');
                for (int j = 0; j < c; j++) printf("%6d", s2[i][j]);
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
