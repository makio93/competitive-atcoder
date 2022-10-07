// 学習2回目,解説AC1

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

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n+1);
    vector<int> ord(n, -1);
    s[0] = 0;
    ord[0] = 0;
    int li = -1, ri = -1;
    rep(i, n) {
        s[i+1] = s[i] + a[s[i]%n];
        if (ord[s[i+1]%n] != -1) {
            ri = i + 1;
            li = ord[s[i+1]%n];
            break;
        }
        ord[s[i+1]%n] = i+1;
    }
    ll res = 0;
    if (k <= (ll)ri) res = s[k];
    else {
        int p = ri - li, r = (k-li) % p;
        ll sval = s[ri] - s[li], q = (k-li) / p;
        res = s[li+r] + sval * q;
    }
    cout << res << endl;
    return 0;
}
