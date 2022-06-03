// 復習1回目,自力,TLE

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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, int> spcnt, apcnt;
	vector<unordered_map<int, int>> pcnt(n);
	rep(i, n) {
		int aval = a[i];
		for (int j=2; j*j<=aval; ++j) if (aval%j == 0) {
			while (aval%j == 0) {
				aval /= j;
				pcnt[i][j]++;
				spcnt[j]++;
			}
		}
		if (aval > 1) {
			pcnt[i][aval]++;
			spcnt[aval]++;
		}
	}
	rep(i, n) {
		for (auto pi : spcnt) {
			if (apcnt.find(pi.first) == apcnt.end()) apcnt[pi.first] = pi.second - pcnt[i][pi.first];
			else apcnt[pi.first] = min(apcnt[pi.first], pi.second-pcnt[i][pi.first]);
		}
	}
	mint am = 1, res = 0;
	rep(i, n) am *= a[i];
	rep(i, n) res += am / a[i];
	for (auto pi : apcnt) res /= mint(pi.first).pow(pi.second);
	cout << res << endl;
	return 0;
}
