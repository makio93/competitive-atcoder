// 学習0回目,自力,WA+TLE

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
const ll LINF = (ll)(1e18);

int n;
vector<ll> val;
vector<vector<pair<ll, int>>> mval(2);
void dfs(int mode, int v, int h, ll nval) {
    int id = (mode==1?0:1), mul = (id==0?-1:1);
    mval[id][h] = max(mval[id][h], {nval,v*mul});
    if (h==0 || v+mode<0 || v+mode>=n) return;
    dfs(mode, v+mode, h-1, nval+val[v]);
    if (h-1>0 && val[v]<0) dfs(mode, v+mode, h-2, nval);
}

int main(){
    int k;
    cin >> n >> k;
    val = vector<ll>(n);
    rep(i, n) cin >> val[i];
    rep(i, 2) mval[i] = vector<pair<ll, int>>(k+1, {-LINF,INF});
    mval[0][0] = { 0, 0 };
    mval[1][0] = { 0, n-1 };
    dfs(1, 0, k, 0);
    dfs(-1, n-1, k, 0);
    rep(i, k+1) mval[0][i].second *= -1;
    ll ans = 0;
    rep(i, k+1) for (int j=k-i; j<=k; ++j) {
        if (mval[0][i].second+mval[1][j].second <= n+2) ans = max(ans, mval[0][i].first+mval[1][j].first);
    }
    cout << ans << endl;
    return 0;
}
