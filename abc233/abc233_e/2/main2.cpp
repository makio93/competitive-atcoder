// 

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
    string s;
    cin >> s;
    int n = s.length();
    int w = 0, x = 0;
    rep(i, n) w += s[i] - '0';
    string ans;
    repr(i, n) {
        x += w;
        w -= s[i] - '0';
        ans += '0' + x%10;
        x /= 10;
    }
    while (x) {
        ans += '0' + x%10;
        x /= 10;
    }
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}
