// 学習0回目,解説AC

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

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> d(n), rd;
    rep(i, n) cin >> d[i];
    rd = d;
    reverse(all(rd));
    ll ans = 0;
    int len = min(n, k);
    rep(a, len+1) for (int b=0; b<=len-a; ++b) {
        set<int> vmemo;
        ll sum = 0;
        rep(i, a) {
            sum += d[i];
            vmemo.insert(d[i]);
        }
        rep(i, b) {
            sum += rd[i];
            vmemo.insert(rd[i]);
        }
        ans = max(ans, sum);
        auto itr = vmemo.begin();
        rep(i, (k-(a+b))) {
            if (itr==vmemo.end()) break;
            if (*itr >= 0) break;
            sum -= *itr;
            ans = max(ans, sum);
            ++itr;
        }
    }
    cout << ans << endl;
    return 0;
}
