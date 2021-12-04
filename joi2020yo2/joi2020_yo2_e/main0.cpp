#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番,未完成

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

const string rsp = "RSP";

int n;
string e;
map<tuple<int, int, int>, mint> memo;
mint calc(int l, int r, int t) {
	if (memo.find({l,r,t}) != memo.end()) return memo[{l, r, t}];
	if (r-l <= 0) return (memo[{l, r, t}] = 0);
	else if (r-l == 1) {
		if (e[l]!='?' && rsp.find(e[l])==string::npos) return (memo[{l, r, t}] = 0);
		if (e[l]==rsp[t] || e[l]=='?') return (memo[{l, r, t}] = 1);
	}
	else {
		vector<mint> res(3, mint(1));
		int lid = l, rid = l;
		while (lid < r) {
			int pcnt = 0;
			if (e[l] == '(') {
				++pcnt;
				while (rid<r && pcnt>0) {
					if (e[rid] == '(') ++pcnt;
					else if (e[rid] == ')') --pcnt;
					++rid;
				}
				vector<mint> tres(3, mint(0));
				rep(i, 3) tres[i] = calc(lid+1, rid-1, i);

			}

		}
	}
}

int main() {
	char a;
	cin >> n >> e >> a;
	int aid = -1;
	rep(i, 3) if (a == rsp[i]) aid = i;
	cout << calc(0, n, aid) << endl;
	return 0;
}
