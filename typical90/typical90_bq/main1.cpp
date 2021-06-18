#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説を見てから、改めて実装、AC

const ll mod = (ll)(1e9) + 7;
ll mpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b%2 == 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        if (n == 1) cout << k << endl;
        else cout << 0LL << endl;
    }
    else if (n == 1) cout << (k%mod) << endl;
    else if (n == 2) cout << (k*(k-1)%mod) << endl;
    else cout << (k*(k-1)%mod*mpow(k-2,n-2)%mod) << endl;
    return 0;
}
