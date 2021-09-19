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

// 解説AC

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    set<int> plst;
    rep3(i, 1, n+1) plst.insert(i);
    vector<int> res;
    rep(i, k-1) {
        res.push_back(a[i]);
        plst.erase(a[i]);
        if (*plst.begin() < a[i]) {
            res.push_back(*plst.begin());
            plst.erase(plst.begin());
        }
    }
    for (auto itr=plst.rbegin(); itr!=plst.rend(); ++itr) res.push_back(*itr);
    rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
    return 0;
}
