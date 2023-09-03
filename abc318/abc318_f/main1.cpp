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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), l(n);
	rep(i, n) cin >> x[i];
	rep(i, n) cin >> l[i];
	function<bool(ll)> check = [&](ll ki) {
		vector<ll> b(n);
		rep(i, n) b[i] = abs(x[i]-ki);
		sort(all(b));
		rep(i, n) if (b[i] > l[i]) return false;
		return true;
	};
	vector<ll> kl;
	rep(i, n) rep(j, n) {
		kl.push_back(x[i]+l[j]);
		kl.push_back(x[i]-l[j]-1);
	}
	sort(all(kl));
	kl.erase(unique(all(kl)), kl.end());
	int m = kl.size();
	ll res = 0;
	rep3(i, 1, m) if (check(kl[i])) res += kl[i] - kl[i-1];
	cout << res << endl;
	return 0;
}
