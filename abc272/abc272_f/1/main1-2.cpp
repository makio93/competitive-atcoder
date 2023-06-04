// 学習1回目,解説AC2

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
    string s, t;
    cin >> n >> s >> t;
    string st = s + s + '$' + t + t + '~';
    auto sa = suffix_array(st);
    ll res = 0;
    int scnt = 0;
    rep(i, n*4+2) {
        if (sa[i] < n) ++scnt;
        else if (sa[i] >= n*2+1 && sa[i] < n*3+1) res += scnt;
    }
    cout << res << endl;
    return 0;
}
