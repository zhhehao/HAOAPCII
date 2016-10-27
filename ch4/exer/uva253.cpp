/*
** use 3 functions, rotateX, rotateY, rotateZ to simulate
*/

# include <cstdio>
# include <cstring>
using namespace std;

# define MAXN 6

char cube_s[MAXN], cube_c[MAXN];

int cmpCube() {
	int ok = 1;
	for (int i = 0; i < 6; i++)
		if (cube_c[i] != cube_s[i]) {
			ok = 0;
			break;
		}
	return ok;
}

int rotateX() {
	char t = cube_c[1];
	cube_c[1] = cube_c[2];
	cube_c[2] = cube_c[4];
	cube_c[4] = cube_c[3];
	cube_c[3] = t;
	return cmpCube();
}

int rotateY() {
	char t = cube_c[1];
	cube_c[1] = cube_c[5];
	cube_c[5] = cube_c[4];
	cube_c[4] = cube_c[0];
	cube_c[0] = t;
	return cmpCube();
}

int rotateZ() {
	char t = cube_c[0];
	cube_c[0] = cube_c[2];
	cube_c[2] = cube_c[5];
	cube_c[5] = cube_c[3];
	cube_c[3] = t;
	return cmpCube();
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	char buf[15];
	while(scanf("%s", buf) != EOF) {
		for (int i = 0; i < 6; i++)
			cube_c[i] = buf[i];
		for (int i = 6; i < 12; i++)
			cube_s[i-6] = buf[i];

		bool is_same = false;
		for (int i = 0; i < 4; i++) {
			if (rotateX()) {
				is_same = true;
				goto end;
			}
			for (int j = 0; j < 4; j++) {
				if (rotateY())  {
					is_same = true;
					goto end;
				}
				for (int k = 0; k < 4; k++) {
					if (rotateZ()) {
						is_same = true;
						goto end;
					}
				}
			}
		}

end:
		if (is_same)
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}
	return 0;
}
