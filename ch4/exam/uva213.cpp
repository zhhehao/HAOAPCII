# include <cstdio>
# include <cctype>
# include <cmath>
using namespace std;

# define maxn 300
char map_code[maxn];
const int start_code[8] = {-1, 0, 1, 4, 11, 26, 57, 120};

int getValue(int len) {
	int sum = 0;
	char ch;
	for (int i = len - 1; i >= 0; i--) {
		ch = getchar();
		while(ch == '\n' || ch == '\r') ch = getchar();
		if (ch == '1')
			sum += (1 << i);
	}
	return sum;
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	for(;;) {
		map_code[0] = getchar();
		while(map_code[0] == '\n' || map_code[0] == '\r') map_code[0] = getchar();
		if (map_code[0] == EOF) break;
		int cnt = 1;
		for(;;) {
			map_code[cnt] = getchar();
			if (map_code[cnt] == '\n' || map_code[cnt] == '\r')
				break;
			cnt++;
		}
		int len;
		while((len = getValue(3)) != 0) {
			int code, bye = (int)(pow(2, len)-1);
			while((code = getValue(len)) != bye) {
				printf("%c", map_code[code+start_code[len]]);
			}
		}
		printf("\n");
	}
	return 0;
}