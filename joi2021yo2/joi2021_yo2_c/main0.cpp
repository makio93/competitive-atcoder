#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main(){
    int n;
    ll d, k;
    cin >> n >> d >> k;
    vector<pair<ll, int>> sp(n);
    rep(i, n) {
        cin >> sp[i].second >> sp[i].first;
        sp[i].second--;
    }
    sort(all(sp));
    vector<vector<pair<ll, int>>> sn(2);
    rep(i, n) {
        sn[sp[i].second].emplace_back(sp[i].first, i);
    }
    vector<vector<int>> dp(n+1, vector<int>(2));
    rep(i, n) {
        ll now = 0;
        if (i > 0) now = sp[i-1].first + 1;
        rep(j, 2) {
            if (sp[i].second == j) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1);
            else dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            ll next = now + (d + dp[i][j] * k);
            int np = distance(sn[1-j].begin(), lower_bound(all(sn[1-j]), pair<ll, int>(next, 0)));
            if (np < (int)(sn[1-j].size())) {
                dp[sn[1-j][np].second+1][1-j] = max(dp[sn[1-j][np].second+1][1-j], dp[i][j]+1);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
