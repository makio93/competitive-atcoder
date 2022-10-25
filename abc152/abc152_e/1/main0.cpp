// 学習1回目,自力AC

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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll mod = (ll)(1e9) + 7;
ll modpow(ll a, ll b, ll m) {
    ll p = 1, q = a;
    rep(i, 63) {
        if (b & (1LL<<i)) p = p * q % m;
        q = q * q % m;
    }
    return p;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<unordered_map<int, int>> plst(n);
    unordered_map<int, int> lp;
    rep(i, n) {
        int ai = a[i];
        for (int j=2; j*j<=ai; ++j) {
            while (ai%j == 0) {
                plst[i][j]++;
                ai /= j;
            }
        }
        if (ai > 1) plst[i][ai]++;
        for (const auto& pi : plst[i]) {
            if (lp.find(pi.first) == lp.end()) lp[pi.first] = pi.second;
            else chmax(lp[pi.first], pi.second);
        }
    }
    ll lval = 1;
    for (const auto& pi : lp) rep(i, pi.second) lval = lval * pi.first % mod;
    ll res = 0;
    rep(i, n) {
        ll val = lval;
        for (const auto& pi : plst[i]) {
            ll tval = 1;
            rep(j, pi.second) tval = tval * pi.first % mod;
            val = val * modpow(tval, mod-2, mod) % mod;
        }
        res = (res + val) % mod;
    }
    cout << res << endl;
    return 0;
}
