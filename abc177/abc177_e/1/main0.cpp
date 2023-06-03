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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int gval = a[0];
    rep3(i, 1, n) gval = gcd(gval, a[i]);
    if (gval > 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    unordered_map<int, int> pcnt;
    rep(i, n) {
        int ai = a[i];
        for (int j=2; j*j<=ai; ++j) if (ai%j == 0) {
            pcnt[j]++;
            while (ai%j == 0) ai /= j;
        }
        if (ai > 1) pcnt[ai]++;
    }
    bool pair = true;
    for (const auto& pi : pcnt) if (pi.second >= 2) pair = false;
    if (pair) cout << "pairwise coprime" << endl;
    else cout << "setwise coprime" << endl;
    return 0;
}
