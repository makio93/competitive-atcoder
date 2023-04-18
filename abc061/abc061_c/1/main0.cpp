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
    ll k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    rep(i, n) pq.emplace(a[i], b[i]);
    int res = 0;
    while (!pq.empty()) {
        auto [ai, bi] = pq.top(); pq.pop();
        if ((ll)bi >= k) {
            res = ai;
            break;
        }
        k -= bi;
    }
    cout << res << endl;
    return 0;
}
