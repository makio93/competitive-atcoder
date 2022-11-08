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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int am = *max_element(all(a));
	fenwick_tree<int> acnt(am+2);
	fenwick_tree<ll> asum(am+2);
	vector<mint> avals(n+1);
	rep(i, n) {
		avals[i+1] += (mint)(asum.sum(a[i]+1, am+1)) * 2;
		avals[i+1] += acnt.sum(0, a[i]+1) * (mint)(a[i]) * 2;
		avals[i+1] += a[i];
		asum.add(a[i], a[i]);
		acnt.add(a[i], 1);
		avals[i+1] += avals[i];
	}
	rep3(i, 1, n+1) avals[i] /= (mint)(i) * i;
	rep3(i, 1, n+1) cout << avals[i].val() << endl;
	return 0;
}
