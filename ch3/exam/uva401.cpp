# include <cstdio>
# include <cstring>
# define maxn 30
const char P[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char M[] = "A000300HIL0JM0O0002TUVWXY51SE0Z0080";

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	char s[maxn];
	while (scanf("%s", s) != EOF) {
		bool is_pa = true, is_mi = true;
		for (int i = 0, j = strlen(s)-1; i <= j; i++, j--) {
			// printf("i is %d, j is %d\n", i, j);
			if (is_pa && i < strlen(s) && j >= 0 && s[i] != s[j])
				is_pa = false;
			if (is_mi && i < strlen(s) && j >= 0) {
				for (int k = 0; k < 35; k++) {
					if (s[i] == P[k] && (M[k] == '0' || s[j] != M[k])) {
						is_mi = false;
						break;
					}
				}
			}
			if (!is_pa && !is_mi) break;
		}

		if (is_pa) {
			if (is_mi)
				printf("%s -- is a mirrored palindrome.\n\n", s);
			else
				printf("%s -- is a regular palindrome.\n\n", s);
		}
		else {
			if (is_mi)
				printf("%s -- is a mirrored string.\n\n", s);
			else
				printf("%s -- is not a palindrome.\n\n", s);
		}
	}
	return 0;
}
