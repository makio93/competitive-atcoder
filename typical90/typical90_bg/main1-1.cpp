#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

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
    for (int i=0; i*64<q; ++i) {
        vector<ull> dp(n);
        for (int j=0; j<64&&i*64+j<q; ++j) dp[a[i*64+j]] |= (1ULL << j);
        rep(j, m) dp[y[j]] |= dp[x[j]];
        for (int j=0; j<64&&i*64+j<q; ++j) {
            if ((dp[b[i*64+j]]>>j) & 1ULL) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
