// 本番AC

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
    string s;
    cin >> s;
    int zero = (int)(s.length()) - 1;
    while (zero >= 0) {
        if (s[zero] != '0') break;
        --zero;
    }
    int l = 0, r = zero;
    bool ok = true;
    while (l < r) {
        if (s[l] != s[r]) {
            ok = false;
            break;
        }
        else { ++l; --r; }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
