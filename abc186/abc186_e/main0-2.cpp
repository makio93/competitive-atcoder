// 終了後,自力WA

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

using mint = modint;
ll mod = 0;

// auto mod int
struct mint2 {
    ll x; // typedef long long ll;
    mint2(ll x=0):x((x%mod+mod)%mod){}
    mint2 operator-() const { return mint2(-x);}
    mint2& operator+=(const mint2 a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint2& operator-=(const mint2 a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint2& operator*=(const mint2 a) { (x *= a.x) %= mod; return *this;}
    mint2 operator+(const mint2 a) const { return mint2(*this) += a;}
    mint2 operator-(const mint2 a) const { return mint2(*this) -= a;}
    mint2 operator*(const mint2 a) const { return mint2(*this) *= a;}
    mint2 pow(ll t) const {
        if (!t) return 1;
        mint2 a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint2 inv() const { return pow(mod-2);}
    mint2& operator/=(const mint2 a) { return *this *= a.inv();}
    mint2 operator/(const mint2 a) const { return mint2(*this) /= a;}
};
istream& operator>>(istream& is, mint2& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint2& a) { return os << a.x; }

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        ll n, s, k;
        cin >> n >> s >> k;
        if (gcd(n, k) != 1) {
            if (n%k == 0) {
                if ((n-s)%k == 0) cout << ((n-s) / k) << endl;
                else cout << -1 << endl;
            }
            else {
                mod = n;
                mint2 val(n-s);
                val /= k;
                cout << val << endl;
            }
        }
        else {
            mint::set_mod(n);
            mint val = n - s;
            val /= k;
            cout << val.val() << endl;
        }
    }
    return 0;
}
