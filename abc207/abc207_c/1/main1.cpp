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

int main() {
    int n;
    cin >> n;
    vector<double> l(n), r(n);
    rep(i, n) {
        int ti;
        cin >> ti >> l[i] >> r[i];
        --ti;
        if (ti&2) l[i] += 0.5;
        if (ti&1) r[i] -= 0.5;
    }
    int res = 0;
    rep(i, n) rep3(j, i+1, n) if (max(l[i], l[j]) <= min(r[i], r[j])) ++res;
    cout << res << endl;
    return 0;
}
