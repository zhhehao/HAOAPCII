# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

# define maxn 220
int mGear[maxn], dGear[maxn];
char mBuf[maxn], dBuf[maxn];

int getLen(int* top, int* bottom, int tLen, int bLen) {
	int cur = 0;
	for(;;) {
		int i = cur, j = 0;
		while(top[i]+bottom[j] <= 3) {
			i++; j++;
			if (j == bLen)
				return max(cur+bLen, tLen);
		}
		cur++;
	}
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while(scanf("%s%s", mBuf, dBuf) != EOF) {
		memset(mGear, 0, sizeof(mGear));
		memset(dGear, 0, sizeof(dGear));
		int mLen = strlen(mBuf), dLen = strlen(dBuf);
		for (int i = 0; i < mLen; i++)
			mGear[i] = mBuf[i] - '0';
		for (int i = 0; i < dLen; i++)
			dGear[i] = dBuf[i] - '0';
		printf("%d\n", min(getLen(mGear, dGear, mLen, dLen), getLen(dGear, mGear, dLen, mLen)));
	}
	return 0;
}