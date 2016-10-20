# include <cstdio>
# include <cstring>

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int c;
	while ((c = getchar()) != EOF) {
		bool isspace = true;
		for (int i = 0; i < strlen(s); i++) {
			if (c != s[i]) continue;
			else {
				printf("%c", s[i-1]);
				isspace = false;
				break;
			}
		}
		if (isspace)
			printf("%c", c);
	}
	return 0;
}