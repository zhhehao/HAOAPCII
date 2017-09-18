# include <cstdio>
# include <cstring>
# include <cctype>
# include <vector>
# include <algorithm>
using namespace std;

const int maxn = 200 + 10;
int image[maxn][maxn], H, W, cnt;

const int hex[16][4] = {
    {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
    {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
    {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
    {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
};

const char hiero[6] = {'W', 'A', 'K', 'J', 'S', 'D'};

const int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void print_image() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%d", image[i][j]);
        }
        printf("\n");
    }
}

void setbg(int x, int y) { // setbg from 0 to 2
    image[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i][0], ny = y + dx[i][1];
        if (nx < 0 || nx > H-1 || ny < 0 || ny > W-1 || image[nx][ny] != 0) continue;
        setbg(nx, ny);
    }
}

void solve(int x, int y) {
    image[x][y] = 3;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i][0], ny = y + dx[i][1];
        if (nx < 0 || nx > H-1 || ny < 0 || ny > W-1 || image[nx][ny] > 1) continue;
        if (image[nx][ny] == 0) {cnt++; setbg(nx, ny);}
        solve(nx, ny);
    }
}

int main(void) {

    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    int kase = 1;
    while (scanf("%d%d", &H, &W) == 2 && H) {
        // input and transfer hex to dec.
        char buff[maxn];
        for (int i = 0; i < H; i++) {
            scanf("%s", buff);
            for (int j = 0; j < W; j++) {
                int cur = isdigit(buff[j]) ? buff[j] - '0': buff[j] - 'a' + 10;
                int begin = j * 4;
                for (int k = begin, l = 0; l < 4; k++, l++) {
                    image[i][k] = hex[cur][l];
                }
            }
        }

        W *= 4; // resize W
        // set bg color from 0 to 2
        // print_image();
        for (int i = 0; i < W; i++) {
            if (image[0][i] == 0) setbg(0, i);
            if (image[H-1][i] == 0) setbg(H-1, i);
        }
        for (int i = 0; i < H; i++) {
            if (image[i][0] == 0) setbg(i, 0);
            if (image[i][W-1] == 0) setbg(i, W-1);
        }
        // print_image();
        vector <char> ans;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (image[i][j] == 1) {
                    cnt = 0;
                    solve(i, j);
                    ans.push_back(hiero[cnt]);
                }
            }
        }

        sort(ans.begin(), ans.end());
        printf("Case %d: ", kase++);
        for (int i = 0; i < ans.size(); i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
