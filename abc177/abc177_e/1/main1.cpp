// 学習1回目,解説AC

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
    int mval = *max_element(all(a));
    vector<int> sieve(mval+1);
    sieve[1] = 1;
    for (int i=2; i<=mval; ++i) if (sieve[i] == 0) {
        sieve[i] = i;
        if (i > mval/i) continue;
        for (int j=i*i; j<=mval; j+=i) if (sieve[j] == 0) sieve[j] = i;
    }
    unordered_map<int, int> pcnt;
    rep(i, n) {
        int ai = a[i], pval = 1;
        while (ai > 1) {
            if (sieve[ai] != pval) pcnt[sieve[ai]]++;
            pval = sieve[ai];
            ai /= pval;
        }
    }
    bool pair = true;
    for (const auto& pi : pcnt) if (pi.second >= 2) pair = false;
    if (pair) cout << "pairwise coprime" << endl;
    else cout << "setwise coprime" << endl;
    return 0;
}
