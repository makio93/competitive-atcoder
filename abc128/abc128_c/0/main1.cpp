// 

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
    vector<int> k(m), s(n, 0);
    rep(i, m) {
        cin >> k[i];
        rep(j, k[i]) {
            int si;
            cin >> si;
            --si;
            s[si] |= 1<<i;
        }
    }
    int p = 0;
    rep(i, m) {
        int pi;
        cin >> pi;
        p |= pi<<i;
    }
    int ans = 0;
    rep(i, 1<<n) {
        int t = 0;
        rep(j, n) {
            if (i>>j&1) t ^= s[j];
        }
        if (t == p) ++ans;
    }
    cout << ans << endl;
    return 0;
}
