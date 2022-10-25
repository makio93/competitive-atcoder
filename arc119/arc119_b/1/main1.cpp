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

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (count(all(s), '1') != count(all(t), '1')) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> sids, tids;
    rep(i, n) {
        if (s[i] == '0') sids.push_back(i);
        if (t[i] == '0') tids.push_back(i);
    }
    int m = sids.size();
    int res = 0;
    rep(i, m) if (sids[i] != tids[i]) ++res;
    cout << res << endl;
    return 0;
}
