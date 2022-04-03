// 解説AC2-2(queueで遷移先マスを列挙せず,遷移先を見つけると同時に再帰を進める)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int n;
vector<string> s;
ull sid;
set<ull> used;

void paint(int i, int j, int m) {
    if (m == 1) {
        s[i][j] = '@';
        sid += (1ULL<<(i*n+j));
    }
    else {
        s[i][j] = '.';
        sid -= (1ULL<<(i*n+j));
    }
}

ll dfs(int d) {
    if (used.find(sid) != used.end()) return 0;
    used.insert(sid);
    if (d == 0) return 1;
    ll res = 0;
    rep(i, n) rep(j, n) if (s[i][j] == '.') {
        vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
        bool ok = false;
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
            if (s[ni][nj] != '@') continue;
            ok = true;
        }
        if (ok) {
            paint(i, j, 1);
            res += dfs(d-1);
            paint(i, j, 0);
        }
    }
    return res;
}

int main() {
    int k;
    cin >> n >> k;
    s = vector<string>(n);
    rep(i, n) cin >> s[i];
    ll res = 0;
    sid = 0;
    used.insert(sid);
    rep(i, n) rep(j, n) if (s[i][j] == '.') {
        paint(i, j, 1);
        res += dfs(k-1);
        paint(i, j, 0);
    }
    cout << res << endl;
    return 0;
}
