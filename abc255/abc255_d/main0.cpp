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
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vector<ll> s(n+1);
	rep(i, n) s[i+1] += s[i] + a[i];
	rep(i, q) {
		ll x;
		cin >> x;
		int lid = upper_bound(all(a), x) - a.begin();
		ll lval = lid * x - s[lid], rval = (s[n] - s[lid]) - (n-lid) * x;
		cout << (lval+rval) << endl;
	}
	return 0;
}
