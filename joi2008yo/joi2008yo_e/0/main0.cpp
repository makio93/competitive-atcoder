// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    rep(i, r) rep(j, c) cin >> a[i][j];
    int ans = 0;
    rep(i, (1<<r)) {
        vector<bool> rev(r);
        rep(j, r) if ((i>>j)&1) rev[j] = true;
        int sum = 0;
        rep(j, c) {
            int cnt = 0;
            rep(i2, r) if ((a[i2][j]==0) xor (rev[i2])) ++cnt;
            sum += max(cnt, r-cnt);
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
