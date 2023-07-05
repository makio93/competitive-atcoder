// 学習1回目,自力AC

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
    int n, m;
    ll k;
    string s;
    cin >> n >> m >> k >> s;
    int xlen = count(all(s), 'x');
    if (xlen*(ll)m == k) {
        cout << (n*(ll)m) << endl;
        return 0;
    }
    vector<int> xlst;
    rep(i, n) if (s[i] == 'x') xlst.push_back(i);
    vector<ll> llst, rlst;
    llst.push_back(-1);
    int ri = k%xlen, li = 0;
    rlst.push_back(k/xlen*(ll)n+xlst[ri]);
    ++ri;
    while (ri < xlen) {
        llst.push_back(xlst[li]);
        rlst.push_back(k/xlen*(ll)n+xlst[ri]);
        ++li; ++ri;
    }
    llst.push_back(li >= xlen ? xlst[0]+n : xlst[li]);
    rlst.push_back(k/xlen*(ll)n+n);
    if (k/xlen <= m-2) {
        rep(i, xlen) xlst.push_back(xlst[i]+n);
        while (ri < xlen*2) {
            llst.push_back(xlst[li]);
            rlst.push_back(k/xlen*(ll)n+xlst[ri]);
            ++li; ++ri;
        }
    }
    int rlen = rlst.size();
    ll res = 0;
    rep(i, rlen) res = max(res, rlst[i]-llst[i]-1);
    cout << res << endl;
    return 0;
}
