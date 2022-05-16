// 復習1回目,解説AC1

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

const int INF = (int)(1e9);

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n+2);
    vector<int> ord(n, -1);
    ord[0] = 0;
    int l = -1, r = -1;
    rep(i, n+1) {
        s[i+1] = s[i] + a[s[i]%n];
        if (ord[s[i+1]%n] != -1) {
            l = ord[s[i+1]%n];
            r = i+1;
            break;
        }
        ord[s[i+1]%n] = i+1;
    }
    ll res = 0;
    if (k <= (ll)l) res = s[k];
    else {
        int p = r - l;
        ll q = (k-(l+1)) / p;
        int b = (int)((k-(l+1)) % p);
        ll x = s[r] - s[l];
        res = s[l+b+1] + x*q;
    }
    cout << res << endl;
    return 0;
}
