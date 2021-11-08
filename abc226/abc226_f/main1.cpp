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

// 解説AC

const ll mod = 998244353LL;
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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

vector<mint> fact, ifact;
void init(int n) {
	fact = vector<mint>(n+1);
	ifact = vector<mint>(n+1);
	fact[0] = 1;
	for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
	ifact[n] = fact[n].inv();
	for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
}

mint res = 0;
unordered_map<int, int> lf;
int n, k;

void dfs(int d=0, int v=1) {
	if (d == n) {
		mint val = fact[n];
		for (auto pi : lf) {
			val *= fact[pi.first-1].pow(pi.second);
			val /= fact[pi.first].pow(pi.second) * fact[pi.second];
		}
		ll lval = -1;
		for (auto pi : lf) {
			if (lval == -1) lval = pi.first;
			else lval = lcm(lval, pi.first);
		}
		val *= mint(lval).pow(k);
		res += val;
	}
	else {
		rep3(i, v, n-d+1) {
			lf[i]++;
			dfs(d+i, i);
			lf[i]--;
			if (lf[i] == 0) lf.erase(i);
		}
	}
}

int main() {
	cin >> n >> k;
	init(n);
	dfs();
	cout << res << endl;
	return 0;
}
