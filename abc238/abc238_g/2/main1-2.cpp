// 学習2回目,解説AC2

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

const int BCNT = 50;

unsigned long long xor64(){
    static unsigned long long x = 88172645463325252ULL;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), l(q), r(q);
    rep(i, n) cin >> a[i];
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
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
    vector<bool> res(q, true);
    rep(i0, BCNT) {
        vector<int> hs(mval+1);
        rep(i, mval+1) hs[i] = xor64() % 3;
        vector<int> hvals(n+1);
        rep(i, n) {
            for (const int& vi : pf[a[i]]) hvals[i+1] += hs[vi];
            hvals[i+1] %= 3;
            hvals[i+1] += hvals[i];
        }
        rep(i, q) if ((hvals[r[i]]-hvals[l[i]])%3 != 0) res[i] = false;
    }
    rep(i, q) {
        if (res[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
