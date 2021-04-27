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

// 本番終了後に自力で実装、AC、のちに一部書き直し

int main(){
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vector<int> t(d);
    rep(i, d) {
        cin >> t[i];
        t[i]--;
    }
    int m;
    cin >> m;
    vector<pair<int, int>> dq(m);
    rep(i, m) {
        cin >> dq[i].first >> dq[i].second;
        dq[i].first; dq[i].second--;
    }
    vector<int> last(26);
    ll sum = 0;
    rep3(i, 1, d+1) {
        sum += s[i-1][t[i-1]];
        last[t[i-1]] = i;
        rep(j, 26) sum -= c[j] * (i - last[j]);
    }
    rep(i, m) {
        int fq = t[dq[i].first-1], tq = dq[i].second;
        int td = dq[i].first;
        int fl = dq[i].first-1, fr = dq[i].first+1, tl = dq[i].first, tr = dq[i].first;
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
        sum -= s[td-1][fq];
        sum += (td-fl)*(td-fl-1)*c[fq]/2 + (fr-td)*(fr-td-1)*c[fq]/2;
        sum -= (fr-fl)*(fr-fl-1)*c[fq]/2;
        sum += s[td-1][tq];
        sum -= (td-tl)*(td-tl-1)*c[tq]/2 + (tr-td)*(tr-td-1)*c[tq]/2;
        sum += (tr-tl)*(tr-tl-1)*c[tq]/2;
        cout << sum << endl;
        t[td-1] = tq;
    }
    return 0;
}
