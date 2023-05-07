// 学習3回目,解説AC1

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
    vector<int> ord(n+1, -1);
    vector<ll> sum(n+1);
    int li = -1, ri = -1;
    ord[0] = 0;
    rep(i, n) {
        sum[i+1] = sum[i] + a[sum[i]%n];
        if (ord[sum[i+1]%n] != -1) {
            ri = i+1;
            li = ord[sum[i+1]%n];
            break;
        }
        ord[sum[i+1]%n] = i+1;
    }
    ll res = 0;
    if (k < ri) res = sum[k];
    else {
        int p = ri - li, r = (k-li) % p;
        ll q = (k-li) / p;
        res = sum[li] + (sum[ri]-sum[li]) * q + (sum[li+r]-sum[li]);
    }
    cout << res << endl;
    return 0;
}
