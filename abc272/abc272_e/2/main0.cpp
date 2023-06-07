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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<pair<int, int>>> tlst(m);
    rep(i, n) {
        if (a[i]+(i+1) >= 0 && a[i]+(i+1) < n) tlst[0].emplace_back(a[i]+(i+1), i+1);
        else if (a[i]+(i+1) < 0) {
            int tlen = (abs(a[i]) + (i+1) - 1) / (i+1) * (i+1), tval = tlen + a[i];
            if (tval < n && tlen/(i+1) <= m) tlst[tlen/(i+1)-1].emplace_back(tval, i+1);
        }
    }
    map<int, vector<int>> ast;
    rep(i, m) {
        int res = 0;
        map<int, vector<int>> nst;
        for (const auto& pi : tlst[i]) {
            nst[pi.first].push_back(pi.second);
            while (nst.find(res) != nst.end()) ++res;
        }
        for (const auto& pi : ast) for (const int& ti : pi.second) if (pi.first+ti < n) {
            nst[pi.first+ti].push_back(ti);
            while (nst.find(res) != nst.end()) ++res;
        }
        swap(nst, ast);
        cout << res << endl;
    }
    return 0;
}
