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

// 本番中に作成、テスト用

int main(){
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vector<int> last(26);
    ll sum = 0;
    rep3(i, 1, d+1) {
        ll cm = 0;
        rep(j, 26) cm += c[j] * (i - last[j]);
        pair<int, int> m((int)(-1e9), -1);
        rep(j, 26) {
            ll sat = s[i-1][j] - cm + c[j] * (i - last[j]);
            m = max(m, {sat, j});
        }
        sum += m.first;
        last[m.second] = i;
        cout << (m.second + 1) << ' ' << sum << endl;
    }
    return 0;
}
