// 学習1回目,自力AC

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
    int n;
    cin >> n;
    ll res = 0;
    rep3(i, 1, n+1) {
        vector<pair<int, int>> plst;
        int tmp = i;
        for (int j=2; j*j<=tmp; ++j) if (tmp%j == 0) {
            plst.emplace_back(j, 0);
            while (tmp%j == 0) {
                tmp /= j;
                plst.back().second++;
            }
        }
        if (tmp > 1) plst.emplace_back(tmp, 1);
        int j = 1;
        for (const auto& pi : plst) if (pi.second%2 == 1) j *= pi.first;
        int si = 1, cnt = 1;
        while (j*(si+1)*(si+1) <= n) {
            ++si;
            ++cnt;
        }
        res += cnt;
    }
    cout << res << endl;
    return 0;
}
