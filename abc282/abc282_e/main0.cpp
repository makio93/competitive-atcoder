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
ll mod = 0;
struct mint {
	ll x;
	mint(ll x=0) : x((x%mod+mod)%mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	mod = m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<tuple<ll, int, int>> vals;
	rep(i, n) rep3(j, i+1, n) vals.emplace_back((mint(a[i]).pow(a[j])+mint(a[j]).pow(a[i])).x, i, j);
	sort(vals.rbegin(), vals.rend());
	dsu d(n);
	ll res = 0;
	int cnt = 0, vlen = vals.size();
	rep(i, vlen) {
		if (d.same(get<1>(vals[i]), get<2>(vals[i]))) continue;
		res += get<0>(vals[i]);
		d.merge(get<1>(vals[i]), get<2>(vals[i]));
		++cnt;
		if (cnt >= n-1) break;
	}
	cout << res << endl;
	return 0;
}
