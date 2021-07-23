#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC(解答例を見ないで作成)

unordered_map<ll, ll> memo;
ll f(ll n) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 0LL) return (memo[0] = 0);
    ll ki = 1;
    while (ki <= n) {
        bool ok = false;
        for (ll i=ki; i<=3*ki; ++i) {
            if (n-i < 0LL) break;
            if ((n-i)%10 == 0LL) {
                ll rval = f((n-i)/10);
                if (rval <= ki) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) return (memo[n] = ki);
        ++ki;
    }
    return (memo[n] = n);
}

int main() {
    int t;
    cin >> t;
    rep(i0, t) {
        ll n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}
