/* get ac, after use strcmp replace memcmp
**
** Please remember divide 0 may be caused error, need handle it.
** And add EPS to resolve floating number error.
*/
# include <cstdio>
# include <cstring>
# include <cctype>
using namespace std;

# define maxn 1024
# define EPS 1e-5
int s_count;

struct Students {
	int cid;
	char name[12], sid[12];
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
		memset(spms[s_count].sid, '\0', sizeof(spms[s_count].sid));
		scanf("%s", spms[s_count].sid);
		if(strlen(spms[s_count].sid) == 1 && spms[s_count].sid[0] == '0')
			break;
		scanf("%d", &spms[s_count].cid);
		memset(spms[s_count].name, '\0', sizeof(spms[s_count].name));
		scanf("%s", spms[s_count].name);
		scanf("%d%d%d%d", &spms[s_count].chinese, &spms[s_count].math, &spms[s_count].english, &spms[s_count].program);
		spms[s_count].total = spms[s_count].chinese + spms[s_count].math + spms[s_count].english + spms[s_count].program;
		spms[s_count].avg = (double)spms[s_count].total / 4.0 + EPS;
		spms[s_count].is_active = true;
		dup = false;
		for (int i = 0; i < s_count; i++) {
			if (strcmp(spms[i].sid, spms[s_count].sid) == 0 && spms[i].is_active) {
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
	char id[12];
	for(;;) {
		printf("Please enter SID or name. Enter 0 to finish.\n");
		memset(id, '\0', sizeof(id));
		scanf("%s", id);
		if(strlen(id) == 1 && id[0] == '0')
			break;
		if (choose) {
			int rm_cnt = 0;
			if (isdigit(id[0])) {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && strcmp(spms[i].sid, id) == 0) {
						spms[i].is_active = false;
						rm_cnt++;
						break;
					}
				}
			}
			else {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && strcmp(spms[i].name, id) == 0) {
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
					if (spms[i].is_active && strcmp(spms[i].sid, id) == 0) {
						int srank = 1;
						for (int j = 0; j < s_count; j++) {
							if (j != i && spms[j].is_active && spms[j].total > spms[i].total)
								srank++;
						}
						printf("%d %s %d %s %d %d %d %d %d %.2f\n", srank, spms[i].sid, spms[i].cid, spms[i].name, spms[i].chinese, spms[i].math, spms[i].english, spms[i].program, spms[i].total, spms[i].avg);
						break;
					}
				}
			}
			else {
				for (int i = 0; i < s_count; i++) {
					if (spms[i].is_active && strcmp(spms[i].name, id) == 0) {
						int srank = 1;
						for (int j = 0; j < s_count; j++) {
							if (j != i && spms[j].is_active && spms[j].total > spms[i].total)
								srank++;
						}
						printf("%d %s %d %s %d %d %d %d %d %.2f\n", srank, spms[i].sid, spms[i].cid, spms[i].name, spms[i].chinese, spms[i].math, spms[i].english, spms[i].program, spms[i].total, spms[i].avg);
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
	int cps = 0, cfs = 0, mps = 0, mfs = 0;
	int eps = 0, efs = 0, pps = 0, pfs = 0;
	int ctotal = 0, mtotal = 0, etotal = 0, ptotal = 0;
	double c_ave, m_ave, e_ave, p_ave;
	int allpass = 0, threepass = 0, twopass = 0, onepass = 0, nopass = 0;
	if (cid == 0) {
		for (int i = 0; i < s_count; i++) {
			int pass = 0;
			if (spms[i].is_active) {
				num_student++;
				ctotal += spms[i].chinese;
				mtotal += spms[i].math;
				etotal += spms[i].english;
				ptotal += spms[i].program;
				if (spms[i].chinese >= 60) { cps++; pass++;}
				else cfs++;
				if (spms[i].math >= 60) { mps++; pass++;}
				else mfs++;
				if (spms[i].english >= 60) { eps++; pass++;}
				else efs++;
				if (spms[i].program >= 60) { pps++; pass++;}
				else pfs++;
				if (pass == 4)
					allpass++;
				else if (pass == 3)
					threepass++;
				else if (pass == 2)
					twopass++;
				else if (pass == 1)
					onepass++;
				else
					nopass++;
			}
		}
		// division 0 need be consider.
		printf("Chinese\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)ctotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", cps);
		printf("Number of failed students: %d\n\n", cfs);
		printf("Mathematics\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)mtotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", mps);
		printf("Number of failed students: %d\n\n", mfs);
		printf("English\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)etotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", eps);
		printf("Number of failed students: %d\n\n", efs);
		printf("Programming\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)ptotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", pps);
		printf("Number of failed students: %d\n\n", pfs);
		printf("Overall:\n");
		printf("Number of students who passed all subjects: %d\n", allpass);
		printf("Number of students who passed 3 or more subjects: %d\n", allpass+threepass);
		printf("Number of students who passed 2 or more subjects: %d\n", allpass+threepass+twopass);
		printf("Number of students who passed 1 or more subjects: %d\n", allpass+threepass+twopass+onepass);
		printf("Number of students who failed all subjects: %d\n\n", nopass);
	}
	else {
		for (int i = 0; i < s_count; i++) {
			int pass = 0;
			if (spms[i].is_active && spms[i].cid == cid) {
				num_student++;
				ctotal += spms[i].chinese;
				mtotal += spms[i].math;
				etotal += spms[i].english;
				ptotal += spms[i].program;
				if (spms[i].chinese >= 60) { cps++; pass++;}
				else cfs++;
				if (spms[i].math >= 60) { mps++; pass++;}
				else mfs++;
				if (spms[i].english >= 60) { eps++; pass++;}
				else efs++;
				if (spms[i].program >= 60) { pps++; pass++;}
				else pfs++;
				if (pass == 4)
					allpass++;
				else if (pass == 3)
					threepass++;
				else if (pass == 2)
					twopass++;
				else if (pass == 1)
					onepass++;
				else
					nopass++;
			}
		}
		printf("Chinese\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)ctotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", cps);
		printf("Number of failed students: %d\n\n", cfs);
		printf("Mathematics\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)mtotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", mps);
		printf("Number of failed students: %d\n\n", mfs);
		printf("English\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)etotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", eps);
		printf("Number of failed students: %d\n\n", efs);
		printf("Programming\nAverage Score: %.2f\n", num_student == 0 ? 0 : (double)ptotal / (double)num_student + EPS);
		printf("Number of passed students: %d\n", pps);
		printf("Number of failed students: %d\n\n", pfs);
		printf("Overall:\n");
		printf("Number of students who passed all subjects: %d\n", allpass);
		printf("Number of students who passed 3 or more subjects: %d\n", allpass+threepass);
		printf("Number of students who passed 2 or more subjects: %d\n", allpass+threepass+twopass);
		printf("Number of students who passed 1 or more subjects: %d\n", allpass+threepass+twopass+onepass);
		printf("Number of students who failed all subjects: %d\n\n", nopass);
	}
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
