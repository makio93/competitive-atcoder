#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 実験目的、解説ACしたソースからvector->mapにするとTLEになる

const ll mod = (ll)(1e9) + 7;

int h, w;
vector<int> lcnt;
vector<unordered_map<int, int>> stoid;
vector<unordered_map<int, int>> idtos;
vector<unordered_map<int, bool>> idtot;

bool isok(int spos, int dep, int s) {
    int y = (spos + dep) / w, x = (spos + dep) % w;
    const vector<int> dy = { -1, -1, -1, 0 }, dx = { -1, 0, 1, -1 }, did = { -w-1, -w, -w+1, -1 };
    rep(i, 4) {
        int ny = y + dy[i], nx = x + dx[i], nid = dep + did[i];
        if (ny<0 || nx<0 || nx>=w) continue;
        if (nid < 0) continue;
        if ((s>>nid) & 1) return false;
    }
    return true;
}

void init(int spos, int dep=0, int s=0) {
    if (dep == w+1) {
        int idcnt = lcnt[spos];
        stoid[spos][s] = idcnt;
        idtos[spos][idcnt] = s;
        idtot[spos][idcnt] = isok(spos, dep, s);
        lcnt[spos]++;
        return;
    }
    else {
        init(spos, dep+1, s);
        if (isok(spos, dep, s)) init(spos, dep+1, s+(1<<dep));
        return;
    }
}

int main() {
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    lcnt = vector<int>(w);
    stoid = vector<unordered_map<int, int>>(w);
    idtos = vector<unordered_map<int, int>>(w);
    idtot = vector<unordered_map<int, bool>>(w);
    rep(i, w) init(i);
    vector<unordered_map<int, int>> to0(w), to1(w);
    rep(i, w) rep(j, lcnt[i]) {
        int ni = (i + 1) % w;
        int tsi0 = (idtos[i][j] >> 1);
        int nid0 = stoid[ni][tsi0];
        to0[i][j] = nid0;
        if (idtot[i][j]) {
            int tsi1 = (idtos[i][j]>>1) + (1<<w);
            if (stoid[ni].find(tsi1) != stoid[ni].end()) {
                int nid1 = stoid[ni][tsi1];
                to1[i][j] = nid1;
            }
            else to1[i][j] = -1;
        }
        else to1[i][j] = -1;
    }
    vector<unordered_map<int, ll>> dp(h*w+1);
    dp[0][stoid[w-1][0]] = 1;
    rep(i, h*w) {
        int wi = (i+w-1) % w;
        rep(j, lcnt[wi]) {
            dp[i+1][to0[wi][j]] = (dp[i+1][to0[wi][j]] + dp[i][j]) % mod;
            if (to1[wi][j]!=-1 && c[i/w][i%w]=='.') {
                dp[i+1][to1[wi][j]] = (dp[i+1][to1[wi][j]] + dp[i][j]) % mod;
            }
        }
    }
    ll res = 0;
    rep(i, lcnt[w-1]) res = (res + dp[h*w][i]) % mod;
    cout << res << endl;
    return 0;
}
