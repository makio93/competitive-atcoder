// 学習2回目,自力WA1

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
    string s, t;
    cin >> n >> s >> t;
    if (count(all(s), '1') != count(all(t), '1')) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0, val = 0;
    rep(i, n) {
        if (s[i] == t[i]) continue;
        if (s[i] == '1') {
            if (val >= 0) ++res;
            ++val;
        }
        else {
            if (val <= 0) ++res;
            --val;
        }
    }
    cout << res << endl;
    return 0;
}
