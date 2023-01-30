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
    dsu d(n);
    bool ok = true;
    vector<int> dcnt(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        dcnt[ai]++, dcnt[bi]++;
        if (d.same(ai, bi)) ok = false;
        else d.merge(ai, bi);
    }
    rep(i, n) if (dcnt[i] > 2) ok = false;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
