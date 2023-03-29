// 学習1回目,自力AC

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
const int MAX = 55555;

int main() {
    int n;
    cin >> n;
    vector<bool> is_prime(MAX+1, true);
    for (int i=0; i*i<=MAX; ++i) {
        if (i <= 1) {
            is_prime[i] = false;
            continue;
        }
        for (int j=i*i; j<=MAX; j+=i) is_prime[j] = false;
    }
    vector<int> res;
    rep3(i, 1, 5) {
        for (int j=5+i; j<=MAX; j+=5) if (is_prime[j]) {
            res.push_back(j);
            if ((int)(res.size()) >= n) break;
        }
        if ((int)(res.size()) >= n) break;
        res.clear();
    }
    rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    return 0;
}
