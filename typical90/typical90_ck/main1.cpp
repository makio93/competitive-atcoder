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

template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0):n(n),d(n+1) {}
	void add(int i, T x=1) {
		for (i++; i <= n; i += i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};

int compress(vector<int>& x1) {
	int n1 = x1.size();
	set<int> st;
	for (int xi : x1) st.insert(xi);
	vector<int> arr;
	for (auto itr=st.begin(); itr!=st.end(); ++itr) { arr.push_back(*itr); }
	rep(i, n1) x1[i] = lower_bound(all(arr), x1[i]) - arr.begin();
	return (int)(arr.size())-1;
}

int main() {
	int n; ll k;
	cin >> n >> k;
	vector<int> a(n), cl(n);
	rep(i, n) cin >> a[i];
	int alen = compress(a);
	BIT<int> d(alen+5);
	int l = n-1;
	d.add(a[l], 1);
	ll s = 0;
	repr(r, n) {
		while (l-1>=0 && s+d.sum(a[l-1]-1)<=k) {
			d.add(a[l-1], 1);
			--l;
			s += d.sum(a[l-1]-1);
		}
		cl[r] = l;
		d.add(a[r], -1);
		s -= d.sum(alen+3) - d.sum(a[r]) + 1;
	}
	vector<mint> dp(n+1), dp2(n+1);
	dp[0] = 1; dp2[0] = 1;
	rep3(i, 1, n+1) {
		if (cl[i-1] == 0) dp[i] += dp2[i-1];
		else dp[i] += dp2[i-1] - dp2[cl[i-1]-1];
		dp2[i] += dp[i] + dp2[i-1];
	}
	cout << dp[n] << endl;
	return 0;
}
