# include <cstdio>
# include <cstring>
# include <stack>
using namespace std;

const int maxn = 100000 + 10;

int value[26][2], n;
char str[maxn];

struct Matrix {
    int a, b;
};

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    scanf("%d", &n);
    memset(value, 0, sizeof(value));
    char c[5]; int a, b;
    while (n--) {
        scanf("%s %d %d", c, &a, &b);
        value[c[0]-'A'][0] = a;
        value[c[0]-'A'][1] = b;
    }

    while (scanf("%s", str) == 1) {
        if (str[0] != '(') {printf("0\n"); continue;}
        int len = strlen(str);
        stack <Matrix> s;
        bool is_error = false;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == '(') continue;
            if (str[i] != ')') {
                Matrix m;
                m.a = value[str[i]-'A'][0];
                m.b = value[str[i]-'A'][1];
                s.push(m);
                continue;
            }
            if (s.size() < 2) {is_error = true; break;}
            Matrix m1, m2;
            m2.a = s.top().a; m2.b = s.top().b; s.pop();
            m1.a = s.top().a; m1.b = s.top().b; s.pop();
            if (m1.b != m2.a) {is_error = true; break;}
            Matrix m3;
            m3.a = m1.a; m3.b = m2.b;
            sum += m1.a * m1.b * m2.b;
            s.push(m3);
        }
        if (is_error) {printf("error\n"); continue;}
        printf("%d\n", sum);
    }
    return 0;
}
