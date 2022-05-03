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
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i, 1000) {
        string t;
        int x = i;
        rep(j, 3) {
            t += '0' + x % 10;
            x /= 10;
        }
        int ti = 0;
        rep(j, n) {
            if (s[j] == t[ti]) ++ti;
            if (ti == 3) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
