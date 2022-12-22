// 学習2回目,解説AC

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

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<pair<char, int>> runs;
    runs.emplace_back(s.front(), 1);
    rep3(i, 1, n) {
        if (runs.back().first == s[i]) runs.back().second++;
        else runs.emplace_back(s[i], 1);
    }
    int m = runs.size(), acnt = 0, bcnt = 0;
    rep(i, m) if (runs[i]==make_pair((char)('R'),1) && i-1>=0 && runs[i-1].first=='A' && i+1<m && runs[i+1].first=='C') {
        ++acnt;
        bcnt += min(runs[i-1].second, runs[i+1].second);
    }
    int res = min(acnt*2, bcnt);
    cout << res << endl;
    return 0;
}
