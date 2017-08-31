# include <iostream>
# include <string>
# include <sstream>
# include <queue>
# include <deque>
# include <cstdio>
# include <cstring>
using namespace std;

const int maxn = 100000 + 10;
int config[7], var[26], T, kase;
string buff;
bool is_lock;

struct Statement {
    int type, v;
};

queue <Statement> sq[maxn];
deque <int> rq; queue <int> bq;

int main(void) {

// # ifdef LOCAL
//     freopen("d.in", "r", stdin);
//     freopen("d.out", "w", stdout);
// # endif

    cin >> T; getline(cin, buff); // remove "\n"
    kase = 0;
    while (T--) {

        while (!rq.empty()) rq.pop_front();
        while (!bq.empty()) bq.pop();
        if (kase++) cout << "\n";
        memset(var, 0, sizeof(var));
        for (int i = 0; i < 7; i++) cin >> config[i];
        getline(cin, buff); // remove "\n"
        for (int i = 0; i < config[0]; i++) {
            while (1) {
                getline(cin, buff);
                Statement st;
                if (buff[2] == '=') {
                    stringstream ss(buff);
                    char nouse;
                    ss >> nouse >> nouse >> st.v;
                    st.type = buff[0] - 'a';
                }
                else if (buff[0] == 'p') {
                    st.type = -1;
                    st.v = buff[6] - 'a';
                }
                else if (buff[0] == 'l') {
                    st.type = -2;
                }
                else if (buff[0] == 'u') {
                    st.type = -3;
                }
                else if (buff[0] == 'e') {
                    st.type = -4;
                }
                sq[i].push(st);
                if (st.type == -4) break;
            }
            rq.push_back(i);
        }
        is_lock = false;
        while (!rq.empty()) {
            int job = rq.front(); rq.pop_front();
            int quantum = config[6];
            while (quantum > 0) {
                Statement &cmd = sq[job].front();
                if (cmd.type >= 0) {
                    // if (quantum < config[1]) break;
                    quantum -= config[1];
                    var[cmd.type] = cmd.v;
                }
                else if (cmd.type == -1) {
                    // if (quantum < config[2]) break;
                    quantum -= config[2];
                    cout << job+1 << ": " << var[cmd.v] << "\n";
                }
                else if (cmd.type == -2) {
                    // if (quantum < config[3]) break;
                    quantum -= config[3];
                    if (is_lock) {
                        bq.push(job);
                        goto end;
                    }
                    else {
                        is_lock = true;
                    }
                }
                else if (cmd.type == -3) {
                    // if (quantum < config[4]) break;
                    quantum -= config[4];
                    is_lock = false;
                    if (!bq.empty()) {
                        rq.push_front(bq.front()); bq.pop();
                    }
                }
                else if (cmd.type == -4) {
                    // if (quantum < config[5]) break;
                    sq[job].pop();
                    goto end;
                }
                sq[job].pop();
            }
            rq.push_back(job);
end:
            continue;
        }
    }
    return 0;
}
