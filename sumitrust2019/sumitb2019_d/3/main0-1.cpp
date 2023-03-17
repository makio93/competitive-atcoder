// 学習3回目,自力AC1

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
    string s;
    cin >> n >> s;
    int res = 0;
    rep(i, 1000) {
        int ti = i, id = 0;
        rep(j, n) {
            if (s[j]-'0' == ti%10) {
                ++id;
                ti /= 10;
                if (id == 3) break;
            }
        }
        if (id == 3) ++res;
    }
    cout << res << endl;
    return 0;
}
