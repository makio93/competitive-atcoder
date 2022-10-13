// 本番中に作成、不完全

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

ll op(ll a, ll b) { return (a + b); }
ll e() { return 0LL; }

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	map<ll, int> acnt, bcnt;
	rep(i, n) acnt[a[i]+i]++;
	rep(i, n) bcnt[b[i]+i]++;
	bool ok = ((acnt.size()) == (bcnt.size()));
	if (ok) {
		auto aitr=acnt.begin(), bitr=bcnt.begin();
		while (aitr!=acnt.end() && bitr!=bcnt.end()) {
			if ((*aitr) != (*bitr)) ok = false;
			if (!ok) break;
			++aitr; ++bitr;
		}
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	segtree<ll, op, e> seg(n+1);
	map<ll, set<int>> aval;
	rep(i, n) aval[a[i]+i].insert(i);
	vector<ll> b2(n);
	rep(i, n) b2[i] = b[i] + i;
	ll res = 0;
	rep(i, n) {
		if (a[i] == b[i]) {
			aval[b2[i]].erase(i);
			continue;
		}
		int id = *(aval[b2[i]].begin());
		int id2 = id + seg.prod(0, id+1);
		res += abs(id2-i);
		aval[b2[i]].erase(id);
		int sid1 = seg.get(i), sid2 = seg.get(id+1);
		int sid3 = seg.get(i+1), sid4 = seg.get(id);
		if (i < id) {
			seg.set(i, sid1+1);
			seg.set(id+1, sid2-1);
		}
		else {
			seg.set(i+1, sid3+1);
			seg.set(id, sid4-1);
		}
	}
	cout << res << endl;
	return 0;
}
