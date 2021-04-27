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

// 本番終了後に自力で実装し直し、2回目、スコアは悪化

int main(){
    int ti = clock();
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vector<int> last(26), t(d);
    ll sum = 0;
    rep3(i, 1, d+1) {
        ll cm = 0;
        rep(j, 26) cm += c[j] * (i - last[j]);
        pair<int, int> m((int)(-1e9), -1);
        rep(j, 26) {
            ll sat = s[i-1][j] - cm + c[j] * (i - last[j]);
            m = max(m, {sat, j});
        }
        sum += m.first;
        last[m.second] = i;
        t[i-1] = m.second;
        //cout << (m.second + 1) << endl;
    }
    srand((unsigned)time(NULL));
    while (clock()-ti < CLOCKS_PER_SEC*195/100) {
        int dr = rand() % d + 1, qr = rand() % 26;
        int fq = t[dr-1], tq = qr;
        int td = dr;
        int fl = dr-1, fr = dr+1, tl = dr, tr = dr;
        while (fl > 0) {
            if (t[fl-1] == fq) break;
            --fl;
        }
        while (fr <= d) {
            if (t[fr-1] == fq) break;
            ++fr;
        }
        while (tl > 0) {
            if (t[tl-1] == tq) break;
            --tl;
        }
        while (tr <= d) {
            if (t[tr-1] == tq) break;
            ++tr;
        }
        ll nsum = sum;
        nsum -= s[td-1][fq];
        nsum += (td-fl)*(td-fl-1)*c[fq]/2 + (fr-td)*(fr-td-1)*c[fq]/2;
        nsum -= (fr-fl)*(fr-fl-1)*c[fq]/2;
        nsum += s[td-1][tq];
        nsum -= (td-tl)*(td-tl-1)*c[tq]/2 + (tr-td)*(tr-td-1)*c[tq]/2;
        nsum += (tr-tl)*(tr-tl-1)*c[tq]/2;
        //cout << sum << endl;
        if (nsum >= sum*1.02) t[td-1] = tq;
    }
    rep(i, d) cout << (t[i] + 1) << endl;
    return 0;
}
