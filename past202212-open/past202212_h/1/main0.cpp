// 学習1回目,自力AC

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
    int d;
    string n;
    cin >> d >> n;
    vector<int> dcnt(10);
    rep(i, d) dcnt[n[i]-'0']++;
    ll res = 0;
    rep(i, 10) rep(j, 10) res += dcnt[i] * (ll)dcnt[j] * abs(i-j);
    res /= 2;
    cout << res << endl;
    return 0;
}
