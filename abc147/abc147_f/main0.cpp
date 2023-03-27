// バチャ本番WA

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

const int INF = (int)(1e9);

int main() {
	int n, x, d;
	cin >> n >> x >> d;
	if (d < 0) {
		x *= -1;
		d *= -1;
	}
	if (d==0 && x<0) x *= -1;
	ll res = 0;
	if (d>0 && x>0) {
		res = 1 + (ll)n * (n+1) / 2;
	}
	else if (x==0 && d>0) {
		res = (ll)(n-1) * n / 2;
	}
	else if (x>0 && d==0) {
		res = n + 1;
	}
	else if (x==0 && d==0) {
		res = 1;
	}
	else {
		map<int, set<pair<ll, bool>>> md;
		ll val = 0;
		rep(i, n) {
			val += x;
			ll nval = val + (ll)(n-1-i) * d;
			int mval = (d - abs(val) % d) % d;
			if (md.find(mval) == md.end()) {
				md[mval].emplace(val, false);
				md[mval].emplace(nval, true);
				res += (n-i);
			}
			else {
				auto litr = md[mval].lower_bound({ val, false }), ritr = md[mval].lower_bound({ nval, true });
				if (litr == ritr) {
					if (litr==md[mval].end() || !litr->second) {
						if (ritr==md[mval].end() || ritr->first>nval) {
							res += (nval - val) / d + 1;
							md[mval].emplace(val, false);
							md[mval].emplace(nval, true);
						}
						else {
							res += (nval - val) / d;
							md[mval].erase({nval, false});
							md[mval].emplace(val, false);
						}
					}
				}
				else {
					if (!litr->second) res += (litr->first - val) / d;
					for (auto titr=litr; next(titr)!=ritr; ++titr) {
						if (titr->second) res += (next(titr)->first - titr->first) / d - 1;
					}
					if (ritr==md[mval].end() || !ritr->second) {
						res += (nval-prev(ritr)->first) / d;
						if (ritr!=md[mval].end() && ritr->first==nval) --res;
					}
					litr = md[mval].emplace(val, false).first;
					if (val!=nval && md[mval].find({val, true})!=md[mval].end()) {
						--litr;
						md[mval].erase({ val, false });
						md[mval].erase({ val, true });
					}
					ritr = md[mval].emplace(nval, true).first;
					if (val!=nval && md[mval].find({nval, false})!=md[mval].end()) {
						++ritr;
						md[mval].erase({ nval, false });
						md[mval].erase({ nval, true });
					}
					while (next(litr) != ritr) md[mval].erase(next(litr));
				}
			}
		}
		if (!md[0].empty()) {
			if (md[0].find({0LL, false})==md[0].end() && md[0].find({0LL, true})==md[0].end()) {
				auto titr = md[0].lower_bound({0LL, true});
				if (titr==md[0].end() || !titr->second) ++res;
			}
		}
	}
	cout << res << endl;
	return 0;
}
