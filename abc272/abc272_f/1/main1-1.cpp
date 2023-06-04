// 学習1回目,解説AC1

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
    string st = s + s + string(n, 'a') + t + t + string(n, 'z');
    auto sa = suffix_array(st);
    int lv = n * 3, rv = n * 4;
    ll res = 0;
    int bcnt = 0;
    repr(i, n*6) {
        if (sa[i]>=lv && sa[i]<rv) ++bcnt;
        else if (sa[i] < n) res += bcnt;
    }
    cout << res << endl;
    return 0;
}
