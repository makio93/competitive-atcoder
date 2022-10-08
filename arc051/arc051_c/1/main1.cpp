// 学習1回目,解説AC

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

ll modpow(ll a, ll b) {
    ll p = 1, q = a;
    rep(i, 63) {
        if (b & (1LL<<i)) p = p * q % mod;
        q = q * q % mod;
    }
    return p;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> ai(n);
    rep(i, n) cin >> ai[i];
    if (a == 1) sort(all(ai));
    else {
        ll mval = *max_element(all(ai));
        while (b > 0) {
            auto litr = min_element(all(ai));
            if ((*litr)*a > mval) break;
            *litr *= a;
            --b;
        }
        sort(all(ai));
        if (b > 0) {
            int q = b / n, r = b % n;
            rep(i, r) ai[i] *= a;
            sort(all(ai));
            rep(i, n) ai[i] = ai[i] % mod * modpow(a, q) % mod;
        }
        else rep(i, n) ai[i] %= mod;
    }
    rep(i, n) cout << ai[i] << endl;
    return 0;
}
