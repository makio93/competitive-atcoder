// 復習1回目,自力AC

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
    vector<bool> isp(mval+1, true);
    isp[0] = isp[1] = false;
    rep3(i, 2, mval+1) if (isp[i]) {
        for (int j=i*2; j<=mval; j+=i) isp[j] = false;
    }
    vector<int> plst;
    rep(i, mval+1) if (isp[i]) plst.push_back(i);
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    int m = plst.size();
    vector<vector<uint64_t>> hlst(m, vector<uint64_t>(3));
    rep(i, m) {
        rep(j, 2) hlst[i][j] = engine();
        rep(j, 2) hlst[i][2] ^= hlst[i][j];
    }
    vector<int> pcnts(m);
    vector<uint64_t> hsums(n+1);
    rep(i, n) {
        int aval = a[i];
        for (int j=2; j*j<=aval; ++j) if (aval%j == 0) {
            int pid = lower_bound(all(plst), j) - plst.begin();
            while (aval%j == 0) {
                aval /= j;
                hsums[i+1] ^= hlst[pid][pcnts[pid]];
                pcnts[pid] = (pcnts[pid] + 1) % 3;
            }
        }
        if (aval > 1) {
            int pid = lower_bound(all(plst), aval) - plst.begin();
            hsums[i+1] ^= hlst[pid][pcnts[pid]];
            pcnts[pid] = (pcnts[pid] + 1) % 3;
        }
    }
    rep(i, n) hsums[i+1] ^= hsums[i];
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        if ((hsums[ri] ^ hsums[li]) == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
