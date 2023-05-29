// 解説WA2

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

pair<int, int> op(pair<int, int> li, pair<int, int> ri) { return { li.first + ri.first, li.second + ri.second }; }
pair<int, int> e() { return { 0, 1 }; }
pair<int, int> mapping(bool f, pair<int, int> x) { return f ? make_pair(x.second - x.first, x.second) : x; }
bool composition(bool f, bool g) { return f ? !g : g; }
bool id() { return false; }

const int LIM = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> h(n), w(n), r(n), c(n);
	rep(i, n) {
		cin >> h[i] >> w[i] >> r[i] >> c[i];
		r[i]--; c[i]--;
	}
	vector<int> xdict;
	xdict.push_back(-1);
	vector<vector<map<int, vector<pair<int, int>>>>> yxlst(2, vector<map<int, vector<pair<int, int>>>>(2));
	rep(i, n) {
		rep(py, 2) rep(px, 2) {
			if (r[i]%2!=py && c[i]%2==px) continue;
			if (r[i]%2==py && c[i]%2!=px) continue;
			int sy = (r[i] - py) / 2, sx = (c[i] - px) / 2;
			if (sy < 0) sy = 0;
			else ++sy;
			if (sx < 0) sx = 0;
			else ++sx;
			int ty = (r[i] + h[i] - 1 - py) / 2, tx = (c[i] + w[i] - 1 - px) / 2;
			if (sy<=ty && sx<=tx) {
				xdict.push_back(sx);
				xdict.push_back(sx+1);
				xdict.push_back(tx);
				xdict.push_back(tx+1);
				yxlst[py][px][sy].emplace_back(sx, tx);
				yxlst[py][px][ty].emplace_back(sx, tx);
			}
		}
	}
	sort(all(xdict));
	xdict.erase(unique(all(xdict)), xdict.end());
	int xlen = xdict.size();
	rep(py, 2) rep(px, 2) {
		for (auto& pi : yxlst[py][px]) for (auto& [li, ri] : pi.second) {
			li = lower_bound(all(xdict), li) - xdict.begin();
			ri = lower_bound(all(xdict), ri) - xdict.begin();
		}
	}
	ll res = 0;
	rep(py, 2) rep(px, 2) {
		lazy_segtree<pair<int, int>, op, e, bool, mapping, composition, id> lst(xlen);
		rep3(i, 1, xlen) lst.set(i, { 0, xdict[i]-xdict[i-1] });
		for (auto itr=yxlst[py][px].begin(); itr!=yxlst[py][px].end(); ++itr) {
			for (const auto& pi : itr->second) {
				auto [li, ri] = pi;
				lst.apply(li, ri+1, true);
			}
			if (next(itr) != yxlst[py][px].end()) res += lst.all_prod().first * (ll)(next(itr)->first - itr->first);
		}
	}
	cout << res << endl;
	return 0;
}
