// 復習1回目,自力AC

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
    int a, n;
    cin >> a >> n;
    int len = to_string(n).length(), mx = 1;
    rep(i, len) mx *= 10;
    vector<int> dist(mx, INF);
    queue<int> que;
    dist[1] = 0;
    que.push(1);
    while (!que.empty() && dist[n]==INF) {
        int val = que.front(); que.pop();
        int di = dist[val], ndi = di + 1;
        ll nval = (ll)val * a;
        if (nval<(ll)mx && dist[nval]==INF) {
            dist[nval] = ndi;
            que.push(nval);
        }
        if (val<10 || val%10==0) continue;
        string vstr = to_string(val);
        int m = vstr.length(), tval = stoi(vstr.substr(m-1)+vstr.substr(0, m-1));
        if (dist[tval] != INF) continue;
        dist[tval] = ndi;
        que.push(tval);
    }
    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
    return 0;
}
