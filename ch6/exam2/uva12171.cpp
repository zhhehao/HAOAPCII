# include <cstdio>
# include <cstring>
# include <set>
# include <vector>
# include <algorithm>
using namespace std;

const int maxn = 100 + 10;

int t, n, ans_area, ans_volume, space[maxn][maxn][maxn], boxes[maxn][6];
int dx[6][3] = {{0, 1, 0}, {0, -1, 0},
                {-1, 0, 0}, {1, 0, 0},
                {0, 0, 1}, {0, 0, -1}};

vector <int> xx, yy, zz;

void _init() {
    scanf("%d", &n);
    xx.resize(0); yy.resize(0); zz.resize(0);
    xx.push_back(0); yy.push_back(0); zz.push_back(0);
    set <int> set_x, set_y, set_z;
    memset(boxes, 0, sizeof(boxes));
    int num[6];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &num[j]);
            if (j >= 3) {
                num[j] += num[j-3];
            }
            if ((j == 0 || j == 3) && set_x.count(num[j]) == 0) {
                set_x.insert(num[j]);
                xx.push_back(num[j]);
                // printf("insert x = %d\n", num[j]);
            }
            else if ((j == 1 || j == 4) && set_y.count(num[j]) == 0) {
                set_y.insert(num[j]);
                yy.push_back(num[j]);
            }
            else if ((j == 2 || j == 5) && set_z.count(num[j]) == 0) {
                set_z.insert(num[j]);
                zz.push_back(num[j]);
            }
            boxes[i][j] = num[j];
            // printf("%d\n", boxes[n][j]);
        }
        // printf("\n");
    }
    sort(xx.begin(), xx.end()); xx.push_back(xx[xx.size()-1]+1);
    sort(yy.begin(), yy.end()); yy.push_back(yy[yy.size()-1]+1);
    sort(zz.begin(), zz.end()); zz.push_back(zz[zz.size()-1]+1);

    // for (int i = 0; i < xx.size(); i++) printf("%d\n", xx[i]);
    // printf("\n");

    memset(space, 0, sizeof(space));
    for (int i = 0; i < n; i++) {
        int x_s, x_e, y_s, y_e, z_s, z_e;
        x_s = lower_bound(xx.begin(), xx.end(), boxes[i][0]) - xx.begin();
        // printf("%d %d\n", boxes[i][0], x_s);
        x_e = lower_bound(xx.begin(), xx.end(), boxes[i][3]) - xx.begin();
        y_s = lower_bound(yy.begin(), yy.end(), boxes[i][1]) - yy.begin();
        y_e = lower_bound(yy.begin(), yy.end(), boxes[i][4]) - yy.begin();
        z_s = lower_bound(zz.begin(), zz.end(), boxes[i][2]) - zz.begin();
        z_e = lower_bound(zz.begin(), zz.end(), boxes[i][5]) - zz.begin();
        // printf("%d %d %d %d %d %d\n", x_s, x_e, y_s, y_e, z_s, z_e);
        for (int j1 = x_s; j1 < x_e; j1++) {
            for (int j2 = y_s; j2 < y_e; j2++) {
                for (int j3 = z_s; j3 < z_e; j3++) {
                    space[j1][j2][j3] = 1;
                    // printf("%d %d %d\n", j1, j2, j3);
                }
            }
        }
    }
    // printf("\n");
}

void flood_fill(int x, int y, int z) {
    // printf("firse volume is %d\n", ans_volume);
    ans_volume += (xx[x+1]-xx[x]) * (yy[y+1]-yy[y]) * (zz[z+1]-zz[z]);
    // printf("second volume is %d\n\n", ans_volume);
    space[x][y][z] = 2;
    int nx, ny, nz;
    for (int i = 0; i < 6; i++) {
        nx = x + dx[i][0];
        ny = y + dx[i][1];
        nz = z + dx[i][2];
        if (nx < 1 || ny < 1 || nz < 1 || nx >= xx.size()-1 || ny >= yy.size()-1 || nz >= zz.size()-1 || space[nx][ny][nz] != 1) continue;
        if (i <= 1) ans_area += (xx[nx+1]-xx[nx]) * (zz[nz+1]-zz[nz]);
        else if (i >= 4) ans_area += (xx[nx+1]-xx[nx]) * (yy[ny+1]-yy[ny]);
        else ans_area += (yy[ny+1]-yy[ny]) * (zz[nz+1]-zz[nz]);
    }

    for (int i = 0; i < 6; i++) {
        nx = x + dx[i][0];
        ny = y + dx[i][1];
        nz = z + dx[i][2];
        if (nx < 0 || ny < 0 || nz < 0 || nx >= xx.size()-1 || ny >= yy.size()-1 || nz >= zz.size()-1 || space[nx][ny][nz] != 0) continue;
        flood_fill(nx, ny, nz);
    }
}

void _solve() {
    ans_area = 0;
    ans_volume = 0;
    flood_fill(0, 0, 0);
    ans_volume = xx[xx.size()-1] * yy[yy.size()-1] * zz[zz.size()-1] - ans_volume;
}

void _output() {
    printf("%d %d\n", ans_area, ans_volume);
}

int main(void) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        _init();
        _solve();
        _output();
    }
    return 0;
}
