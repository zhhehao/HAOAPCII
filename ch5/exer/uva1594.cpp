# include <cstdio>
# include <vector>
# include <set>
# include <cmath>
using namespace std;

vector <int> vt;
set <vector<int> > vis;
int n;

void input(void) {
	vt.resize(0);
	vis.clear();
	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		vt.push_back(a);
	}
}

bool zero_chk() {
	for (int i = 0; i < vt.size(); i++)
		if (vt[i] != 0)
			return false;
	return true;
}

void output(void) {
	for (;;) {
		if (zero_chk()) {printf("ZERO\n"); break;}
		int t1 = vt[0];
		for (int i = 0; i < vt.size() - 1; i++)
			vt[i] = abs(vt[i]-vt[i+1]);
		vt[vt.size()-1] = abs(vt[vt.size()-1]-t1);
		if (vis.count(vt)) {printf("LOOP\n"); break;}
		else
			vis.insert(vt);
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		input();
		output();
	}
	return 0;
}