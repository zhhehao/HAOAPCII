/*
** detail
*/

# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 144 + 5;
const double EPS = 1e-6;

struct Player {
	int tot, pre, dq, rd[4], rank;
	char name[25];
	double prize;
	bool amateur, tie;
};

Player p[maxn];

int cmp1(const Player& a, const Player& b) {
	if (a.dq > -3 && b.dq > -3)
		return a.pre < b.pre;
	else
		return a.dq > b.dq;
}

int cmp2(const Player& a, const Player& b) {
	if (a.dq != b.dq)
		return a.dq > b.dq;
	if (a.tot != b.tot)
		return a.tot < b.tot;
	return strcmp(a.name, b.name) < 0;
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T, kase = 0; scanf("%d", &T);
	while (T--) {
		memset(p, 0, sizeof(p));
		double total_prize; scanf("%lf", &total_prize);
		double prize[maxn];
		for (int i = 0; i < 70; i++) {
			scanf("%lf", &prize[i]);
			prize[i] = prize[i]  / 100.0 * total_prize;
		}
		int n; scanf("%d", &n); char s[40];
		fgets(s, 40, stdin);
		for (int i = 0; i < n; i++) {
			fgets(p[i].name, 20, stdin);
			if (strchr(p[i].name, '*')) p[i].amateur = true;
			for (int j = 0; j < 4; j++) {
				if (!scanf("%d", &p[i].rd[j])) {
					p[i].dq = j - 4;
					break;
				}
				if (j < 2) p[i].pre += p[i].rd[j];
				p[i].tot += p[i].rd[j];
			}
			fgets(s, 40, stdin);
		}

		// for (int i = 0; i < n; i++)
		// 	printf("%s\n", p[i].name);

		sort(p, p+n, cmp1);
		int pos = 0;
		while (pos < min(n, 70) && p[pos].dq > -3) ++pos;
		while (p[pos].dq > -3 && p[pos].pre == p[pos-1].pre) ++pos;
		// printf("pos is %d\n", pos);
		sort(p, p+pos, cmp2);

		int k=0,rk=0,prk=0;
	    while(k<pos){
	        if(p[k].dq) break;
	        int sta=k,prerk=rk+1,cnt=0;
	        bool x=false;
	        double sum=0;
	        while(!p[sta].dq&&p[k].tot==p[sta].tot){
	            if(!p[sta].amateur) sum+=pri[prk+cnt++],x=true;
	            ++rk,++sta;
	        }
	        sum/=cnt;
	        for(int i=k;i<=sta;++i){
	            p[i].rk=prerk;
	            if(prk>69) p[i].amateur=true,p[i].t=false;
	            if(!p[i].amateur) p[i].prize=sum,p[i].t=cnt>1;
	        }
	        k=sta-1,k++;
	        prk+=cnt;
	    }

		int rk = 0, prk = 0;
		for (int i = 0; i < pos; ){
			// printf("i is %d\n", i);
			if (p[i].dq) break;
			int same = i, same_cnt = 0, prerk = rk + 1;
			double sum = 0.0;
			while (!p[same].dq && p[i].tot == p[same].tot) {
				if (!p[same].amateur) {
					sum += prize[prk + same_cnt++];
				}
				rk++;
				same++;
			}
			sum /= same_cnt;
			for (int j = i; j <= same; j++) {
				p[j].rank = prerk;
				if (prk > 69) {
					p[j].amateur = true;
					p[j].tie = false;
				}
				if (!p[j].amateur) {
					p[j].prize = sum;
					if (same_cnt > 1)
						p[j].tie = true;
					else
						p[j].tie = false;
				}
			}
			i = same - 1;
			i++;
			prk += same_cnt;
		}

		if (kase++) printf("\n");
		printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
    	printf("-----------------------------------------------------------------------\n");
    	for (int i = 0; i < pos; i++) {
    		printf("%-21s", p[i].name);
    		if (p[i].dq) printf("          ");
    		else {
    			char place[5];
    			sprintf(place, "%d%c", p[i].rank, p[i].tie ? 'T' : ' ');
    			printf("%-10s", place);
    		}
    		for (int j = -4; j < p[i].dq; j++) {
    			printf("%-5d", p[i].rd[4+j]);
    		}
    		for (int j = p[i].dq; j < 0; j++) printf("     ");
    		if (p[i].dq) printf("%s", "DQ");
    		else if (!p[i].amateur)
    			printf("%-10d", p[i].tot);
    		else
    			printf("%d", p[i].tot);
    		if(p[i].dq||p[i].amateur){printf("\n");continue;}
        	printf("$%9.2lf\n",p[i].prize + EPS);
    	}
	}
	return 0;
}