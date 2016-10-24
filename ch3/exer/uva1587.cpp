# include <cstdio>
# include <map>
# include <algorithm>
# include <set>
using namespace std;

struct Pallets {
	int w, h;
	bool operator < (const Pallets &b) const {
		if (w < b.w)
			return w < b.w;
		else
			return h < b.h;
	}
};

map <Pallets, int> box;
Pallets key[6];
set <int> sideLen;

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	for(;;) {
		box.clear();
		sideLen.clear();
		Pallets pallet;
		int keyCount = 0;
		if (scanf("%d%d", &pallet.w, &pallet.h) == EOF)
			break;
		if (pallet.w > pallet.h)
			swap(pallet.w, pallet.h);
		box[pallet] = 1;
		key[keyCount++] = pallet;
		sideLen.insert(pallet.w);
		sideLen.insert(pallet.h);
		for (int i = 0; i < 5; i++) {
			scanf("%d%d", &pallet.w, &pallet.h);
			if (pallet.w > pallet.h)
				swap(pallet.w, pallet.h);
			if (box.count(pallet) > 0) {
				box[pallet]++;
			}
			else {
				box[pallet] = 1;
				key[keyCount++] = pallet;
			}
			sideLen.insert(pallet.w);
			sideLen.insert(pallet.h);
		}
		// printf("%d\n", box.size());
		if (sideLen.size() == 1)
			printf("POSSIBLE\n");
		else if (sideLen.size() > 3)
			printf("IMPOSSIBLE\n");
		else if (sideLen.size() == 2 && box.size() == 2) {
			if (box[key[0]] == 2 || box[key[0]] == 4)
				printf("POSSIBLE\n");
			else
				printf("IMPOSSIBLE\n");
		}
		else if (sideLen.size() == 3 && box.size() == 3) {
			if (box[key[0]] == 2 && box[key[1]] == 2)
				printf("POSSIBLE\n");
			else
				printf("IMPOSSIBLE\n");				
		}
		else {
			printf("IMPOSSIBLE\n");	
		}
	}
	return 0;
}