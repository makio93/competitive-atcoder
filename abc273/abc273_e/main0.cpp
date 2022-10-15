// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct Page {
	Page* par;
	int val;
	Page(Page *pt=nullptr, int v=-1) : par(pt), val(v) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	unordered_map<int, Page*> book;
	Page *root = new Page(), *id = root;
	vector<int> res;
	rep(i, q) {
		string qi;
		cin >> qi;
		if (qi == "ADD") {
			int xi;
			cin >> xi;
			id = new Page(id, xi);
			res.push_back(id->val);
		}
		else if (qi == "DELETE") {
			if (id->par != nullptr) id = id->par;
			res.push_back(id->val);
		}
		else if (qi == "SAVE") {
			int yi;
			cin >> yi;
			book[yi] = id;
			res.push_back(id->val);
		}
		else {
			int zi;
			cin >> zi;
			if (book.find(zi) != book.end()) id = book[zi];
			else id = root;
			res.push_back(id->val);
		}
	}
	rep(i, q) cout << res[i] << (i<q-1?' ':'\n');
	return 0;
}
