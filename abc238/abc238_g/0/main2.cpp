// 

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
    vector<int> a(n), l(q), r(q);
    rep(i, n) cin >> a[i];
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    vector<vector<int>> plst(n);
    rep(i, n) {
        int aval = a[i];
        for (int j=2; j*j<=aval; ++j) {
            while (aval%j == 0) {
                plst[i].push_back(j);
                aval /= j;
            }
        }
        if (aval > 1) plst[i].push_back(aval);
    }
    int mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    random_device seed;
    mt19937_64 engine(seed());
    vector<bool> res(q, true);
    rep(i1, 50) {
        vector<int> hash(mval+1), hsum(n+1);
        rep(i, mval+1) hash[i] = engine() % 3;
        rep(i, n) {
            hsum[i+1] += hsum[i];
            for (int val : plst[i]) hsum[i+1] += hash[val];
        }
        rep(i, q) if ((hsum[r[i]]-hsum[l[i]])%3 != 0) res[i] = false;
    }
    rep(i, q) {
        if (res[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
