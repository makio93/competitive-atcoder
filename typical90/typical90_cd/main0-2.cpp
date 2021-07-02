#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

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
	ll l, r;
	cin >> l >> r;
	int llen = to_string(l).length(), rlen = to_string(r).length();
	mint res = 0;
	if (llen == rlen) res += mint(r+l) * (r-l+1) / 2 * llen;
	else {
		mint l2 = mint(10).pow(llen), r2 = mint(10).pow(rlen-1);
		res += ((mint)l+l2-1) * (l2-l) / 2 * llen;
		res += ((mint)r+r2) * ((mint)r-r2+1) / 2 * rlen;
		rep3(li, llen, rlen-1) {
			mint tl = mint(10).pow(li), tr = mint(10).pow(li+1);
			res += ((mint)tl+tr-1) * (tr-tl) / 2 * (li+1);
		}
	}
	cout << res << endl;
	return 0;
}
