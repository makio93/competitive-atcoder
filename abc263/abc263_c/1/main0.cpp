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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ord(m);
    rep(i, n) ord[i] = 1;
    do {
        rep(i, m) if (ord[i] == 1) cout << (i+1) << ' ';
        cout << endl;
    } while (next_permutation(all(ord), greater<int>()));
    return 0;
}
