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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    int m = t.length();
    vector<char> c(k+1);
    vector<string> a(k+1);
    rep(i, k) cin >> c[i] >> a[i];
    c[k] = 'z' + 1;
    a[k] = s;
    vector<vector<vector<int>>> dp0(m, vector<vector<int>>(m, vector<int>(27, INF)));
    vector<vector<vector<vector<int>>>> dp1(m, vector<vector<vector<int>>>(m, vector<vector<int>>(k+1)));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> g(28);
    rep(i, k+1) if ((int)(a[i].length()) == 1) g[a[i][0]-'a'].emplace_back(c[i]-'a', 1);
    repr(i, m) rep3(j, i, m) {
        rep(ii, k+1) {
            dp1[i][j][ii] = vector<int>(a[ii].size(), INF);
            rep3(i2, 1, a[ii].size()) rep3(j2, i+1, j+1) chmin(dp1[i][j][ii][i2], dp1[i][j2-1][ii][i2-1]+dp0[j2][j][a[ii][i2]-'a']);
        }
        rep(i2, 27) {
            if (i==j && t[i]-'a'==i2 && dp0[i][j][i2]>0) {
                dp0[i][j][i2] = 0;
                pq.emplace(0, i2);
            }
            int mval = INF;
            rep(ii, k+1) if (c[ii]-'a'==i2 && (a[ii].length())>1) chmin(mval, dp1[i][j][ii][a[ii].length()-1]+1);
            if (dp0[i][j][i2] > mval) {
                dp0[i][j][i2] = mval;
                pq.emplace(mval, i2);
            }
        }
        pq.emplace(0, 27);
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int vi = pi.second, di = pi.first;
            if (vi!=27 && di!=dp0[i][j][vi]) continue;
            for (const auto& tpi : g[vi]) {
                int ti = tpi.first, ndi = min(INF, di+tpi.second);
                if (dp0[i][j][ti] <= ndi) continue;
                dp0[i][j][ti] = ndi;
                pq.emplace(ndi, ti);
            }
        }
        rep(ii, k+1) dp1[i][j][ii][0] = dp0[i][j][a[ii][0]-'a'];
    }
    if (dp1[0][m-1][k][s.length()-1] == INF) cout << -1 << endl;
    else cout << dp1[0][m-1][k][s.length()-1] << endl;
    return 0;
}
