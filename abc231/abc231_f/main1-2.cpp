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

// 解説AC2,手元でもコンパイル可能な解答

ll op(ll v1, ll v2) { return v1+v2; };
ll e() { return 0LL; };

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	function<void(vector<int>&)> comp = [](vector<int>& vec) -> void {
		vector<int> tmp;
		for (int val : vec) tmp.push_back(val);
		sort(all(tmp));
		tmp.erase(unique(all(tmp)), tmp.end());
		for (int& val : vec) val = lower_bound(all(tmp), val) - tmp.begin();
	};
	comp(a);
	comp(b);
	vector<pair<int, int>> vlst(n);
	rep(i, n) vlst[i] = { a[i], -b[i] };
	sort(all(vlst));
	rep(i, n) vlst[i].second *= -1;
	segtree<ll, op, e> seg(n);
	ll res = 0;
	rep(i, n) {
		int tlen = 1;
		while (i+1<n && vlst[i+1]==vlst[i]) { ++i; ++tlen; }
		seg.set(vlst[i].second, seg.get(vlst[i].second)+tlen);
		res += seg.prod(vlst[i].second, n) * tlen;
	}
	cout << res << endl;
	return 0;
}
