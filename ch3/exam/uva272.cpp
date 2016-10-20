# include <cstdio>
# include <cstring>

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int c, q = 1;
	while ((c = getchar()) != EOF) {
		if (c == '"') {
			printf("%s", q ? "``" : "''");
			q = !q;
		}
		else
			printf("%c", c);
	}
	return 0;
}