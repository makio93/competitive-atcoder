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

// 自力WA2

using mint = modint998244353;

string nstr;
int m, n;
vector<int> c;
unordered_map<int, int> ctoid;

map<tuple<int, int, bool, bool>, pair<mint, mint>> memo;
pair<mint, mint> calc(int di, int bs, bool md, bool zr) {
	if (memo.find(make_tuple(di, bs, md, zr)) != memo.end()) return memo[make_tuple(di, bs, md, zr)];
	pair<mint, mint> res = { 0, 0 };
	if (di == n-1) {
		rep(i, 10) {
			if (md && i>nstr[di]-'0') break;
			int bval = bs;
			if (!(zr&&i==0) && ctoid.find(i)!=ctoid.end()) bval |= (1<<(ctoid[i]));
			if (bval == (1<<m)-1) {
				res.first++;
				res.second += i;
			}
		}
		return memo[make_tuple(di, bs, md, zr)] = res;
	}
	else {
		rep(i, 10) {
			if (md && i>nstr[di]-'0') break;
			if (md && i==nstr[di]-'0') {
				int bval = bs;
				if (!(zr&&i==0) && ctoid.find(i)!=ctoid.end()) bval |= (1<<ctoid[i]);
				auto tres = calc(di+1, bval, true, (zr&&i==0));
				res.first += tres.first;
				res.second += mint(10).pow((n-1)-di) * i * tres.first + tres.second;
			}
			else {
				int bval = bs;
				if (!(zr&&i==0) && ctoid.find(i)!=ctoid.end()) bval |= (1<<ctoid[i]);
				auto tres = calc(di+1, bval, false, (zr&&i==0));
				res.first += tres.first;
				res.second += mint(10).pow((n-1)-di) * i * tres.first + tres.second;
			}
		}
		return memo[make_tuple(di, bs, md, zr)] = res;
	}
};

int main() {
	cin >> nstr >> m;
	n = nstr.length();
	c = vector<int>(m);
	rep(i, m) cin >> c[i];
	rep(i, m) ctoid[c[i]] = i;
	auto ares = calc(0, 0, true, true);
	cout << ares.second.val() << endl;
	return 0;
}
