/*
** base trans, need ip address knowledge
*/

# include <cstdio>
# include <cstring>
# include <set>
using namespace std;

# define MAXN 1005
int ip[MAXN][32], net[32], mask[32];
char buf[20];

void to_Binary(int num, int* a) {
	 int cnt = 7;
	 while(num != 0) {
	 	if (num % 2 == 1)
	 		a[cnt] = 1;
	 	num /= 2;
	 	cnt--;
	 }
}

int to_Dec(int* a) {
	int num = 0, cnt = 0;
	for (int i = 7; i >= 0; i--) {
		num += (a[cnt++] << i);
	}
	return num;
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int m;
	while(scanf("%d", &m) != EOF) {
		memset(ip, 0, sizeof(ip));
		int b1, b2, b3, b4;
		for (int i = 0; i < m; i++) {
			memset(buf, '\0', sizeof(buf));
			scanf("%s", buf);
			for (int j = 0; j < strlen(buf); j++)
				if (buf[j] == '.')
					buf[j] = 32;
			sscanf(buf, "%d%d%d%d", &b1, &b2, &b3, &b4);
			to_Binary(b1, ip[i]);
			to_Binary(b2, ip[i]+8);
			to_Binary(b3, ip[i]+16);
			to_Binary(b4, ip[i]+24);
		}

		memset(net, 0, sizeof(net));
		memset(mask, 0, sizeof(mask));
		set<int> checkDuplicate;
		int cur;
		for (int j = 0; j < 32; j++) {
			checkDuplicate.clear();
			for (int i = 0; i < m; i++) {
				checkDuplicate.insert(ip[i][j]);
			}
			if (checkDuplicate.size() == 1) {
				net[j] = ip[0][j];
				mask[j] = 1;
			}
			else {
				cur = j;
				break;
			}
		}
		printf("%d.%d.%d.%d\n", to_Dec(net), to_Dec(net+8), to_Dec(net+16), to_Dec(net+24));
		printf("%d.%d.%d.%d\n", to_Dec(mask), to_Dec(mask+8), to_Dec(mask+16), to_Dec(mask+24));
	}
	return 0;
}
