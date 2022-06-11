// 復習1回目,解説AC1

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

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    vector<vector<int>> pls(mval+1);
    rep3(i, 2, mval+1) if (pls[i].empty()) {
        for (int j=i; j<=mval; j+=i) {
            int tval = j;
            while (tval%i == 0) {
                pls[j].push_back(i);
                tval /= i;
            }
        }
    }
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<vector<uint_fast64_t>> hs(mval+1, vector<uint_fast64_t>(3));
    rep(i, mval+1) rep(j, 2) {
        hs[i][j] = engine();
        hs[i][2] ^= hs[i][j];
    }
    vector<int> pcnts(mval+1);
    vector<uint_fast64_t> hsums(n+1);
    rep(i, n) {
        hsums[i+1] ^= hsums[i];
        for (int pv : pls[a[i]]) {
            hsums[i+1] ^= hs[pv][pcnts[pv]];
            pcnts[pv] = (pcnts[pv] + 1) % 3;
        }
    }
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        if ((hsums[li]^hsums[ri]) == (uint_fast64_t)(0)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
