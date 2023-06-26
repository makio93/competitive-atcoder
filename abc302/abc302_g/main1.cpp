// 解説AC

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
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    auto b = a;
    sort(all(b));
    vector<vector<int>> c(4, vector<int>(4));
    rep(i, n) c[a[i]][b[i]]++;
    int res = 0;
    vector<int> ord(4);
    iota(all(ord), 0);
    do {
        int val = 0;
        rep(i, 4) rep3(j, i+1, 4) val += c[ord[i]][ord[j]];
        res = max(res, val);
    } while (next_permutation(all(ord)));
    cout << res << endl;
    return 0;
}
