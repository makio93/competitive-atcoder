// 本番WA

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
	vector<bool> used(n+1);
	rep3(i, 2, n+1) {
		if (!used[i]) {
			for (int j=i*2; j<=n; j+=i) used[j] = true;
		}
	}
	vector<int> plst;
	rep3(i, 2, n+1) if (!used[i]) plst.push_back(i);
	unordered_map<int, int> pid;
	int m = plst.size();
	rep(i, m) pid[plst[i]] = i;
	map<ll, int> pcnt;
	pcnt[0]++;
	ll res = 1;
	rep3(i, 2, n+1) {
		int val = i;
		mint tval = 0;
		for (int j=2; j*j<=val; ++j) if (val%j == 0) {
			int tcnt = 0;
			while (val%j == 0) {
				val /= j;
				++tcnt;
			}
			if (tcnt%2 == 1) tval += mint(2).pow(pid[j]);
		}
		if (val > 1) tval += mint(2).pow(pid[val]);
		if (pcnt.find(tval.x) != pcnt.end()) res += pcnt[tval.x] * 2;
		pcnt[tval.x]++;
		res++;
	}
	cout << res << endl;
	return 0;
}
