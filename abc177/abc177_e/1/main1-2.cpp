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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = *max_element(all(a));
    vector<int> acnt(mval+1);
    rep(i, n) acnt[a[i]]++;
    bool pair = true;
    rep3(i, 2, mval+1) {
        int tcnt = 0;
        for (int j=i; j<=mval; j+=i) tcnt += acnt[j];
        if (tcnt >= 2) pair = false;
    }
    if (pair) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int gval = a[0];
    rep3(i, 1, n) gval = gcd(gval, a[i]);
    if (gval > 1) cout << "not coprime" << endl;
    else cout << "setwise coprime" << endl;
    return 0;
}
