/*
** every ugly number product 2, 3, 5, always ugly number
*/

# include <cstdio>
# include <queue>
# include <set>
using namespace std;

priority_queue <long long, vector<long long>, greater<long long> > pq;
set <long long> ugly;

int main(void) {
	int cnt = 1;
	pq.push(1);
	ugly.insert(1);
	for (;;) {
		if (cnt == 1500) {
			printf("The 1500'th ugly number is %d.\n", pq.top());
			break;
		}
		long long u1 = pq.top() * 2;
		long long u2 = pq.top() * 3;
		long long u3 = pq.top() * 5;
		if (!ugly.count(u1)) {
			ugly.insert(u1);
			pq.push(u1);
		}
		if (!ugly.count(u2)) {
			ugly.insert(u2);
			pq.push(u2);
		}
		if (!ugly.count(u3)) {
			ugly.insert(u3);
			pq.push(u3);
		}
		pq.pop();
		cnt++;
	}
	return 0;
}