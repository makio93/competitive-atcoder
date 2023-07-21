// 解説AC

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
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> f(m);
    rep(i, n) f[a[i]] = i;
    vector<int> fis;
    rep(i, m) fis.push_back(f[i]);
    sort(all(fis));
    unordered_set<int> useds;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int fi = 0;
    rep(i, fis[fi]+1) pq.emplace(a[i], i);
    vector<int> res;
    int mli = -1;
    while ((int)(res.size()) < m) {
        while (pq.top().second <= mli || useds.find(pq.top().first) != useds.end()) pq.pop();
        res.push_back(pq.top().first);
        useds.insert(pq.top().first);
        mli = max(mli, pq.top().second);
        while (!pq.empty() && (pq.top().second <= mli || useds.find(pq.top().first) != useds.end())) pq.pop();
        while (fi < m && useds.find(a[fis[fi]]) != useds.end()) {
            ++fi;
            rep3(i, fis[fi-1]+1, fis[fi]+1) pq.emplace(a[i], i);
        }
    }
    rep(i, m) cout << (res[i]+1) << (i<m-1?' ':'\n');
    return 0;
}
