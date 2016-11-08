# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

struct Maps {
	string name;
	double x1, y1, x2, y2;
};

struct Maps_sort {
	string name;
	double dis_cen, ratio, dis_lr, minx;
};

struct Locations {
	string name;
	double x, y;
	vector <string> maps;
};

vector <Maps> v_maps;
vector <Locations> v_loca;

void input(void) {
	v_maps.resize(0); v_loca.resize(0);
	Maps buf;
	cin >> buf.name;
	for (;;) {
		cin >> buf.name;
		if (buf.name == "LOCATIONS") break;
		cin >> buf.x1 >> buf.y1 >> buf.x2 >> buf.y2;
		if (buf.x1 > buf.x2) swap(buf.x1, buf.x2);
		if (buf.y1 > buf.y2) swap(buf.y1, buf.y2);
		v_maps.push_back(buf);
	}
	Locations buf_l;
	for (;;) {
		cin >> buf_l.name;
		if (buf_l.name == "REQUESTS") break;
		cin >> buf_l.x >> buf_l.y;
		v_loca.push_back(buf_l);
	}
}

void solve(void) {

}

int main(void) {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	input();
	solve();
	return 0;
}