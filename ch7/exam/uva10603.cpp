# include <cstdio>
# include <cstring>
# include <queue>
using namespace std;

const int maxn = 200 + 5;

int vis[maxn][maxn], va, vb, vc, d, ansd, ansdis;

struct Node {
    int v[3], dis;
    bool operator < (const Node& a) const {
        return a.dis < dis;
    }
};

void solve() {
    priority_queue <Node> q;
    Node first_node;
    first_node.dis = 0;
    first_node.v[0] = 0;
    first_node.v[1] = 0;
    first_node.v[2] = vc;
    vis[0][0] = 1;
    q.push(first_node);

    while (!q.empty()) {
        Node node; node = q.top(); q.pop();
        if (node.v[0] == d || node.v[1] == d || node.v[2] == d) {
            ansd = d;
            ansdis = node.dis;
            break;
        }
        if (node.v[0] < d && node.v[0] > ansd) {ansd = node.v[0]; ansdis = node.dis;}
        if (node.v[1] < d && node.v[1] > ansd) {ansd = node.v[1]; ansdis = node.dis;}
        if (node.v[2] < d && node.v[2] > ansd) {ansd = node.v[2]; ansdis = node.dis;}
        int s0 = va - node.v[0], s1 = vb - node.v[1], s2 = vc - node.v[2];
        if (s0 > 0) {
            Node n_node;
            if (node.v[1] >= s0) {
                n_node.v[0] = va; n_node.v[1] = node.v[1]-s0; n_node.v[2] = node.v[2]; n_node.dis = node.dis + s0;
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[1] < s0) {
                n_node.v[0] = node.v[0] + node.v[1]; n_node.v[1] = 0; n_node.v[2] = node.v[2]; n_node.dis = node.dis + node.v[1];
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[2] >= s0) {
                n_node.v[0] = va; n_node.v[2] = node.v[2]-s0; n_node.v[1] = node.v[1]; n_node.dis = node.dis + s0;
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[2] < s0) {
                n_node.v[0] = node.v[0] + node.v[2]; n_node.v[2] = 0; n_node.v[1] = node.v[1]; n_node.dis = node.dis + node.v[2];
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
        }
        if (s1 > 0) {
            Node n_node;
            if (node.v[0] >= s1) {
                n_node.v[1] = vb; n_node.v[0] = node.v[0]-s1; n_node.v[2] = node.v[2]; n_node.dis = node.dis + s1;
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[0] < s1) {
                n_node.v[1] = node.v[1] + node.v[0]; n_node.v[0] = 0; n_node.v[2] = node.v[2]; n_node.dis = node.dis + node.v[0];
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[2] >= s1) {
                n_node.v[1] = vb; n_node.v[2] = node.v[2]-s1; n_node.v[0] = node.v[0]; n_node.dis = node.dis + s1;
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[2] < s1) {
                n_node.v[1] = node.v[1] + node.v[2]; n_node.v[2] = 0; n_node.v[0] = node.v[0]; n_node.dis = node.dis + node.v[2];
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
        }
        if (s2 > 0) {
            Node n_node;
            if (node.v[0] >= s2) {
                n_node.v[2] = vc; n_node.v[0] = node.v[0]-s2; n_node.v[1] = node.v[1]; n_node.dis = node.dis + s2;
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[0] < s2) {
                n_node.v[2] = node.v[2] + node.v[0]; n_node.v[0] = 0; n_node.v[1] = node.v[1]; n_node.dis = node.dis + node.v[0];
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[1] >= s2) {
                n_node.v[2] = vc; n_node.v[1] = node.v[1]-s2; n_node.v[0] = node.v[0]; n_node.dis = node.dis + s2;
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
            if (node.v[1] < s2) {
                n_node.v[2] = node.v[2] + node.v[1]; n_node.v[1] = 0; n_node.v[0] = node.v[0]; n_node.dis = node.dis + node.v[1];
                if (vis[n_node.v[0]][n_node.v[1]] == 0) {vis[n_node.v[0]][n_node.v[1]] = 1; q.push(n_node);}
            }
        }
    }
}

int main(void) {

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &va, &vb, &vc, &d);
        memset(vis, 0, sizeof(vis));
        ansd = 0; ansdis = 0;
        solve();
        printf("%d %d\n", ansdis, ansd);
    }
    return 0;
}
