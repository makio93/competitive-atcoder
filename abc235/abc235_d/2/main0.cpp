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
    int a, n;
    cin >> a >> n;
    int nlen = to_string(n).length(), mval = 1;
    rep(i, nlen) mval *= 10;
    vector<int> dist(mval, INF);
    queue<int> que;
    dist[1] = 0;
    que.push(1);
    while (!que.empty()) {
        int xi = que.front(); que.pop();
        int di = dist[xi], ndi = di + 1;
        string sxi = to_string(xi);
        int slen = sxi.length();
        if ((ll)xi*a<(ll)mval && dist[xi*a]==INF) {
            dist[xi*a] = ndi;
            que.push(xi*a);
        }
        if (sxi.back()=='0' || slen<2) continue;
        int nxi = stoi(string(1,sxi.back())+sxi.substr(0,slen-1));
        if (dist[nxi] == INF) {
            dist[nxi] = ndi;
            que.push(nxi);
        }
    }
    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
    return 0;
}
