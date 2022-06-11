// 復習2回目,解説AC

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
    vector<int> c = a, d = b;
    sort(all(c));
    sort(all(d));
    if (c != d) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, n-1) if (c[i+1] == c[i]) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int& vi : a) vi = lower_bound(all(c), vi) - c.begin();
    for (int& vi : b) vi = lower_bound(all(c), vi) - c.begin();
    vector<int> pa(n), pb(n), to(n);
    rep(i, n) pa[a[i]] = i;
    rep(i, n) pb[b[i]] = i;
    rep(i, n) to[pa[i]] = pb[i];
    ll rcnt = 0;
    fenwick_tree<int> fw(n);
    repr(i, n) {
        rcnt += fw.sum(0, to[i]);
        fw.add(to[i], 1);
    }
    if (rcnt%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
