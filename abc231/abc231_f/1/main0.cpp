// 学習1回目,自力AC

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
    vector<int> alst = a, blst = b;
    sort(all(alst));
    sort(all(blst));
    alst.erase(unique(all(alst)), alst.end());
    blst.erase(unique(all(blst)), blst.end());
    rep(i, n) a[i] = lower_bound(all(alst), a[i]) - alst.begin();
    rep(i, n) b[i] = lower_bound(all(blst), b[i]) - blst.begin();
    int alen = alst.size(), blen = blst.size();
    vector<vector<int>> ab(alen);
    rep(i, n) ab[a[i]].push_back(b[i]);
    fenwick_tree<int> bs(blen);
    ll res = 0;
    int sum = 0;
    rep(i, alen) if (!ab[i].empty()) {
        sum += (int)(ab[i].size());
        for (int bi : ab[i]) bs.add(bi, 1);
        for (int bi : ab[i]) res += sum - bs.sum(0, bi);
    }
    cout << res << endl;
    return 0;
}
