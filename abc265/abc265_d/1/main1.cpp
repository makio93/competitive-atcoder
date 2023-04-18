// 学習1回目,解説AC

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
    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    set<ll> st;
    ll sval = 0;
    rep(i, n) {
        sval += a[i];
        st.insert(sval);
    }
    q += p;
    r += q;
    sval = 0;
    rep(i, n) {
        if (st.find(sval+p)!=st.end() && st.find(sval+q)!=st.end() && st.find(sval+r)!=st.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        sval += a[i];
    }
    cout << "No" << endl;
    return 0;
}
