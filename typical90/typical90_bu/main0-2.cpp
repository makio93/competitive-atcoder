#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答2、WA

const ll mod = (ll)(1e9) + 7;

int main() {
    int n;
    cin >> n;
    vector<char> c(n);
    rep(i, n) cin >> c[i];
    map<char, int> ccnt;
    rep(i, n) ccnt[c[i]]++;
    if ((int)(ccnt.size()) < 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<set<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].insert(bi);
        g[bi].insert(ai);
    }
    vector<int> deg(n), ord(n, n+5);
    vector<pair<ll, ll>> cval(n, { 1LL, 1LL }); // Cut? : { No, Yes }
    vector<ll> dval(n, 1LL);
    rep(i, n) deg[i] = (int)(g[i].size());
    queue<int> que;
    rep(i, n) if (deg[i] == 1) {
        que.push(i);
        cval[i] = { 1, 0 };
        dval[i] = 0;
        ord[i] = 0;
    }
    while (!que.empty()) {
        int v = que.front(); que.pop();
        ll cv0 = cval[v].first, cv1 = cval[v].second, dv = dval[v];
        ll ndv = (dv + cv1) % mod;
        int oval = ord[v], noval = oval + 1;
        for (int t : g[v]) {
            if (c[t] == c[v]) {
                cval[t].first = cval[t].first * cv0 % mod;
                cval[t].second = cval[t].second * cv1 % mod;
                dval[t] = dval[t] * ndv % mod;
            }
            else {
                cval[t].first = cval[t].first * (cv0 + dv) % mod;
                cval[t].second = cval[t].second * cv0 % mod;
                dval[t] = dval[t] * cv0 % mod;
            }
            g[t].erase(v);
            deg[t]--;
            if (deg[t] == 1) {
                que.push(t);
                ord[t] = min(noval, ord[t]);
            }
        }
        g[v].clear();
        deg[v] = 0;
    }
    pair<int, int> last = { -1, -1 };
    rep(i, n) last = max(last, { ord[i], i });
    int lv = last.second;
    ll res = (cval[lv].first + dval[lv]) % mod;
    cout << res << endl;
    return 0;
}
