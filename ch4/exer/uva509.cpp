/*
** simulate raid system
*/

# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

# define MAXN 6450

char diskset[6][MAXN];
int d_cnt, s_cnt, b_cnt;
char parity[3];
vector <int> verr;

int check_data(void) {
	int parity_result = (parity[0] == 'O' ? 1 : 0);
	// printf("parity_result is %d\n", parity_result);
	int len = s_cnt * b_cnt, parity_cur = -1;
	for (int j = 0; j < len; j++) {
		if (j % s_cnt == 0) {
			parity_cur = (parity_cur+1) % d_cnt;
		}
		// printf("parity_cur is %d\n", parity_cur);
		int err = 0, sum = 0;
		verr.resize(0);
		for (int i = 0; i < d_cnt; i++)
			if (diskset[i][j] == 'x') {
				err++;
				verr.push_back(i);
			}
			else
				sum += diskset[i][j]-'0';
		// printf("sum is %d\n", sum);
		// printf("err is %d\n", err);

		if (err > 1)
			return 1;
		else if (err == 1) {
			if (diskset[parity_cur][j] == 'x') {
				if (sum % 2 == parity_result)
					continue;
				else
					return 1;
			}
			else {
				if (sum % 2 == parity_result)
					diskset[verr[0]][j] = '0';
				else
					diskset[verr[0]][j] = '1';
			}
		}
		else {
			if (sum % 2 != parity_result)
				return 1;
		}
	}
	return 0;
}

void putContent(void) {
	printf("valid, contents are: ");

	printf("\n");
}

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int kase = 1;
	while(scanf("%d", &d_cnt)== 1 && d_cnt){
		memset(diskset, '\0', sizeof(diskset));
		memset(parity, '\0', sizeof(parity));
		scanf("%d%d%s", &s_cnt, &b_cnt, parity);
		for (int i = 0; i < d_cnt; i++)
			scanf("%s", diskset[i]);
		printf("Disk set %d is ", kase++);
		if (check_data())
			printf("invalid.\n");
		else
			putContent();
	}
	return 0;
}