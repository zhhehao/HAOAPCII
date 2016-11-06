# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>
using namespace std;

struct Book {
	string title, author;
	bool is_borrowed;
	bool operator < (const Book& b) const {
		if (author == b.author)
			return title < b.title;
		else
			return author < b.author;
	}
};

vector <Book> shelve;
vector <Book> relist;
map <string, int> catalog;

int get_pos(int pos) {
	pos--;
	if (pos < 0) return -1;
	while (shelve[pos].is_borrowed) {
		pos--;
		if (pos < 0) return -1;
	}
	return pos;
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	string buf;
	Book book;
	shelve.resize(0);
	while (getline(cin, buf)) {
		if (buf == "END") break;
		book.title = buf.substr(0, buf.find('\"', 1)+1);
		book.author = buf.substr(buf.find(" by ")+4);
		// cout << book.title + ':' + book.author + "\n";
		book.is_borrowed = false;
		shelve.push_back(book);
	}
	sort(shelve.begin(), shelve.end());
	catalog.clear();
	for (int i = 0; i < shelve.size(); i++) catalog[shelve[i].title] = i;
	relist.resize(0);
	while (getline(cin, buf)) {
		if (buf == "END") break;
		// cout << buf.substr(7) + "\n";
		if (buf[0] == 'B') {
			shelve[catalog[buf.substr(7)]].is_borrowed = true;
		}
		else if (buf[0] == 'R') {
			relist.push_back(shelve[catalog[buf.substr(7)]]);
		}
		else if (buf[0] == 'S') {
			sort(relist.begin(), relist.end());
			for (int i = 0; i < relist.size(); i++) {
				int pos = get_pos(catalog[relist[i].title]);
				if (pos == -1)
					cout << "Put " + relist[i].title + " first\n";
				else
					cout << "Put " + relist[i].title + " after " + shelve[pos].title + "\n";
				shelve[catalog[relist[i].title]].is_borrowed = false;
			}
			cout << "END\n";
			relist.resize(0);
		}
	}
	return 0;
}
