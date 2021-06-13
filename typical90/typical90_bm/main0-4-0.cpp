#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答、わからない

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
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

int main() {
    int r, g, b, k;
    cin >> r >> g >> b >> k;
    int x, y, z;
    cin >> x >> y >> z;
    combination cb(max({k,x,y,z,r,g,b})+1);
    mint res = 0;
    rep3r(i, max({0,k-z,k-b}), x+1) {
        int bi = k - i;
        //if (bi>k || bi>y || bi>z || bi>b || bi<0) continue;
        mint val = 0;
        rep3r(j, max({0,bi,k-min(r,z-bi)}), min({bi+g,y,k})+1) {
            int gi = i + j - k;
            int ri = k - bi - gi;
            //if (ri>k || ri>x || ri>z || ri>r || ri<0) continue;
            //if (gi>k || gi>x || gi>y || gi>g || gi<0) continue;
            //if (gi==k || ri==k) val += cb(g,gi) * cb(r,ri) / 2;
            val += cb(g,gi) * cb(r,ri);
        }
        //if (bi == k) res += val * cb(b, bi) / 2;
        res += val * cb(b, bi);
    }
    cout << res.x << endl;
    return 0;
}
