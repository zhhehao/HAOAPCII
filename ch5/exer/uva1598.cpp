# include <iostream>
# include <queue>
# include <vector>
# include <string>
# include <algorithm>
# include <map>
# include <set>
using namespace std;

const int maxn = 10000 + 10;

// for priority, "<" means large value first, ">" means small value first

struct Quote_bid {
	int id, price;
	bool operator < (const Quote_bid& b) const {
		if (price != b.price) return price < b.price;
		return id > b.id;
	}
};

struct Quote_ask {
	int id, price;
	bool operator < (const Quote_ask& b) const {
		if (price != b.price) return price > b.price;
		return id > b.id;
	}
};

struct Quote_all {
	int price, size, from;
};

Quote_all all[maxn];
set <int> inactive;
map <int, int> m_buy;
map <int, int> m_sell;

int cnt;

void input(priority_queue <Quote_bid>& buy, priority_queue <Quote_ask>& sell) {
	string buf; cin >> buf;
	if (buf[0] != 'C') {
		if (buf[0] == 'B') {
			cin >> all[cnt].size >> all[cnt].price;
			all[cnt].from = 1;
			Quote_bid tmp; tmp.id = cnt; tmp.price = all[cnt].price;
			buy.push(tmp);
			if (!m_buy.count(all[cnt].price)) m_buy[all[cnt].price] = all[cnt].size;
			else m_buy[all[cnt].price] += all[cnt].size;
			cnt++;
		}
		else {
			cin >> all[cnt].size >> all[cnt].price;
			all[cnt].from = 0;
			Quote_ask tmp; tmp.id = cnt; tmp.price = all[cnt].price;
			sell.push(tmp);
			if (!m_sell.count(all[cnt].price)) m_sell[all[cnt].price] = all[cnt].size;
			else m_sell[all[cnt].price] += all[cnt].size;
			cnt++;
		}
	}
	else {
		int id; cin >> id;
		if (all[id].from) m_buy[all[id].price] -= all[id].size;
		else m_sell[all[id].price] -= all[id].size;
		all[id].size = 0;
		cnt++;
		inactive.insert(id);
	}
}

void chk_inactive(priority_queue <Quote_bid>& buy, priority_queue <Quote_ask>& sell) {
	while (!buy.empty() && inactive.count(buy.top().id)) {
		buy.pop();
	}
	while (!sell.empty() && inactive.count(sell.top().id)) {
		sell.pop();
	}
}

void do_trade(priority_queue <Quote_bid>& buy, priority_queue <Quote_ask>& sell) {
	int t_price, t_size;
	Quote_bid b = buy.top(); buy.pop();
	Quote_ask s = sell.top(); sell.pop();
	if (all[cnt-1].from) t_price = s.price;
	else t_price = b.price;
	t_size = min(all[b.id].size, all[s.id].size);
	cout << "TRADE " << t_size << " " << t_price << "\n";
	all[b.id].size -= t_size;
	all[s.id].size -= t_size;
	m_buy[b.price] -= t_size;
	m_sell[s.price] -= t_size;
	if (all[b.id].size != 0) {buy.push(b);}
	if (all[s.id].size != 0) {sell.push(s);}
}

void solve(priority_queue <Quote_bid>& buy, priority_queue <Quote_ask>& sell) {
	chk_inactive(buy, sell);
	while (!buy.empty() && !sell.empty() && buy.top().price >= sell.top().price && all[buy.top().id].size != 0 && all[sell.top().id].size != 0) {
		do_trade(buy, sell);
		chk_inactive(buy, sell);
	}
	int b_price, b_size, s_price, s_size;
	if (buy.empty()) {
		b_price = 0; b_size = 0;
	}
	else {
		b_price = buy.top().price;
		b_size = m_buy[buy.top().price];
	}
	if (sell.empty()) {
		s_price = 99999; s_size = 0;
	}
	else {
		s_price = sell.top().price;
		s_size = m_sell[sell.top().price];
	}
	cout << "QUOTE " << b_size << ' ' << b_price << " - " << s_size << ' ' << s_price << "\n";
}

int main(void) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, kase = 0;
	while (cin >> n){
		if (kase++) cout << "\n";
		cnt = 1; inactive.clear(); m_buy.clear(); m_sell.clear();
		priority_queue <Quote_bid> buy; while(!buy.empty()) buy.pop();
		priority_queue <Quote_ask> sell; while(!sell.empty()) sell.pop();
		while (n--) {
			input(buy, sell);
			solve(buy, sell);
		}
	}
	return 0;
}