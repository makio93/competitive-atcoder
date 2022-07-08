// 復習1回目,解説AC

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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> memo(n*2, vector<ll>(n*2, -1));
    auto dfs = [&](auto dfs, int li, int ri) -> ll {
        if (memo[li][ri] != -1) return memo[li][ri];
        if (ri-li == 0) {
            if (n%2 == 1) return memo[li][ri] = a[li%n];
            else return memo[li][ri] = 0;
        }
        ll rval = 0;
        if ((n-ri+li)%2 == 1) rval = max(a[li%n]+dfs(dfs,li+1,ri), dfs(dfs,li,ri-1)+a[ri%n]);
        else rval = (a[li%n] >= a[ri%n] ? dfs(dfs, li+1, ri) : dfs(dfs, li, ri-1));
        return memo[li][ri] = rval;
    };
    ll res = 0;
    rep(i, n) res = max(res, a[i]+dfs(dfs,i+1,i+n-1));
    cout << res << endl;
    return 0;
}
