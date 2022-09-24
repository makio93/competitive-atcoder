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

const int INF = (int)(1e9);

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	map<ll, set<int>> avals;
	rep(i, n) avals[a[i]].insert(i);
	ll sval = 0, kval = k;
	unordered_set<int> zeros;
	set<int> exists;
	rep(i, n) exists.insert(i);
	for (auto itr=avals.begin(); itr!=avals.end(); ++itr) {
		int tlen = exists.size();
		ll tval = tlen * (itr->first-sval);
		if (kval > tval) {
			sval = itr->first;
			for (const int& aid : itr->second) {
				exists.erase(aid);
				zeros.insert(aid);
			}
			kval -= tval;
		}
		else {
			ll pval = kval / tlen, qval = kval % tlen;
			int qcnt = 0;
			for (const int& aid : exists) {
				a[aid] -= pval;
				if (qcnt < qval) a[aid]--;
				++qcnt;
			}
			kval = 0;
			break;
		}
	}
	for (const int& id : zeros) a[id] = 0;
	for (const int& id : exists) a[id] -= sval;
	rep(i, n) cout << a[i] << ' ';
	cout << endl;
	return 0;
}
