/*
** use 2 functions, rotatex,, rotatey to simulate
*/

# include <cstdio>
# include <cstring>
using namespace std;

# define MAXN 6

char cube_s[MAXN], cube_t[MAXN], cube_c[MAXN];

void rotateX() {
	char t = cube_c[1];
	cube_c[1] = cube_c[2];
	cube_c[2] = cube_c[4];
	cube_c[4] = cube_c[3];
	cube_c[3] = t;
}

void rotateY() {
	char t = cube_c[1];
	cube_c[1] = cube_c[5];
	cube_c[5] = cube_c[4];
	cube_c[4] = cube_c[0];
	cube_c[0] = t;
}

void getcube1() {
	strcpy(cube_c, cube_s);
}

void getcube2() {
	strcpy(cube_c, cube_s);
}

void getcube3() {
	strcpy(cube_c, cube_s);
}

void getcube4() {
	strcpy(cube_c, cube_s);
}

void getcube5() {
	strcpy(cube_c, cube_s);
}

void getcube6() {
	strcpy(cube_c, cube_s);
}

int cmpCube() {
	int cnt = 4;
	while(cnt--) {
		rotateX();
		if (strcmp(cube_c, cube_t) == 0)
			return 1;
	}
	return 0;
}

int checkCube() {
	getcube1();
	if(cmpCube())
		return 1;
	getcube2();
	if(cmpCube())
		return 1;
	getcube3();
	if(cmpCube())
		return 1;
	getcube4();
	if(cmpCube())
		return 1;
	getcube5();
	if(cmpCube())
		return 1;
	getcube6();
	if(cmpCube())
		return 1;
	return 0;
}

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	char buf[12];
	while(scanf("%s", buf) != EOF) {
		for (int i = 0; i < 6; i++)
			cube_s[i] = buf[i];
		for (int i = 6; i < 12; i++)
			cube_t[i-6] = buf[i];

		if (checkCube())
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}
	return 0;
}