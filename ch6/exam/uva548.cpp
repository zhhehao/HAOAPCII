# include <iostream>
# include <cstring>
# include <string>
# include <sstream>
using namespace std;

const int maxn = 100000 + 10;

int inorder[maxn], postorder[maxn], cnt, min_sum, min_node;

void solve(int v_sum, int L1, int R1, int L2, int R2) {
	// cout << "L is " << L << ", R is " << R << "\n";
	if (L1 == R1) {
		int sum = v_sum + inorder[L1];
		if (sum < min_sum) {
			min_sum = sum;
			min_node = inorder[L1];
		}
	}
	else if (L1 < R1) {
		int root_pos = L1; while (inorder[root_pos] != postorder[R2]) root_pos++;
		int sum = v_sum + inorder[root_pos];
		int len1 = root_pos - L1;
		solve(sum, L1, root_pos-1, L2, L2+len1-1);
		int len2 = R1 - root_pos;
		solve(sum, root_pos+1, R1, R2-len2 , R2-1);
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	string str;
	while (getline(cin, str)) {
		// memset(inorder, 0, sizeof(inorder));
		// memset(postorder, 0, sizeof(postorder));
		int node; cnt = 0; stringstream ss(str);
		while (ss >> node) inorder[cnt++] = node;
		cnt = 0; getline(cin, str); stringstream ss2(str);
		while (ss2 >> node) postorder[cnt++] = node;

		min_sum = 100000000;
		min_node = postorder[cnt-1];
		solve(0, 0, cnt-1, 0, cnt-1);
		cout << min_node << "\n";
	}
	return 0;
}