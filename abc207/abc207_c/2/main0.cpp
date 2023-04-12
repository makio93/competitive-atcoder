// 学習2回目,自力AC

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
    vector<int> l(n), r(n);
    rep(i, n) {
        int ti;
        cin >> ti >> l[i] >> r[i];
        --ti;
        l[i] *= 2;
        r[i] *= 2;
        if (ti&1) r[i]--;
        if (ti&2) l[i]++;
    }
    int res = 0;
    rep(i, n) rep3(j, i+1, n) if (l[i]<=r[j] && l[j]<=r[i]) ++res;
    cout << res << endl;
    return 0;
}
