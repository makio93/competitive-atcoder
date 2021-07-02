#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答、WA

using ull = unsigned long long;

const ull mod = (ll)(1e9) + 7;
struct mint {
	ull x;
	mint(ull x=0) : x((x%mod+mod)%mod) {}
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
	mint pow(ull t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
	// for prime mod
	mint inv() const { return pow(mod-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
	ull l, r;
	cin >> l >> r;
	ull ten = 1;
	int clen = 1;
	mint res = 0;
	while (clen<=18 && ten*10<=l) {
		ten *= 10;
		++clen;
	}
	while (ten < r) {
		ull li = max(ten, l), ri = min(ten*10, r);
		res += (mint)(li + ri - 1) * (ri - li) / 2 * clen;
		if (r < ten*10) res += (mint)r * clen;
		else if (r == ten*10) res += (mint)r * (clen + 1);
		ten *= 10;
		++clen;
	}
	cout << res << endl;
	return 0;
}
