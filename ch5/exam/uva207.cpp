# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 144 + 5;
const double EPS = 1e-6;

struct Player {
	int rd2, rd4, rd[4], dq, rank;
	char name[25];
	bool amateur, tie;
	double prize;
};

Player p[maxn];
int n, pos;
double prize[maxn];

int cmp1(const Player& a, const Player &b) {
	if (a.dq > 1 && b.dq > 1)
		return a.rd2 < b.rd2;
	return a.dq > b.dq;
}

int cmp2(const Player& a, const Player &b) {
	if (a.dq != b.dq)
		return a.dq > b.dq;
	if (a.rd4 != b.rd4)
		return a.rd4 < b.rd4;
	return strcmp(a.name, b.name) < 0;
}

void getInput(void) {
	memset(p, 0, sizeof(0));
	double total_prize; scanf("%lf", &total_prize);
	for (int i = 0; i < 70; i++) {
		scanf("%lf", &prize[i]);
		prize[i] = prize[i] * total_prize / 100.0;
	}

	scanf("%d", &n);
	char str[40]; fgets(str, 40, stdin);
	for (int i = 0; i < n; i++) {
		fgets(p[i].name, 21, stdin);
		if (strchr(p[i].name, '*'))
			p[i].amateur = true;
		else
			p[i].amateur = false;
		p[i].tie = false;
		p[i].dq = 4;
		p[i].rd2 = 0;
		p[i].rd4 = 0;
		for (int j = 0; j < 4; j++) {
			if (!scanf("%d", &p[i].rd[j])) {
				p[i].dq = j;
				break;
			}
			if (j < 2)
				p[i].rd2 += p[i].rd[j];
			p[i].rd4 += p[i].rd[j];
		}
		fgets(str, 40, stdin);
	}
}

// void solve(){
//     sort(p,p+n,cmp1);
//     pos=0;
//     while(pos<min(n,70)&&p[pos].dq>1) ++pos;
//     while(p[pos].dq>1&&p[pos].rd2==p[pos-1].rd2) ++pos;
//     sort(p,p+pos,cmp2);
//     int k=0,rk=0,prk=0;
//     while(k<pos){
//         if(p[k].dq != 4) break;
//         int sta=k,prerk=rk+1,cnt=0;
//         bool x=false;
//         double sum=0;
//         while(p[sta].dq == 4 &&p[k].rd4==p[sta].rd4){
//             if(!p[sta].amateur) sum+=prize[prk+cnt++],x=true;
//             ++rk,++sta;
//         }
//         sum/=cnt;
//         for(int i=k;i<=sta;++i){
//             p[i].rank=prerk;
//             if(prk>69) p[i].amateur=true,p[i].tie=false;
//             if(!p[i].amateur) p[i].prize=sum,p[i].tie=cnt>1;
//         }
//         k=sta-1,k++;
//         prk+=cnt;
//     }
// }

void processInput(void) {
	sort(p, p+n, cmp1);
	pos = 0;
	while (pos < min(n, 70) && p[pos].dq > 1) pos++;
	while (p[pos].dq > 1 && p[pos].rd2 == p[pos-1].rd2) pos++;
	sort(p, p+pos, cmp2);

	int k = 0, rk = 0, prk = 0;
	while (k < pos) {
		if (p[k].dq != 4) break;
		int sta = k, prerk = rk + 1, cnt = 0;
		double sum = 0;
		while (p[sta].dq == 4 && p[k].rd4 == p[sta].rd4) {
			if (!p[sta].amateur)
				sum += prize[prk + cnt++];
			rk++;
			sta++;
		}
		sum /= cnt;
		for (int i = k; i < sta; i++) {
			p[i].rank = prerk;
			// I found my wa reason, it is here.
			if (prk > 69) p[i].amateur = true, p[i].tie = false;
			if (!p[i].amateur) {
				p[i].prize = sum;
				if (cnt > 1)
					p[i].tie = true;
			}
		}
		k = sta;
		prk += cnt;
	}
}

void putOutput(void) {
	printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < pos; i++) {
		printf("%-21s", p[i].name);
		if (p[i].dq != 4) printf("          ");
		else {
			char t[5];
			sprintf(t, "%d%c", p[i].rank, p[i].tie ? 'T':' ');
			printf("%-10s", t);
		}
		for (int j = 0; j < 4; j++) {
			if (p[i].dq == j) break;
			printf("%-5d", p[i].rd[j]);
		}
		if (p[i].dq == 2) printf("          DQ");
		if (p[i].dq == 3) printf("     DQ");
		if (p[i].dq != 4) {printf("\n"); continue;}
		if (p[i].amateur)
			printf("%d", p[i].rd4);
		else {
			printf("%-10d", p[i].rd4);
			printf("$%9.2lf", p[i].prize);
		}
		printf("\n");
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		getInput();
		// solve();
		processInput();
		putOutput();
		if (t) printf("\n");
	}
	return 0;
}
