// 本番WA

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

const ll LINF = (ll)(1e18);

int main() {
	int n;
	ll h;
	cin >> n >> h;
	vector<int> t(n), d(n);
	rep(i, n) cin >> t[i] >> d[i];
	unordered_map<int, int> dlst;
	rep(i, n) {
		if (dlst.find(d[i]) == dlst.end()) dlst[d[i]] = t[i];
		else dlst[d[i]] = max(dlst[d[i]], t[i]);
	}
	vector<pair<int, int>> tlst, tmp;
	for (const auto& pi : dlst) tlst.emplace_back(pi.second, pi.first);
	sort(tlst.rbegin(), tlst.rend());
	int m = tlst.size();
	tmp.push_back(tlst[0]);
	rep3(i, 1, m) if (tlst[i].first != tlst[i-1].first) tmp.push_back(tlst[i]);
	swap(tlst, tmp);
	tlst.emplace_back(0, 0);
	m = tlst.size();
	function<bool(ll)> check = [&](ll cval) {
		ll hval = h, ccval = cval;
		set<int> dst;
		set<pair<ll, int>> ast;
		rep(i, m) {
			if ((ll)tlst[i].first < ccval) ast.emplace((ll)tlst[i].first*tlst[i].second, tlst[i].second);
			else dst.insert(tlst[i].second);
		}
		rep(i, m) {
			ll tval = ccval - tlst[i].first, pval = ccval;
			ll bval = dst.empty() ? -LINF : (ll)*dst.rbegin(), aval = ast.empty() ? -LINF : (ll)ast.rbegin()->first;
			if (bval==-LINF || aval==-LINF) {
				if (bval != -LINF) {
					hval -= bval * (pval+tlst[i].first+1) * tval / 2;
				}
				else {
					hval -= aval * tval;
				}
			}
			else {
				ll sval = bval * (pval+tlst[i].first+1) * tval / 2;
				if (sval < aval) {
					if (bval*pval > aval) {
						ll tval2 = aval / bval;
						hval -= bval * (pval+tval2+1) * (pval-tval2) / 2 + aval * (tval2-tlst[i].first);
					}
					else {
						hval -= sval;
					}
				}
				else hval -= aval * tval;
			}
			if (hval <= 0) return true;
			ast.erase({ (ll)tlst[i].first*tlst[i].second, tlst[i].second });
			dst.insert(tlst[i].second);
			ccval = tlst[i].first;
		}
		return false;
	};
	ll lval = 0, rval = h;
	while (rval-lval > 1) {
		ll cval = rval - (rval-lval) / 2;
		if (check(cval)) rval = cval;
		else lval = cval;
	}
	cout << rval << endl;
	return 0;
}
