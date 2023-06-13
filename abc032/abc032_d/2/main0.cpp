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

const ll LINF = (ll)(1e18);

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> vi(n), wi(n);
    rep(i, n) cin >> vi[i] >> wi[i];
    if (*max_element(all(wi)) <= 1000) {
        int wlen = accumulate(all(wi), 0);
        vector<ll> dp(wlen+1, -LINF);
        dp[0] = 0;
        rep(i, n) repr(j, wlen+1) if (dp[j] >= 0LL && j+wi[i] <= wlen) dp[j+wi[i]] = max(dp[j+wi[i]], dp[j]+vi[i]);
        ll res = 0;
        rep(i, wlen+1) if (i <= w) res = max(res, dp[i]);
        cout << res << endl;
    }
    else if (*max_element(all(vi)) <= 1000) {
        int vlen = accumulate(all(vi), 0);
        vector<ll> dp(vlen+1, LINF);
        dp[0] = 0;
        rep(i, n) repr(j, vlen+1) if (dp[j] < LINF && j+vi[i] <= vlen) dp[j+vi[i]] = min(dp[j+vi[i]], dp[j]+wi[i]);
        int res = 0;
        rep(i, vlen+1) if (dp[i] <= w) res = max(res, i);
        cout << res << endl;
    }
    else {
        if (n == 1) {
            if (wi[0] <= w) cout << vi[0] << endl;
            else cout << 0 << endl;
            return 0;
        }
        vector<pair<ll, ll>> llst, rlst;
        rep(i, 1<<(n/2)) {
            ll wval = 0, vval = 0;
            rep(j, n/2) if (i&(1<<j)) {
                wval += wi[j];
                vval += vi[j];
            }
            llst.emplace_back(wval, vval);
        }
        rep(i, 1<<(n-n/2)) {
            ll wval = 0, vval = 0;
            rep(j, n-n/2) if (i&(1<<j)) {
                wval += wi[n/2+j];
                vval += vi[n/2+j];
            }
            rlst.emplace_back(wval, vval);
        }
        sort(all(llst));
        sort(all(rlst));
        int llen = llst.size(), rlen = rlst.size();
        rep(i, llen-1) llst[i+1].second = max(llst[i+1].second, llst[i].second);
        rep(i, rlen-1) rlst[i+1].second = max(rlst[i+1].second, rlst[i].second);
        ll res = 0;
        rep(i, llen) if (llst[i].first <= w) {
            int id = upper_bound(all(rlst), make_pair(w-llst[i].first, LINF)) - rlst.begin() - 1;
            if (id >= 0) res = max(res, llst[i].second+rlst[id].second);
        }
        cout << res << endl;
    }
    return 0;
}
