// 学習2回目,解説AC3

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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    sort(all(c), greater<ll>());
    priority_queue<pair<ll, int>> pq;
    unordered_set<int> used;
    pq.emplace(a[0]+b[0]+c[0], 0);
    used.insert(0);
    vector<ll> res;
    while ((int)(res.size()) < k) {
        auto pi = pq.top(); pq.pop();
        res.push_back(pi.first);
        int ai = pi.second/1000/1000, bi = pi.second / 1000 % 1000, ci = pi.second % 1000;
        if (pi.second/1000/1000+1<x && used.find(pi.second+1000*1000)==used.end()) {
            pq.emplace(a[ai+1]+b[bi]+c[ci], pi.second+1000*1000);
            used.insert(pi.second+1000*1000);
        }
        if (pi.second/1000%1000+1<y && used.find(pi.second+1000)==used.end()) {
            pq.emplace(a[ai]+b[bi+1]+c[ci], pi.second+1000);
            used.insert(pi.second+1000);
        }
        if (pi.second%1000+1<z && used.find(pi.second+1)==used.end()) {
            pq.emplace(a[ai]+b[bi]+c[ci+1], pi.second+1);
            used.insert(pi.second+1);
        }
    }
    rep(i, k) cout << res[i] << endl;
    return 0;
}
