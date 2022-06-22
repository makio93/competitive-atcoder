// 復習1回目,解説AC

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
    ll mx = 1;
    while (mx <= (ll)n) mx *= 10;
    vector<int> dist(mx, INF);
    queue<ll> que;
    dist[1] = 0;
    que.push(1);
    while (!que.empty()) {
        ll val = que.front(); que.pop();
        int di = dist[val], ndi = di + 1;
        ll nval1 = val * a;
        if (nval1<mx && dist[nval1]==INF) {
            dist[nval1] = ndi;
            que.push(nval1);
        }
        if (val<10 || val%10==0) continue;
        string vstr = to_string(val);
        int m = vstr.length();
        ll nval2 = stoll(vstr.substr(m-1)+vstr.substr(0, m-1));
        if (nval2<mx && dist[nval2]==INF) {
            dist[nval2] = ndi;
            que.push(nval2);
        }
    }
    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
    return 0;
}
