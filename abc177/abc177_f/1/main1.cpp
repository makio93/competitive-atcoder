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

const int INF = (int)(1e9);

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> a(h), b(h);
    rep(i, h) {
        cin >> a[i] >> b[i];
        a[i]--;
    }
    set<pair<int, int>> st;
    multiset<int> mst;
    rep(i, w) {
        st.emplace(i, i);
        mst.insert(0);
    }
    rep(i, h) {
        auto itr = st.lower_bound({ a[i], -1 });
        int ali = -1;
        while (itr != st.end() && itr->first < b[i]) {
            mst.erase(mst.find(itr->first - itr->second));
            int ri = (b[i] < w) ? b[i] : INF, len = ri == INF ? INF : ri - itr->second, li = itr->second;
            st.erase(itr);
            if (len != INF) ali = max(ali, li);
            itr = st.lower_bound({ a[i], -1 });
        }
        if (ali != -1) {
            st.emplace(b[i], ali);
            mst.insert(b[i]-ali);
        }
        if (mst.empty()) cout << -1 << endl;
        else cout << ((*mst.begin())+i+1) << endl;
    }
    return 0;
}
