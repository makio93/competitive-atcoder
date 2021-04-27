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

// 本番中に実装、AC（のちに一部書き直し）

int main() {
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vector<int> t(d);
    rep(i, d) {
        cin >> t[i];
        t[i]--;
    }
    vector<int> last(26);
    ll sum = 0;
    rep3(i, 1, d+1) {
        sum += s[i-1][t[i-1]];
        last[t[i-1]] = i;
        rep(j, 26) sum -= c[j] * (i - last[j]);
        cout << sum << endl;
    }
    return 0;
}
