#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説から、bitsetを用いてみる、MLEに(O(N*Q)bitsくらいになる、10^10/8Bytesくらいなので)

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> x(m), y(m);
    vector<pair<int, int>> yx(m);
    rep(i, m) {
        cin >> yx[i].second >> yx[i].first;
        yx[i].first--; yx[i].second--;
    }
    sort(all(yx));
    rep(i, m) {
        x[i] = yx[i].second;
        y[i] = yx[i].first;
    }
    vector<int> a(q), b(q);
    rep(i, q) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<bitset<100000>> dp(n);
    rep(i, q) dp[a[i]].set(i);
    rep(i, m) dp[y[i]] |= dp[x[i]];
    rep(i, q) cout << (dp[b[i]].test(i) ? "Yes" : "No") << endl;
    return 0;
}
