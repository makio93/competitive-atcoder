// 復習2回目,自力AC

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
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    rep(i, n) mval = max(mval, b[i]);
    vector<int> acnt(mval+1), bcnt(mval+1);
    rep(i, n) acnt[a[i]]++;
    rep(i, n) bcnt[b[i]]++;
    bool res = true;
    rep(i, mval+1) if (acnt[i] != bcnt[i]) res = false;
    if (!res) {
        cout << "No" << endl;
        return 0;
    }
    bool ok = false;
    rep(i, mval+1) if (acnt[i] > 1) ok = true;
    if (ok) {
        cout << "Yes" << endl;
        return 0;
    }
    fenwick_tree<int> at(mval+1), bt(mval+1);
    ll aval = 0, bval = 0;
    repr(i, n) {
        aval += (ll)at.sum(0, a[i]);
        at.add(a[i], 1);
    }
    repr(i, n) {
        bval += (ll)bt.sum(0, b[i]);
        bt.add(b[i], 1);
    }
    if (aval%2 == bval%2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
