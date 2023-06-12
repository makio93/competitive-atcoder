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

const int INF = (int)(1e9);

int op(int ai, int bi) { return max(ai, bi); }
int e() { return 0; }

int main() {
    int n;
    cin >> n;
    vector<int> w(n), h(n);
    rep(i, n) cin >> w[i] >> h[i];
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int li, int ri) -> bool { return make_pair(w[li], -h[li]) < make_pair(w[ri], -h[ri]); });
    int mh = *max_element(all(h));
    segtree<int, op, e> st(mh+1);
    rep(i, n) st.set(h[ord[i]], max(st.get(h[ord[i]]), st.prod(0, h[ord[i]]) + 1));
    cout << st.all_prod() << endl;
    return 0;
}
