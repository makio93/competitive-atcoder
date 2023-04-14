// 学習2回目,解説AC1

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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) rep(j, 3) {
        int pi;
        cin >> pi;
        p[i] += pi;
    }
    auto tmp = p;
    sort(all(tmp), greater<int>());
    int kval = tmp[k-1];
    rep(i, n) {
        if (p[i]+300 >= kval) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
