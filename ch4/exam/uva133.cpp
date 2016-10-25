# include <cstdio>
# include <cstring>
using namespace std;

# define maxn 22
int que[maxn], n, k, m;
int off1, off2, left;

void go() {
	int count = k;
	while(count) {
		off1++;
		if (off1 > n)
			off1 = 1;
		if (que[off1] == 0) {
			count--;
		}
	}
	count = m;
	while(count) {
		off2--;
		if (off2 <= 0)
			off2 = n;
		if (que[off2] == 0) {
			count--;
		}
	}
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while(scanf("%d%d%d", &n, &k, &m) && n) {
		left = n;
		off1 = off2 = 0;
		memset(que, 0, sizeof(que));
		for(;;) {
			go();
			if (off1 != off2) {
				printf("%3d%3d", off1, off2);
				que[off1] = 1;
				que[off2] = 1;
				left -= 2;
			}
			else {
				printf("%3d", off1);
				que[off1] = 1;
				left--;
			}
			if (left)
				printf(",");
			else {
				printf("\n");
				break;
			}
		}
	}
	return 0;
}