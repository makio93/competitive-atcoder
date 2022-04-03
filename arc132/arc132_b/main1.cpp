// 復習,解説1

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
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    bool rev = (n>2 && (p[0]-1==p[1] || p[1]-1==p[2]));
    int id = find(all(p), 1) - p.begin();
    vector<vector<int>> dist(2, vector<int>(n, INF));
    queue<pair<bool, int>> que;
    auto update = [&](bool rev, int id, int di) -> void {
        if (dist[rev][id] <= di) return;
        dist[rev][id] = di;
        que.emplace(rev, id);
    };
    update(rev, id, 0);
    while (!que.empty()) {
        auto [rev, id] = que.front(); que.pop();
        int di = dist[rev][id];
        update(rev, (id+n-1)%n, di+1);
        update(!rev, n-1-id, di+1);
    }
    cout << dist[0][0] << endl;
    return 0;
}
