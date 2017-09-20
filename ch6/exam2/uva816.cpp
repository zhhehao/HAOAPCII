# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

int v[10][10][4][3];

struct Point {
    int x, y;
};

Point ans[1000], next[4][3], p_s, p_e;

struct Inter {
    Point p;
    vector <int> vi[4];
};

Inter maze[10][10];

int solve(Point p, int dir, int step) {
    // dfs solution
}

int main(void) {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    next[0][0].x = 0; next[0][0].y = -1;
    next[0][1].x = -1; next[0][1].y = 0;
    next[0][2].x = 0; next[0][2].y = 1;

    next[1][0].x = 1; next[1][0].y = 0;
    next[1][1].x = 0; next[1][1].y = -1;
    next[1][2].x = -1; next[1][2].y = 0;

    next[2][0].x = 0; next[2][0].y = 1;
    next[2][1].x = 1; next[2][1].y = 0;
    next[2][2].x = 0; next[2][2].y = -1;

    next[3][0].x = -1; next[3][0].y = 0;
    next[3][1].x = 0; next[3][1].y = 1;
    next[3][2].x = 1; next[3][2].y = 0;

    char buff[30];
    while (scanf("%s", buff)) {
        if (strcmp(buff, "END") == 0) break;
        printf("%s\n", buff);
        scanf("%d%d%s%d%d", &p_s.x, &p_s.y, buff, &p_e.x, &p_e.y);
        int dir;
        switch(buff[0]) {
            case 'N': dir = 0; break;
            case 'W': dir = 1; break;
            case 'S': dir = 2; break;
            case 'E': dir = 3; break;
        }

        // get input

        ans[0].x = p_s.x; ans[0].y = p_s.y;
        if (solve(p_s, dir, 1) < 0)
            printf("  No Solution Possible\n");
        else {
            // put output
        }
    }

    return 0;
}
