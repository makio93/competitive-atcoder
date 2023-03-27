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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    ll res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(p[0]);
    rep3(i, 1, n) {
        if (p[i] <= pq.top()) pq.push(p[i]);
        else {
            res += p[i] - pq.top();
            rep(j, 2) pq.push(p[i]);
            pq.pop();
        }
    }
    cout << res << endl;
    return 0;
}
