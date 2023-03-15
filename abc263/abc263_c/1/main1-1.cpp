// 学習1回目,解説AC1

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
    int n, m;
    cin >> n >> m;
    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>()));
    auto solve = [&](auto solve, int v, int k) -> void {
        if (!dp[v][k].empty()) return;
        if (v == 0) {
            if (k == 0) dp[v][k].push_back({});
            else {
                solve(solve, v, k-1);
                dp[v][k] = dp[v][k-1];
            }
            return;
        }
        rep3(ki, 1, k+1) {
            if (v-1 > ki-1) continue;
            solve(solve, v-1, ki-1);
            for (auto vi : dp[v-1][ki-1]) {
                vi.push_back(ki);
                dp[v][k].push_back(vi);
            }
        }
    };
    solve(solve, n, m);
    sort(all(dp[n][m]));
    for (const auto& vi : dp[n][m]) {
        int len = vi.size();
        rep(i, len) cout << vi[i] << ' ';
        cout << endl;
    }
    return 0;
}
