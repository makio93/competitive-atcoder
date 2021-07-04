#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<pair<int, int>> alst(n);
	rep(i, n) alst[i] = { a[i], i };
	sort(all(alst));
	ll q = k / n, r = k % n;
	vector<ll> ans(n);
	rep(i, n) ans[alst[i].second] = q + (ll)((i < (int)r) ? 1LL : 0LL);
	rep(i, n) cout << ans[i] << endl;
	return 0;
}
