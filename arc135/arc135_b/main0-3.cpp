// 終了後,自力考察,AC

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
	int n;
	cin >> n;
	vector<int> s(n);
	rep(i, n) cin >> s[i];
	vector<ll> a(n+2);
	rep(i1, 3) {
		for (int i=i1; i<n-1; i+=3) a[i+3] = a[i] + (s[i+1] - s[i]);
		ll mval = (ll)(1e16);
		for (int i=i1; i<n+2; i+=3) mval = min(mval, a[i]);
		for (int i=i1; i<n+2; i+=3) a[i] -= mval;
	}
	unordered_set<ll> sub;
	rep(i, n) sub.insert(s[i]-(a[i]+a[i+1]+a[i+2]));
	if ((int)(sub.size())>1 || *sub.begin()<0) cout << "No" << endl;
	else {
		ll add = *sub.begin();
		for (int i=0; i<n+2; i+=3) a[i] += add;
		cout << "Yes" << endl;
		rep(i, n+2) printf("%lld%c", a[i], (i<n+1?' ':'\n'));
	}
	return 0;
}
