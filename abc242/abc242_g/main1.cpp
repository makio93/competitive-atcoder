// 解説AC

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

int main() {
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	cin >> q;
	vector<int> l(q), r(q);
	rep(i, q) {
		cin >> l[i] >> r[i];
		l[i]--;
	}
	int b = max(1, (int)(n/sqrt(q)));
	vector<int> qis(q);
	iota(all(qis), 0);
	sort(all(qis), [&](int i, int j) {
		int di = l[i]/b, dj = l[j]/b;
		if (di == dj) return r[i] < r[j];
		else return l[i] < l[j];
	});
	vector<int> ans(q);
	int lp = 0, rp = 0, res = 0;
	vector<int> cnt(n);
	auto add = [&](int val, int sub=1) -> void {
		res -= cnt[a[val]] / 2;
		cnt[a[val]] += sub;
		res += cnt[a[val]] / 2;
	};
	rep(i, q) {
		while (rp < r[qis[i]]) add(rp), ++rp;
		while (lp < l[qis[i]]) add(lp, -1), ++lp;
		while (lp-1 >= l[qis[i]]) --lp, add(lp);
		while (rp-1 >= r[qis[i]]) --rp, add(rp, -1);
		ans[qis[i]] = res;
	}
	rep(i, q) printf("%d\n", ans[i]);
	return 0;
}
