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

const int INF = (int)(1e9);

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> xlst, ylst;
    rep3(i, 1, n) {
        if (i%2 == 0) xlst.push_back(a[i]);
        else ylst.push_back(a[i]);
    }
    vector<bool> dp(n*10*2+10);
    dp[n*10+a[0]] = true;
    int m = xlst.size();
    rep(i, m) {
        vector<bool> ndp(n*10*2+10);
        rep(j, n*10*2+1) if (dp[j]) ndp[j+xlst[i]] = ndp[j-xlst[i]] = true;
        swap(ndp, dp);
    }
    if (x<-n*10 || x>n*10 || !dp[n*10+x]) {
        cout << "No" << endl;
        return 0;
    }
    dp.assign(n*10*2+10, false);
    dp[n*10] = true;
    m = ylst.size();
    rep(i, m) {
        vector<bool> ndp(n*10*2+10);
        rep(j, n*10*2+1) if (dp[j]) ndp[j+ylst[i]] = ndp[j-ylst[i]] = true;
        swap(ndp, dp);
    }
    if (y>=-n*10 && y<=n*10 && dp[n*10+y]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
