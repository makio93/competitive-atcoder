// 復習0,解説AC

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
    random_device seed;
    mt19937_64 engine(seed());
    vector<vector<uint_fast64_t>> hash(mval+1, vector<uint_fast64_t>(3));
    rep(i, mval+1) {
        hash[i][0] = engine();
        hash[i][1] = engine();
        hash[i][2] = hash[i][0] ^ hash[i][1];
    }
    vector<vector<int>> plst(n);
    vector<int> pcnt(mval+1);
    vector<uint_fast64_t> hsum(n+1);
    rep(i, n) {
        hsum[i+1] ^= hsum[i];
        int aval = a[i];
        for (int j=2; j*j<=aval; ++j) {
            while (aval%j == 0) {
                plst[i].push_back(j);
                aval /= j;
                hsum[i+1] ^= hash[j][pcnt[j]%3];
                pcnt[j]++;
            }
        }
        if (aval > 1) {
            plst[i].push_back(aval);
            hsum[i+1] ^= hash[aval][pcnt[aval]%3];
            pcnt[aval]++;
        }
    }
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        if ((hsum[ri]^hsum[li]) == (uint_fast64_t)0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
