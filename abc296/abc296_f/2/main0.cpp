// 学習2回目,自力AC

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
    ta.erase(unique(all(ta)), ta.end());
    if ((int)(ta.size()) < n) {
        cout << "Yes" << endl;
        return 0;
    }
    vector<pair<int, int>> ba(n);
    rep(i, n) ba[i] = { b[i], a[i] };
    sort(all(ba));
    vector<int> na(n);
    rep(i, n) na[i] = ba[i].second;
    int mx = *max_element(all(na));
    fenwick_tree<int> ft(mx+1);
    ll val = 0;
    rep(i, n) {
        val += ft.sum(na[i]+1, mx+1);
        ft.add(na[i], 1);
    }
    if (val%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
