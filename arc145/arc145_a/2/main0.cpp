// 学習2回目,自力AC

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
    if (s[0] == s[n-1]) cout << "Yes" << endl;
    else if (s[0]=='B' && s[n-1]=='A') {
        if (n > 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
    return 0;
}
