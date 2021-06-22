#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答、WA

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
    vector<int> deg(n), state(n);
    rep(i, n) deg[i] = (int)(g[i].size());
    ll res = 1;
    queue<int> que;
    rep(i, n) if (deg[i] == 1) {
        que.push(i);
        state[i] = 1;
    }
    while (!que.empty()) {
        int v = que.front(); que.pop();
        int si = state[v];
        for (int t : g[v]) {
            if (si == 2) res = res * 2 % mod;
            int nsi = si + ((c[t] != c[v]) ? 1 : 0);
            if (nsi == 3) nsi = 1;
            state[t] = max(state[t], nsi);
            g[t].erase(v);
            deg[t]--;
            if (deg[t] == 1) que.push(t);
        }
        g[v].clear();
        deg[v] = 0;
    }
    cout << res << endl;
    return 0;
}
