# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

int nr, nb, sh, tt, tr, tb, np, now, end_time;
const double eps = 1e-6;

struct Room {
	int id, in_time, used_time;
};

struct Bed {
	int id, in_time, used_time;
};

struct Patient {
	int id, room_id, bed_id, in_time, room_time, bed_time, in_bed_time;
	char name[10];
};

int cmp1(const Patient &a, const Patient &b) {
	if (a.in_bed_time != b.in_bed_time) return a.in_bed_time < b.in_bed_time;
	return a.room_id < b.room_id;
}

int cmp2(const Patient &a, const Patient &b) {
	return a.id < b.id;
}

vector <Room> room;
vector <Bed> bed;
vector <Patient> pat;

void input(void) {
	scanf("%d%d%d%d%d%d", &nb, &sh, &tt, &tr, &tb, &np);
	Room tmp_r; Bed tmp_b; Patient tmp_p;
	for (int i = 1; i <= nr; i++) {
		tmp_r.id = i;
		tmp_r.in_time = 0;
		tmp_r.used_time = 0;
		room.push_back(tmp_r);
	}
	for (int i = 1; i <= nb; i++) {
		tmp_b.id = i;
		tmp_b.in_time = 0;
		tmp_b.used_time = 0;
		bed.push_back(tmp_b);
	}
	for (int i = 1; i <= np; i++) {
		scanf("%s%d%d", tmp_p.name, &tmp_p.room_time, &tmp_p.bed_time);
		tmp_p.id = i;
		pat.push_back(tmp_p);
	}
}

void solve(void) {
	now = 0; end_time = 0;
	for (int i = 0; i < pat.size(); i++) {
		int cur;
		for (int j = 0; j < room.size(); j++) {
			if (room[j].in_time == now) {
				cur = j; break;
			}
		}
		pat[i].room_id = room[cur].id;
		pat[i].in_time = now;
		pat[i].in_bed_time = pat[i].in_time + pat[i].room_time;
		room[cur].in_time = now + pat[i].room_time + tr;
		room[cur].used_time += pat[i].room_time;
		now = room[0].in_time;
		for (int j = 1; j < room.size(); j++)
			now = min(room[j].in_time, now);
	}
	sort(pat.begin(), pat.end(), cmp1);
	for (int i = 0; i < pat.size(); i++) {
		int cur;
		for (int j = 0; j < bed.size(); j++) {
			if (bed[j].in_time <= pat[i].in_bed_time) {
				cur = j; break;
			}
		}
		pat[i].bed_id = bed[cur].id;
		end_time = max(end_time, pat[i].in_time + pat[i].room_time + tt + pat[i].bed_time);
		bed[cur].in_time = pat[i].in_bed_time + pat[i].bed_time + tb + tt;
		bed[cur].used_time += pat[i].bed_time;
	}
	sort(pat.begin(), pat.end(), cmp2);
	for (int i = 0; i < pat.size(); i++)
		pat[i].in_bed_time += tt;
}

void output(void) {
	printf(" Patient          Operating Room          Recovery Room\n");
	printf(" #  Name     Room#  Begin   End      Bed#  Begin    End\n");
	printf(" ------------------------------------------------------\n");
	for (int i = 0; i < pat.size(); i++) {
		printf("%2d  %-10s%2d   %2d:", pat[i].id, pat[i].name, pat[i].room_id, sh+pat[i].in_time/60);
		int minutes = pat[i].in_time % 60;
		if (minutes > 9) printf("%d", minutes);
		else printf("0%d", minutes);
		printf("   %2d:", sh+(pat[i].in_time+pat[i].room_time)/60);
		minutes = (pat[i].in_time+pat[i].room_time) % 60;
		if (minutes > 9) printf("%d", minutes);
		else printf("0%d", minutes);
		printf("     %2d   %2d:", pat[i].bed_id, sh+pat[i].in_bed_time/60);
		minutes = pat[i].in_bed_time % 60;
		if (minutes > 9) printf("%d", minutes);
		else printf("0%d", minutes);
		printf("   %2d:", sh+(pat[i].in_bed_time+pat[i].bed_time)/60);
		minutes = (pat[i].in_bed_time+pat[i].bed_time) % 60;
		if (minutes > 9) printf("%d\n", minutes);
		else printf("0%d\n", minutes);
	}
	printf("\nFacility Utilization\nType  # Minutes  %% Used\n");
	printf("-------------------------\n");
	for (int i = 0; i < room.size(); i++) {
		printf("Room%3d%8d", room[i].id, room[i].used_time);
		double uti;
		if (end_time == 0) uti = 0;
		else uti = room[i].used_time*1.0/end_time*100.0 + eps;
		printf("%8.2f\n", uti);
	}
	for (int i = 0; i < bed.size(); i++) {
		printf("Bed%4d%8d", bed[i].id, bed[i].used_time);
		double uti;
		if (end_time == 0) uti = 0;
		else uti = bed[i].used_time*1.0/end_time*100.0 + eps;
		printf("%8.2f\n", uti);
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while (scanf("%d", &nr) == 1) {
		room.resize(0); bed.resize(0); pat.resize(0);
		input();
		solve();
		output();
		printf("\n");
	}
	return 0;
}