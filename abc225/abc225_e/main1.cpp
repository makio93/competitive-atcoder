// 解説AC

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

class fraction {
    ll num, den;
public:
    fraction(ll num=0, ll den=1) : num(num), den(den) {}
    bool operator<(const fraction& other) const {
        return num * other.den < other.num * den;
    }
    bool operator<=(const fraction& other) const {
        return num * other.den <= other.num * den;
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<pair<fraction, fraction>> flst(n);
    rep(i, n) flst[i] = { fraction(y[i], x[i]-1), fraction(y[i]-1, x[i]) };
    sort(all(flst));
    int res = 0, nid = 0;
    while (nid < n) {
        ++res;
        int tid = nid + 1;
        while (tid<n && flst[tid].second<flst[nid].first) ++tid;
        nid = tid;
    }
    cout << res << endl;
    return 0;
}
