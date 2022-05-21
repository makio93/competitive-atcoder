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

const ll mod = (ll)(1e9) + 7;
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
	mint inv() const { return pow(mod-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
	int n, b;
	ll a;
	cin >> n >> a >> b;
	vector<ll> ai(n);
	rep(i, n) cin >> ai[i];
	sort(all(ai));
	if (a == 1) {
		rep(i, n) cout << (ai[i]%mod) << endl;
		return 0;
	}
	ll mval = ai[n-1];
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	rep(i, n) pq.push(ai[i]);
	while (b>0 && pq.top()<mval) {
		auto val = pq.top(); pq.pop();
		pq.push(val*a);
		--b;
	}
	vector<ll> tmp;
	while (!pq.empty()) {
		tmp.push_back(pq.top());
		pq.pop();
	}
	sort(all(tmp));
	if (b == 0) {
		rep(i, n) cout << (tmp[i]%mod) << endl;
		return 0;
	}
	vector<mint> ma(n);
	rep(i, n) ma[i] = tmp[i];
	rep(i, n) ma[i] = ma[i] * mint(a).pow(b/n);
	rep(i, b%n) ma[i] *= a;
	vector<mint> res;
	rep3(i, b%n, n) res.push_back(ma[i]);
	rep(i, b%n) res.push_back(ma[i]);
	rep(i, n) cout << res[i] << endl;
	return 0;
}
