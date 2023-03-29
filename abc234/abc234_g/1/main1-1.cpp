// 学習1回目,解説AC1

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

using mint = modint998244353;

struct R {
    int h;
    mint w;
    R(int h, mint w) : h(h), w(w) {}
};

struct D {
    mint tot;
    stack<R> st;
    D() : tot(0) {}
    void add(int h, mint w) {
        while (st.size() && st.top().h<=h) {
            w += st.top().w;
            tot -= st.top().w * st.top().h;
            st.pop();
        }
        st.emplace(h, w);
        tot += w * h;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    D dmax, dmin;
    dmax.add(a[0], 1), dmin.add(-a[0], 1);
    mint res = 0;
    rep(i, n) {
        res = dmax.tot + dmin.tot;
        if (i+1 >= n) break;
        dmax.add(a[i+1], res);
        dmin.add(-a[i+1], res);
    }
    cout << res.val() << endl;
    return 0;
}
