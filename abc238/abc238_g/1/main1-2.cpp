// 復習1回目,解説AC2

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

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
    auto xorshift = []() -> ull {
        static random_device rd;
        static ull seed = ((ull)(rd()) << 32) + rd();
        seed ^= seed << 13;
        seed ^= seed >> 7;
        seed ^= seed << 17;
        return seed;
    };
    vector<int> l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    vector<bool> res(q, true);
    rep(b, 50) {
        vector<int> hs(mval+1);
        rep(i, mval+1) hs[i] = xorshift() % 3;
        vector<int> hsums(n+1);
        rep(i, n) {
            hsums[i+1] += hsums[i];
            for (int pv : pls[a[i]]) hsums[i+1] += hs[pv];
        }
        rep(i, q) if ((hsums[r[i]]-hsums[l[i]])%3 != 0) res[i] = false;
    }
    rep(i, q) {
        if (res[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
