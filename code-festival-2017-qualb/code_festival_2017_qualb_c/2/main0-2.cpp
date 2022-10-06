// 学習2回目,自力AC2

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<int> col(n);
    bool ok = true;
    stack<pair<int, int>> st;
    st.emplace(0, 1);
    while (!st.empty() && ok) {
        auto pi = st.top(); st.pop();
        int vi = pi.first, ci = pi.second;
        col[vi] = ci;
        for (const int& ti : g[vi]) {
            if (col[ti] == ci) {
                ok = false;
                break;
            }
            if (col[ti] == -ci) continue;
            st.emplace(ti, -ci);
        }
    }
    if (ok) {
        int bi = count(all(col), 1);
        cout << ((ll)bi*(n-bi)-m) << endl;
    }
    else cout << ((ll)n*(n-1)/2-m) << endl;
    return 0;
}
