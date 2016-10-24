# include <cstdio>
# include <cmath>
# include <map>
# include <iostream>
# include <string>
using namespace std;

# define Err 1e-6

struct FloatType {
	int m, e;
	bool operator < (const FloatType &b) const {
		if (m == b.m)
			return e < b.e;
		else
			return m < b.m;
	}
};

map <FloatType, double> ft;

int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	ft.clear();
	FloatType fnum;
	for (int i = 0; i <= 9; i++) {
		for (int j = 1; j <= 30; j++) {
			fnum.m = i;
			fnum.e = j;
			double a = 1 - pow(2, -1*(i+1));
			double b = pow(2, j) - 1;
			ft[fnum] = log10(a) + b*log10(2);
		}
	}

	string number;
	while(cin >> number) {
		if (number[0] == '0') break;
		int pos = number.find("e");
		double c = stod(number.substr(0, pos));
		int d = stoi(number.substr(pos+1, number.length()-pos));
		double value = log10(c) + double(d);
		map <FloatType, double>::iterator it;
		for (it = ft.begin(); it != ft.end(); ++it) {
			if (abs(it->second - value) < Err) {
				printf("%d %d\n", it->first.m, it->first.e);
				break;
			}
		}
	}
	return 0;
}