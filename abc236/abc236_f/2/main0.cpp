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
    vector<int> c(1<<n);
    rep3(i, 1, 1<<n) cin >> c[i];
    vector<pair<int, int>> cvals(1<<n);
    rep(i, 1<<n) cvals[i] = { c[i], i };
    sort(all(cvals));
    vector<bool> used(1<<n);
    ll res = 0;
    rep(i, 1<<n) if (!used[cvals[i].second]) {
        res += cvals[i].first;
        rep(j, 1<<n) if (used[j]) used[cvals[i].second^j] = true;
        used[cvals[i].second] = true;
    }
    cout << res << endl;
    return 0;
}
