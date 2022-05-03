// 学習0回目,解説AC,解法1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> c(n, vector<bool>(n));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        c[x][y] = true;
        c[y][x] = true;
    }
    int ans = 0;
    rep(i, 1<<n) {
        bool ok = true;
        rep(x, n) for (int y=x+1; y<n; ++y) {
            if (!(i&(1<<x)) || !(i&(1<<y))) continue;
            if (!c[x][y]) ok = false;
        }
        if (!ok) continue;
        int cnt = bitset<32>(i).count();
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
