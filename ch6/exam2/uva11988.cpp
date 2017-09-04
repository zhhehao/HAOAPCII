# include <cstdio>
# include <cstring>

const int maxn = 100000 + 10;

struct Chain {
    char c;
    int p;
};

Chain ch[maxn];

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    char buff;
    while (scanf("%c", &buff) != EOF) {
        memset(ch, 0, sizeof(ch));
        int cur = 0, last = 0, cnt = 1; ch[0].p = 0;
        if (buff != '[' && buff != ']') {
            ch[0].p = 1; ch[1].c = buff; ch[1].p = 0;
            cnt = 2; cur = 1; last = 1;
        }
        while(scanf("%c", &buff) && buff != '\n') {
            if (buff == '[') {
                cur = 0;
            }
            else if (buff == ']') {
                cur = last;
            }
            else {
                ch[cnt].c = buff;
                ch[cnt].p = ch[cur].p;
                ch[cur].p = cnt;
                cur = cnt;
                if (ch[cur].p == 0) last = cur;
                cnt++;
            }
        }
        int p = ch[0].p;
        while (1) {
            printf("%c", ch[p].c);
            if (ch[p].p == 0) break;
            p = ch[p].p;
        }
        printf("\n");
    }

    return 0;
}
