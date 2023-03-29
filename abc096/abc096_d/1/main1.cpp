// 学習1回目,解説AC

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
    is_prime[0] = is_prime[1] = false;
    vector<int> res;
    for (int i=2; i<=MAX; ++i) if (is_prime[i]) {
        if (i%5 == 1) {
            res.push_back(i);
            if ((int)(res.size()) == n) break;
        }
        for (int j=i*i; j<=MAX; j+=i) is_prime[j] = false;
    }
    rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    return 0;
}
