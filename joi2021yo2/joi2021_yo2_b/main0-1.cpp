#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

const int INF = (int)(1e9);

int main(){
    int n, q;
    cin >> n >> q;
    rep(i1, q) {
        string s;
        cin >> s;
        int ans = INF;
        rep(i, 1<<(n-1)) {
            string t = s;
            repr(j, n-1) if ((i>>j)&1) {
                reverse(t.begin(), t.begin()+j+2);
            }
            bool ok = true;
            rep(j, n-1) if (t[j] > t[j+1]) ok = false;
            if (ok) ans = min(ans, __builtin_popcount(i));
        }
        cout << ans << endl;
    }
    return 0;
}
