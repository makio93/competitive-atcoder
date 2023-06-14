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

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) {
        cin >> b[i];
        b[i]--;
    }
    auto ta = a, tb = b;
    sort(all(ta));
    sort(all(tb));
    if (ta != tb) {
        cout << "No" << endl;
        return 0;
    }
    unordered_set<int> ast(all(a));
    if ((int)(ast.size()) < n) {
        cout << "Yes" << endl;
        return 0;
    }
    function<ll(vector<int>&)> rcnt = [&](vector<int>& vlst) {
        fenwick_tree<int> ft(n);
        ll rval = 0;
        repr(i, n) {
            rval += ft.sum(0, vlst[i]);
            ft.add(vlst[i], 1);
        }
        return rval;
    };
    ll aval = rcnt(a), bval = rcnt(b);
    if (aval%2 == bval%2) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}
