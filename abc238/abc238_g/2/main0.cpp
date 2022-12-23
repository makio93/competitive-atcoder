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

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = *max_element(all(a));
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<vector<uint64_t>> hs(mval+1, vector<uint64_t>(3));
    rep(i, mval+1) {
        rep(j, 2) hs[i][j] = engine();
        rep(j, 2) hs[i][2] ^= hs[i][j];
    }
    vector<int> pcs(mval+1);
    vector<uint64_t> hsums(n+1);
    rep(i, n) {
        int tmp = a[i];
        for (int j=2; j*j<=tmp; ++j) {
            while (tmp%j == 0) {
                hsums[i+1] ^= hs[j][pcs[j]%3];
                pcs[j]++;
                tmp /= j;
            }
        }
        if (tmp > 1) {
            hsums[i+1] ^= hs[tmp][pcs[tmp]%3];
            pcs[tmp]++;
        }
        hsums[i+1] ^= hsums[i];
    }
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        if ((hsums[ri]^hsums[li]) == 0ULL) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
