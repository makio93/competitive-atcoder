// 学習2回目,自力AC

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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ma = *max_element(all(a));
    vector<int> acnt(ma+1);
    rep(i, n) acnt[a[i]]++;
    ll res = 0;
    for (int i=1; i*i<=ma; ++i) {
        res += (ll)acnt[i] * acnt[i] * acnt[i*i];
        rep3(j, i+1, ma+1) {
            if (i*j > ma) break;
            res += (ll)acnt[i] * acnt[j] * 2 * acnt[i*j];
        }
    }
    cout << res << endl;
    return 0;
}
