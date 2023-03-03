// 学習3回目,自力AC

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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) {
        cin >> b[i];
        b[i]--;
    }
    vector<int> lid(n, -1), rid(n, INF);
    rep(i, n) {
        lid[a[i]] = max(lid[a[i]], i);
        rid[a[i]] = min(rid[a[i]], i+n);
    }
    int pid = 0;
    rep(i, n) if (lid[b[i]] != -1) pid = max(pid, max(0, lid[b[i]]+1-i));
    bool ok = true;
    rep(i, n) if (rid[b[i]] != INF) if (i+pid >= rid[b[i]]) ok = false;
    if (!ok) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        vector<int> res(n);
        rep(i, n) res[(i+pid)%n] = b[i] + 1;
        rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    }
    return 0;
}
