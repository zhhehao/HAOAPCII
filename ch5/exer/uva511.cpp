# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
# include <cmath>
using namespace std;

const double eps = 1e-8;

struct Maps {
	string name;
	double x1, y1, x2, y2;
};

struct Maps_sort {
	string name;
	double area, dis_cen, ratio, dis_lr, minx;
};

struct Locations {
	string name;
	double x, y;
	vector <string> maps;
};

int cmp (const Maps_sort& a, const Maps_sort& b) {
	if (abs(a.area-b.area) >= eps) return a.area > b.area;
	if (abs(a.dis_cen-b.dis_cen) >= eps) return a.dis_cen < b.dis_cen;
	if (abs(a.ratio-b.ratio) >= eps) return a.ratio < b.ratio;
	if (abs(a.dis_lr-b.dis_lr) >= eps) return a.dis_lr > b.dis_lr;
	return a.minx < b.minx;
}

vector <Maps> v_maps;
vector <Locations> v_loca;
map <string, int> s_loca;

void input(void) {
	v_maps.resize(0); v_loca.resize(0); s_loca.clear();
	Maps buf;
	cin >> buf.name;
	for (;;) {
		cin >> buf.name;
		if (buf.name == "LOCATIONS") break;
		cin >> buf.x1 >> buf.y1 >> buf.x2 >> buf.y2;
		if (buf.x1 < buf.x2 && buf.y1 > buf.y2) swap(buf.y1, buf.y2);
		if (buf.x1 > buf.x2) {
			if (buf.y1 > buf.y2) {
				swap(buf.x1, buf.x2);
				swap(buf.y1, buf.y2);
			}
			else {
				swap(buf.x1, buf.x2);
			}
		}
		v_maps.push_back(buf);
	}
	Locations buf_l;
	for (;;) {
		cin >> buf_l.name;
		if (buf_l.name == "REQUESTS") break;
		cin >> buf_l.x >> buf_l.y;
		v_loca.push_back(buf_l);
		s_loca[buf_l.name] = v_loca.size()-1;
	}

	for (int i = 0; i < v_loca.size(); i++) {
		vector <Maps_sort> ms; ms.resize(0);
		Locations& v = v_loca[i];
		for (int j = 0; j < v_maps.size(); j++) {
			Maps& m = v_maps[j];
			if (v.x > m.x1 && v.x < m.x2 && v.y > m.y1 && v.y < m.y2) {
				Maps_sort mm;
				mm.name = m.name;
				double ave_x = (m.x1 + m.x2) / 2;
				double ave_y = (m.y1 + m.y2) / 2;
				mm.area = (m.y2-m.y1)*(m.x2-m.x1);
				mm.dis_cen = (v.x-ave_x)*(v.x-ave_x) + (v.y-ave_y)*(v.y-ave_y);
				mm.ratio = abs((m.y2-m.y1)/(m.x2-m.x1)-0.75);
				mm.dis_lr = (v.x-m.x2)*(v.x-m.x2) + (v.y-m.y1)*(v.y-m.y1);
				mm.minx = m.x1;
				ms.push_back(mm);
			}
		}
		sort(ms.begin(), ms.end(), cmp);

		for (int j = 0; j < ms.size(); j++) {
			v.maps.push_back(ms[j].name);
		}
	}
}

void solve(void) {
	string request; int detail;
	for (;;) {
		cin >> request;
		if (request == "END") break;
		cin >> detail;
		cout << request + " at detail level " << detail;
		if (!s_loca.count(request)) {cout  << " unknown location\n"; continue;}
		vector <string>& vs = v_loca[s_loca[request]].maps;
		if (vs.size() == 0) {cout << " no map contains that location\n"; continue;}
		if (vs.size() < detail) {cout << " no map at that detail level; using " << vs[vs.size()-1] << "\n"; continue;}
		cout << " using " << vs[detail-1] << "\n";
	}
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	input();
	solve();
	return 0;
}