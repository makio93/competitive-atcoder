// 自力AC

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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	int mval = *max_element(all(a));
	vector<int> acnt(mval+1);
	int blen = (int)(ceil(sqrt(q)) + 0.5);
	vector<int> l(q), r(q);
	rep(i, q) {
		cin >> l[i] >> r[i];
		l[i]--;
	}
	vector<int> qlst(q);
	iota(all(qlst), 0);
	sort(all(qlst), [&](int& li, int& ri) -> bool {
		if (l[li]/blen != l[ri]/blen) return l[li] < l[ri];
		else return r[li] < r[ri];
	});
	ll res = 0;
	int li = 0, ri = 0;
	auto cb3 = [](int val) -> ll {
		if (val < 3) return 0;
		return (ll)val * (val-1) * (val-2) / 6;
	};
	auto add = [&](int id) -> void {
		res -= cb3(acnt[a[id]]);
		acnt[a[id]]++;
		res += cb3(acnt[a[id]]);
	};
	auto del = [&](int id) -> void {
		res -= cb3(acnt[a[id]]);
		acnt[a[id]]--;
		res += cb3(acnt[a[id]]);
	};
	vector<ll> ans(q);
	rep(i, q) {
		while (ri < r[qlst[i]]) {
			add(ri);
			++ri;
		}
		while (li < l[qlst[i]]) {
			del(li);
			++li;
		}
		while (li > l[qlst[i]]) {
			--li;
			add(li);
		}
		while (ri > r[qlst[i]]) {
			--ri;
			del(ri);
		}
		ans[qlst[i]] = res;
	}
	rep(i, q) cout << ans[i] << endl;
	return 0;
}
