// 学習1回目,解説AC

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
    int n;
    cin >> n;
    vector<bool> is_square(n+1);
    for (int i=1; i*i<=n; ++i) is_square[i*i] = true;
    vector<vector<int>> dlst(n+1);
    rep3(i, 1, n+1) for (int j=i; j<=n; j+=i) dlst[j].push_back(i);
    vector<int> vcnt(n+1);
    rep3(i, 1, n+1) {
        int mval = 0;
        for (const int& di : dlst[i]) if (is_square[di]) mval = di;
        vcnt[i/mval]++;
    }
    ll res = 0;
    rep3(i, 1, n+1) res += (ll)vcnt[i] * vcnt[i];
    cout << res << endl;
    return 0;
}
