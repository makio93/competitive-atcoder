// 学習2回目,解説AC

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
    vector<int> slst, tlst;
    rep(i, n) if (s[i] == '0') slst.push_back(i);
    rep(i, n) if (t[i] == '0') tlst.push_back(i);
    if ((int)(slst.size()) != (int)(tlst.size())) {
        cout << -1 << endl;
        return 0;
    }
    int m = slst.size(), res = 0;
    rep(i, m) if (slst[i] != tlst[i]) ++res;
    cout << res << endl;
    return 0;
}
