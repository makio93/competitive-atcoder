// 復習1,解説1

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
	rep(i, q) { cin >> l[i] >> r[i]; l[i]--; }
	int bk = max(1, n/(int)(round(sqrt((double)q))));
	vector<int> qid(q);
	iota(all(qid), 0);
	sort(all(qid), [&](int i, int j){
		if (r[i]/bk != r[j]/bk) return r[i]/bk < r[j]/bk;
		else return l[i] < l[j];
	});
	int vl = 0, vr = 0, res = 0;
	vector<int> cnt(n);
	auto add = [&](int id, int di=1) -> void {
		res -= cnt[a[id]] / 2;
		cnt[a[id]] += di;
		res += cnt[a[id]] / 2;
	};
	vector<int> ans(q);
	rep(i, q) {
		while (vr < r[qid[i]]) add(vr), ++vr;
		while (vl < l[qid[i]]) add(vl, -1), ++vl;
		while (vl > l[qid[i]]) --vl, add(vl);
		while (vr > r[qid[i]]) --vr, add(vr, -1);
		ans[qid[i]] = res;
	}
	rep(i, q) printf("%d\n", ans[i]);
	return 0;
}
