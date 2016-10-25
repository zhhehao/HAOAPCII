# include <cstdio>
using namespace std;

# define maxn 50

int r, c, cnt;
bool gone;

struct Operation{
	char com[2];
	int argv[maxn], len;
};

Operation oper[1000];

void actOper(int* cr, int* cc, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (oper[i].com[0] == 'E') {
			if (oper[i].argv[0] == *cr && oper[i].argv[1] == *cc) {
				*cr = oper[i].argv[2];
				*cc = oper[i].argv[3];
			}
			else if (oper[i].argv[2] == *cr && oper[i].argv[3] == *cc) {
				*cr = oper[i].argv[0];
				*cc = oper[i].argv[1];
			}
		}
		else if (oper[i].com[0] == 'I') {
			if (oper[i].com[1] == 'R') {
				int count = 0;
				for (int j = 0; j < oper[i].len; j++) {
					if (oper[i].argv[j] <= *cr)
						count++;
				}
				*cr += count;
			}
			else {
				int count = 0;
				for (int j = 0; j < oper[i].len; j++) {
					if (oper[i].argv[j] <= *cc)
						count++;
				}
				*cc += count;
			}
		}
		else {
			if (oper[i].com[1] == 'R') {
				int count = 0;
				for (int j = 0; j < oper[i].len; j++) {
					if (oper[i].argv[j] == *cr) {
						gone = true;
						return;
					}
					else if (oper[i].argv[j] <= *cr)
						count++;
				}
				*cr -= count;
			}
			else {
				int count = 0;
				for (int j = 0; j < oper[i].len; j++) {
					if (oper[i].argv[j] == *cc) {
						gone = true;
						return;
					}
					else if (oper[i].argv[j] <= *cc)
						count++;
				}
				*cc -= count;
			}
		}
		// printf("cr is %d, cc is %d\n", *cr, *cc);
	}
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out","w", stdout);
	int kase = 0;
	while(scanf("%d%d", &r, &c) == 2 && r) {
		scanf("%d", &cnt);
		for (int i = 0; i < cnt; i++) {
			scanf("%s", oper[i].com);
			if (oper[i].com[0] == 'E')
				scanf("%d%d%d%d", &oper[i].argv[0], &oper[i].argv[1], &oper[i].argv[2], &oper[i].argv[3]);
			else {
				scanf("%d", &oper[i].len);
				for (int j = 0; j < oper[i].len; j++)
					scanf("%d", &oper[i].argv[j]);
			}
		}
		if (kase++)
			printf("\n");
		printf("Spreadsheet #%d\n", kase);
		int cell;
		scanf("%d", &cell);
		while(cell--) {
			int cr, cc;
			scanf("%d%d", &cr, &cc);
			printf("Cell data in (%d,%d) ", cr, cc);
			gone = false;
			actOper(&cr, &cc, cnt);
			if (gone)
				printf("GONE\n");
			else
				printf("moved to (%d,%d)\n", cr, cc);
		}
	}
	return 0;
}