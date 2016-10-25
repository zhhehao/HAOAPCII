# include <cstdio>
# include <cstring>
# include <cctype>
using namespace std;

# define maxn 300
# define EPS 1e-6
int s_count;

struct Students {
	int cid;
	char name[10], sid[11];
	int chinese, math, english, program;
	int total;
	double avg;
	bool is_active;
};

Students spms[maxn];

void show_rank() {
	printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}

void add_students() {
	bool dup;
	for(;;) {
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		scanf("%s", spms[s_count].sid);
		if(strlen(spms[s_count].sid) == 1)
			if (spms[s_count].sid[0] == '0') {
				// printf("There is %d students.\n", s_count);
				return;
			}
			else
				continue;
		spms[s_count].sid[10] = '\0';
		scanf("%d", &spms[s_count].cid);
		scanf("%s", spms[s_count].name);
		scanf("%d%d%d%d", &spms[s_count].chinese, &spms[s_count].math, &spms[s_count].english, &spms[s_count].program);
		spms[s_count].total = spms[s_count].chinese + spms[s_count].math + spms[s_count].english + spms[s_count].program;
		spms[s_count].avg = (double)spms[s_count].total / 4.0 + EPS;
		spms[s_count].is_active = true;
		dup = false;
		for (int i = 0; i < s_count; i++) {
			if (memcmp(spms[i].sid, spms[s_count].sid, sizeof(spms[s_count].sid)) == 0 && spms[i].is_active) {
				dup = true;
				break;
			}
		}
		if (dup)
			printf("Duplicated SID.\n");
		else
			s_count++;
	}
}

void remove_query_students(bool choose) {
	char id[10];
	for(;;) {
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf("%s", id);
		if(strlen(id) == 1)
			if (id[0] == '0') {
				return;
			}
			else
				continue;
		if (choose) {
			int rm_cnt = 0;
			if (isdigit(id[0])) {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && memcmp(spms[i].sid, id, sizeof(id)) == 0) {
						spms[i].is_active = false;
						rm_cnt++;
						break;
					}
				}
			}
			else {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && memcmp(spms[i].name, id, sizeof(char)*strlen(spms[i].name)) == 0) {
						spms[i].is_active = false;
						rm_cnt++;
					}
				}
			}
			printf("%d student(s) removed.\n", rm_cnt);
		}
		else {
			if (isdigit(id[0])) {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && memcmp(spms[i].sid, id, sizeof(id)) == 0) {
						int srank = 1;
						for (int j = 0; j < s_count; j++) {
							if (j != i && spms[j].is_active && spms[j].total > spms[i].total)
								srank++;
						}
						printf("%d %s %d %s %d %d %d %d %d %.2lf\n", srank, spms[i].sid, spms[i].cid, spms[i].name, spms[i].chinese, spms[i].math, spms[i].english, spms[i].program, spms[i].total, spms[i].avg);
						break;
					}
				}
			}
			else {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && memcmp(spms[i].name, id, sizeof(char)*strlen(spms[i].name)) == 0) {
						int srank = 1;
						for (int j = 0; j < s_count; j++) {
							if (j != i && spms[j].is_active && spms[j].total > spms[i].total)
								srank++;
						}
						printf("%d %s %d %s %d %d %d %d %d %.2lf\n", srank, spms[i].sid, spms[i].cid, spms[i].name, spms[i].chinese, spms[i].math, spms[i].english, spms[i].program, spms[i].total, spms[i].avg);
					}
				}
			}
		}
	}
}

void show_static() {
	printf("Please enter class ID, 0 for the whole statistics.\n");
	int cid;
	scanf("%d", &cid);
	int num_student = 0;
	int c_ave = 0, cps = 0, cfs = 0;
	int m_ave = 0, mps = 0, mfs = 0;
	int e_ave = 0, eps = 0, efs = 0;
	int p_ave = 0, pps = 0, pfs = 0;
}

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	s_count = 0;
	int command;
	for(;;) {
		printf("Welcome to Student Performance Management System (SPMS).\n\n");
		printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n");
		printf("5 - Show Statistics\n0 - Exit\n\n");
		scanf("%d", &command);
		switch (command) {
			case 0: goto end; break;
			case 1: add_students(); break;
			case 2: remove_query_students(true); break;
			case 3: remove_query_students(false); break;
			case 4: show_rank(); break;
			case 5: show_static(); break;
		}
	}
end:
	return 0;
}
