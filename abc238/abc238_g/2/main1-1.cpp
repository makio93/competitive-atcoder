// 学習2回目,解説AC1

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
    vector<vector<int>> pf(mval+1);
    rep3(i, 2, mval+1) if (pf[i].empty()) {
        for (int j=i; j<=mval; j+=i) {
            int tmp = j;
            while (tmp%i == 0) {
                tmp /= i;
                pf[j].push_back(i);
            }
        }
    }
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<vector<uint64_t>> hs(mval+1, vector<uint64_t>(3));
    rep(i, mval+1) {
        hs[i][0] = engine();
        hs[i][1] = engine();
        hs[i][2] = hs[i][0] ^ hs[i][1];
    }
    vector<int> pcnts(mval+1);
    vector<uint64_t> hvals(n+1);
    rep(i, n) {
        for (const int& vi : pf[a[i]]) {
            hvals[i+1] ^= hs[vi][pcnts[vi]%3];
            pcnts[vi]++;
        }
        hvals[i+1] ^= hvals[i];
    }
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        if (hvals[ri] == hvals[li]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
