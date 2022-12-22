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

int main() {
    int n;
    cin >> n;
    vector<int> a(n*2);
    rep(i, n*2) cin >> a[i];
    vector<pair<int, int>> aids(2*n);
    rep(i, n*2) aids[i] = { a[i], i };
    sort(all(aids));
    vector<int> vals(2*n);
    rep(i, n*2) {
        if (i < n) vals[aids[i].second] = 1;
        else vals[aids[i].second] = -1;
    }
    string res(2*n, '.');
    int val = 0;
    rep(i, n*2) {
        if (val==0 || val*vals[i]>0) res[i] = '(';
        else res[i] = ')';
        val += vals[i];
    }
    cout << res << endl;
    return 0;
}
