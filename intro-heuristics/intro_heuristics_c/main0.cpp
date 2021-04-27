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

// 本番中に実装、未完成

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
        dq[i].first--; dq[i].second--;
    }
    vector<int> last(26);
    vector<set<int>> holds(26, set<int>({0}));
    ll sum = 0;
    rep3(i, 1, d+1) {
        sum += s[i-1][t[i-1]];
        last[t[i-1]] = i;
        rep(j, 26) sum -= c[j] * (i - last[j]);
        holds[t[i-1]].insert(i);
    }
    rep(i, 26) holds[i].insert(d+1);
    rep(i, m) {
        int sub = 0;
        int p = t[dq[i].first], q = dq[i].second;
        auto pi = find(all(holds[p]), dq[i].first);
        auto qi = upper_bound(all(holds[q]), dq[i].first);
        pi = holds[p].erase(pi);
        sub += (*pi - dq[i].first) * (*pi - dq[i].first + 1) / 2;
        pi--;
        sub += (dq[i].first - *pi) * (dq[i].first - *pi + 1) / 2;
        auto qti = qi;
        qi--;
        sub += (*qti - *qi) * (*qti - *qi + 1) / 2;
        int add = 0;
        auto pfi = pi;
        pi++;
        add += (*pi - *pfi) * (*pi - *pfi + 1) / 2;
        add += (*qti - dq[i].first) * (*qti - dq[i].first + 1) / 2;
        add += (dq[i].first - *qi) * (dq[i].first - *qi + 1) / 2;
        holds[q].insert(dq[i].first);
        sum = sum - sub + add;
        cout << sum << endl;
    }
    return 0;
}
