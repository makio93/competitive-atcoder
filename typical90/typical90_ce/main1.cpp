#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    int th = (int)round(sqrt(2*m)) + 1;
    unordered_map<int, int> bcol;
    rep(i, n) if ((int)(g[i].size()) >= th) bcol[i] = 1;
    unordered_map<int, vector<int>> g1, g2;
    rep(i, n) {
        if (bcol.find(i) != bcol.end()) {
            for (int t : g[i]) if (bcol.find(t) != bcol.end()) g1[i].push_back(t);
        }
        else {
            g2[i].push_back(i);
            for (int t : g[i]) g2[i].push_back(t);
        }
    }
    cin >> q;
    vector<int> last(n, -1), x(q), y(q);
    rep(i, q) {
        cin >> x[i] >> y[i];
        x[i]--;
        if (bcol.find(x[i]) != bcol.end()) {
            cout << bcol[x[i]] << endl;
            bcol[x[i]] = y[i];
            for (int t : g1[x[i]]) bcol[t] = y[i];
        }
        else {
            int qi = -1;
            for (int t : g2[x[i]]) qi = max(qi, last[t]);
            if (qi == -1) cout << 1 << endl;
            else cout << y[qi] << endl;
            for (int t : g2[x[i]]) if (bcol.find(t) != bcol.end()) bcol[t] = y[i];
        }
        last[x[i]] = i;
    }
    return 0;
}
