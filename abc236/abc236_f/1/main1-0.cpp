// 復習1,解説AC

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
    vector<pair<int, int>> clst;
    clst.emplace_back(0, 0);
    rep3(i, 1, (1<<n)) {
        int ci;
        cin >> ci;
        clst.emplace_back(ci, i);
    }
    sort(all(clst));
    vector<bool> used(1<<n);
    used[0] = true;
    ll res = 0;
    rep(i, (1<<n)) if (!used[clst[i].second]) {
        res += clst[i].first;
        rep(j, (1<<n)) if (used[j]) used[j^clst[i].second] = true;
    }
    cout << res << endl;
    return 0;
}
