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
ll op(ll a, ll b) { return max(a, b); }
ll e() { return numeric_limits<ll>::min(); }

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	segtree<ll, op, e> st(n+1);
	st.set(0, 0);
	rep(i, n) st.set(h[i], st.prod(0, h[i]) + a[i]);
	cout << st.all_prod() << endl;
	return 0;
}
