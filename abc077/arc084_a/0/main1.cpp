// 学習0回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a)); sort(all(b)); sort(all(c));
    ll ans = 0;
    rep(i, n) {
        auto itr_a = lower_bound(all(a), b[i]);
        auto itr_c = lower_bound(all(c), b[i]+1);
        ans += (itr_a - a.begin()) * (c.end() - itr_c);
    }
    cout << ans << endl;
    return 0;
}
