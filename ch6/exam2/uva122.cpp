# include <cstdio>
# include <cstring>
# include <queue>
using namespace std;

const int maxn = 256 + 5;
int N[maxn], L[maxn], R[maxn];
char buff[1000], path[500];
int ans[500];

void not_complete() {
    for (;;) {
        scanf("%s", buff);
        if (strlen(buff) == 2) return;
    }
}

int bfs() {
    int cnt = 0;
    queue <int> q; q.push(0);
    while (!q.empty()) {
        int n = q.front(); q.pop();
        if (N[n] == 0) return 0;
        if (L[n] != 0) q.push(L[n]);
        if (R[n] != 0) q.push(R[n]);
        ans[cnt++] = N[n];
    }
    return cnt;
}

int main(void) {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    while (scanf("%s", buff) != EOF) {
        memset(N, 0, sizeof(N));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        int cnt = 1;
        bool nc = false;

        for (;;) {
            // printf("%s\n", buff);
            int node;
            char * pch = strchr(buff, ',');
            if (pch == NULL) break;
            buff[pch - buff] = ' ';
            sscanf(buff+1, "%d %s", &node, path);
            if (path[0] == ')') {
                if (N[0] != 0) {nc = true; goto end;}
                N[0] = node;
            }
            else {
                int len = strlen(path) - 1, cur = 0;
                for (int i = 0; i < len; i++) {
                    if (path[i] == 'L') {
                        if (L[cur] == 0) {L[cur] = cnt; cur = cnt; cnt++;}
                        else {cur = L[cur];}
                    }
                    else {
                        if (R[cur] == 0) {R[cur] = cnt; cur = cnt; cnt++;}
                        else {cur = R[cur];}
                    }
                }
                if (N[cur] != 0) {nc = true; goto end;}
                N[cur] = node;
            }
            scanf("%s", buff);
        }

        end:
            if (nc) {
                not_complete();
                printf("not complete\n");
                continue;
            }

            int ll = bfs();
            if (ll == 0) {printf("not complete\n"); continue;}
            else {
                ll--;
                for (int i = 0; i < ll; i++) printf("%d ", ans[i]);
                printf("%d\n", ans[ll]);
            }
    }
    return 0;
}
