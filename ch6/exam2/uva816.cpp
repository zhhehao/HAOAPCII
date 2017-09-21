# include <iostream>
# include <cstring>
# include <vector>
# include <string>
# include <map>
# include <queue>
using namespace std;

struct Place {
    int x, y, dir, f;
};

struct Maze {
    int m[4][3][2];
};

Maze maze[10][10];
string m_name;
int sx, sy, ex, ey, sdir;
map <char, int> mdir;
map <char, int> mturn;
vector <Place> path;
int vis[10][10][4];

void set_maze(const int &td, const int &tt, int &rx, int &ry, const int &x, const int &y) {
    if (td == 0) {
        switch(tt) {
            case 0: rx = x; ry = y - 1; break;
            case 1: rx = x; ry = y + 1; break;
            case 2: rx = x - 1; ry = y; break;
        }
        return;
    }
    if (td == 1) {
        switch(tt) {
            case 0: rx = x - 1; ry = y; break;
            case 1: rx = x + 1; ry = y; break;
            case 2: rx = x; ry = y + 1; break;
        }
        return;
    }
    if (td == 2) {
        switch(tt) {
            case 0: rx = x; ry = y + 1; break;
            case 1: rx = x; ry = y - 1; break;
            case 2: rx = x + 1; ry = y; break;
        }
        return;
    }
    if (td == 3) {
        switch(tt) {
            case 0: rx = x + 1; ry = y; break;
            case 1: rx = x - 1; ry = y; break;
            case 2: rx = x; ry = y - 1; break;
        }
        return;
    }
}

void input(void) {
    string str;
    cin >> sx >> sy >> str >> ex >> ey;
    sdir = mdir[str[0]];
    memset(maze, 0, sizeof(maze));
    int x, y;
    while (cin >> x && x != 0) {
        cin >> y;
        while (cin >> str && str[0] != '*') {
            int td = mdir[str[0]];
            for (int i = 1; i < str.length(); i++) {
                int tt = mturn[str[i]];
                set_maze(td, tt, maze[x][y].m[td][tt][0], maze[x][y].m[td][tt][1], x, y);
                // cout << maze[x][y].m[td][tt][0] << " + " << maze[x][y].m[td][tt][1] << "\n";
            }
        }
    }
}

bool solve(void) {
    memset(vis, 0, sizeof(vis));
    queue <Place> q; path.resize(0);
    Place start; start.x = sx; start.y = sy; start.f = -1; path.push_back(start);
    Place bp;
    switch (sdir) {
        case 0: sx--; break;
        case 1: sy++; break;
        case 2: sx++; break;
        case 3: sy--; break;
    }
    bp.x = sx; bp.y = sy; bp.dir = sdir; bp.f = path.size()-1;
    q.push(bp);
    vis[bp.x][bp.y][bp.dir] = 1;
    while (!q.empty()) {
        Place pp = q.front(); q.pop();
        path.push_back(pp);
        int fpos = path.size()-1;
        if (pp.x == ex && pp.y == ey) return true;
        for (int j = 0; j < 3; j++) {
            if (maze[pp.x][pp.y].m[pp.dir][j][0] != 0) {
                Place qp;
                qp.x = maze[pp.x][pp.y].m[pp.dir][j][0];
                qp.y = maze[pp.x][pp.y].m[pp.dir][j][1];
                qp.f = fpos;
                if (j == 0)
                    qp.dir = (pp.dir+3)%4;
                else if (j == 1)
                    qp.dir = (pp.dir+1)%4;
                else
                    qp.dir = pp.dir;
                if (vis[qp.x][qp.y][qp.dir] == 0) {
                    q.push(qp);
                    vis[qp.x][qp.y][qp.dir] = 1;
                }
            }
        }
    }
    return false;
}

void output(void) {
    cout << m_name +"\n";
    if (solve()) {
        vector <Place> ans; ans.resize(0);
        int pos = path.size()-1;
        do {
            ans.push_back(path[pos]);
            pos = path[pos].f;
        } while (pos != -1);
        int cur = ans.size()-1, cnt = 0;
        bool first = true;
        while (cur >= 0) {
            cnt++;
            if (first) {cout << "  " << "(" << ans[cur].x << "," << ans[cur].y << ")"; first = false; cur--; continue;}
            cout << " " << "(" << ans[cur].x << "," << ans[cur].y << ")"; cur--;
            if (cnt % 10 == 0) {cout << "\n"; first = true;}
        }
        if (cnt % 10 != 0) cout << "\n";
    }
    else
        cout << "  No Solution Possible\n";
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    mdir.clear(); mturn.clear();
    mdir['N'] = 0; mdir['E'] = 1; mdir['S'] = 2; mdir['W'] = 3;
    mturn['L'] = 0; mturn['R'] = 1; mturn['F'] = 2;
    while (cin >> m_name && m_name != "END") {
        input();
        output();
    }
    return 0;
}
