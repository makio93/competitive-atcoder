// 解説WA1

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
	vector<int> ui0(n), ui1(n), di0(n), di1(n), li0(n), li1(n), ri0(n), ri1(n);
	vector<int> xlst, xdict;
	xlst.push_back(-1);
	rep(i, n) {
		int ui = r[i], di = r[i] + h[i] - 1, li = c[i], ri = c[i] + w[i] - 1;
		ui0[i] = (ui%2 == 0 ? ui+1 : ui) / 2;
		di0[i] = (di%2 == 0 ? di : di+1) / 2;
		li0[i] = (li%2 == 0 ? li+1 : li) / 2;
		ri0[i] = (ri%2 == 0 ? ri : ri+1) / 2;
		ui1[i] = (ui%2 == 1 ? ui : ui+1) / 2;
		di1[i] = (di%2 == 1 ? di+1 : di) / 2;
		li1[i] = (li%2 == 1 ? li : li+1) / 2;
		ri1[i] = (ri%2 == 1 ? ri+1 : ri) / 2;
		xlst.push_back(li0[i]);
		xlst.push_back(li1[i]);
		xlst.push_back(ri0[i]);
		xlst.push_back(ri1[i]);
	}
	function<void(vector<int>&,vector<int>&)> compress = [](vector<int>& lst, vector<int>& dict) {
		int llen = lst.size();
		rep(i, llen) dict.push_back(lst[i]);
		sort(all(dict));
		dict.erase(unique(all(dict)), dict.end());
		rep(i, llen) lst[i] = lower_bound(all(dict), lst[i]) - dict.begin();
	};
	compress(xlst, xdict);
	int xlen = xdict.size();
	ll res = 0;
	function<ll(map<int, vector<pair<int, int>>>&)> calc = [&](map<int, vector<pair<int, int>>>& yxlst) {
		lazy_segtree<pair<int, int>, op, e, bool, mapping, composition, id> lst(xlen);
		rep3(i, 1, xlen) lst.set(i, { 0, xdict[i]-xdict[i-1] });
		ll sum = 0;
		for (auto itr=yxlst.begin(); itr!=yxlst.end(); ++itr) {
			for (const auto& pi : itr->second) {
				auto [li, ri] = pi;
				if (ri < li) continue;
				lst.apply(li, ri, true);
			}
			if (next(itr) != yxlst.end()) sum += lst.all_prod().first * (ll)(next(itr)->first - itr->first);
		}
		return sum;
	};
	{
		map<int, vector<pair<int, int>>> yxlst;
		rep(i, n) if ((r[i]+c[i])%2 == 0) {
			yxlst[ui0[i]].emplace_back(lower_bound(all(xdict), li0[i]) - xdict.begin(), lower_bound(all(xdict), ri0[i]) - xdict.begin());
			yxlst[di0[i]].emplace_back(lower_bound(all(xdict), li0[i]) - xdict.begin(), lower_bound(all(xdict), ri0[i]) - xdict.begin());
		}
		res += calc(yxlst);
	}
	{
		map<int, vector<pair<int, int>>> yxlst;
		rep(i, n) if ((r[i]+c[i])%2 == 0) {
			yxlst[ui1[i]].emplace_back(lower_bound(all(xdict), li1[i]) - xdict.begin(), lower_bound(all(xdict), ri1[i]) - xdict.begin());
			yxlst[di1[i]].emplace_back(lower_bound(all(xdict), li1[i]) - xdict.begin(), lower_bound(all(xdict), ri1[i]) - xdict.begin());
		}
		res += calc(yxlst);
	}
	{
		map<int, vector<pair<int, int>>> yxlst;
		rep(i, n) if ((r[i]+c[i])%2 == 1) {
			yxlst[ui0[i]].emplace_back(lower_bound(all(xdict), li1[i]) - xdict.begin(), lower_bound(all(xdict), ri1[i]) - xdict.begin());
			yxlst[di0[i]].emplace_back(lower_bound(all(xdict), li1[i]) - xdict.begin(), lower_bound(all(xdict), ri1[i]) - xdict.begin());
		}
		res += calc(yxlst);
	}
	{
		map<int, vector<pair<int, int>>> yxlst;
		rep(i, n) if ((r[i]+c[i])%2 == 1) {
			yxlst[ui1[i]].emplace_back(lower_bound(all(xdict), li0[i]) - xdict.begin(), lower_bound(all(xdict), ri0[i]) - xdict.begin());
			yxlst[di1[i]].emplace_back(lower_bound(all(xdict), li0[i]) - xdict.begin(), lower_bound(all(xdict), ri0[i]) - xdict.begin());
		}
		res += calc(yxlst);
	}
	cout << res << endl;
	return 0;
}
