# include <cstdio>
# include <cstring>

const int maxn = 5000 + 10;
char s[2][maxn];
int n, cur;
int pixel[32][32][2];

void pr(int ans) {
    printf("There are %d black pixels.\n", ans);
}

void fill_pixel(int x, int y, int len, int p) {
    int xlen = x + len, ylen = y + len;
    for (int i = x; i < xlen; i++)
        for (int j = y; j < ylen; j++)
            pixel[i][j][p] = 1;
}

void solve(int x, int y, int len, int p) {
    int xp[4], yp[4];
    xp[0] = x + len/2; yp[0] = y;
    xp[1] = x; yp[1] = y;
    xp[2] = x; yp[2] = y + len/2;
    xp[3] = x + len/2; yp[3] = y + len/2;
    for (int i = 0; i < 4; i++) {
        char buf = s[p][cur++];
        if (buf == 'p') {
            solve(xp[i], yp[i], len/2, p);
        }
        if (buf == 'f') {
            fill_pixel(xp[i], yp[i], len/2, p);
        }
    }
}

int main(void) {

    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", s[0], s[1]);
        if (s[0][0] == 'f' || s[1][0] == 'f') {pr(1024); continue;}
        if (s[0][0] == 'e' && s[1][0] == 'e') {pr(0); continue;}
        memset(pixel, 0, sizeof(pixel));
        if (s[0][0] == 'p') {cur = 1; solve(0, 0, 32, 0);}
        if (s[1][0] == 'p') {cur = 1; solve(0, 0, 32, 1);}
        int ans = 0;
        for (int i = 0; i < 32; i++)
            for (int j = 0; j < 32; j++)
                if (pixel[i][j][0] == 1 || pixel[i][j][1] == 1)
                    ans++;
        pr(ans);
    }

    return 0;
}
