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

// 本番WA

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

struct fraction {
	ll num, den;
	fraction(ll a, ll b) : num(a), den(b) {}
};

void fdiv(fraction& f) {
	if (f.num == 0) f.den = 1;
	else {
		ll gval = gcd(f.num, f.den);
		f.num /= gval; f.den /= gval;
	}
}

ll fcomp(fraction a, fraction b) {
	fdiv(a); fdiv(b);
	ll dval = lcm(a.den, b.den);
	ll anum = a.num * (dval / a.den), bnum = b.num * (dval / b.den);
	return (anum - bnum);
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	pair<fraction, int> mval = { fraction(0, 1), -1 };
	int fid = n;
	repr(i, n) if ((ll)s >= (ll)m*(n-i)) fid = i;
	ll nsum = 0, dsum = 0;
	repr(i, n) {
		nsum += a[i]; ++dsum;
		fraction nfrac(nsum, dsum);
		if (fcomp(nfrac, mval.first) >= 0) mval = { nfrac, i };
	}
	double res = 0.0;
	if (mval.second < fid) {
		double dsub = s / (double)(n-mval.second);
		rep3r(i, mval.second, n) res += a[i] * dsub;
	}
	else {
		pair<fraction, int> mval2 = { fraction(0, 1), -1 };
		ll nsum2 = 0, dsum2 = 0;
		rep3r(i, fid, n) {
			nsum2 += a[i]; ++dsum2;
		}
		repr(i, fid) {
			fraction nfrac2(nsum2, dsum2);
			if (fcomp(nfrac2, mval2.first) >= 0) mval2 = { nfrac2, i };
		}
		rep3r(i, fid, n) res += (double)(a[i] * (ll)m);
		double dsub2 = (s-(ll)(n-fid)*m) / (double)(fid-mval2.second);
		rep3r(i, mval2.second, fid) res += a[i] * dsub2;
	}
	printf("%.14f\n", res);
	return 0;
}
