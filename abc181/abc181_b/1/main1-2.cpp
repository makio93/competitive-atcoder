// 学習1回目,解説AC2

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
    vector<int> cnt((int)(1e6)+2);
    rep(i, n) {
        int ai, bi;
        cin >> ai >> bi;
        cnt[ai]++;
        cnt[bi+1]--;
    }
    rep(i, (int)(1e6)+1) cnt[i+1] += cnt[i];
    ll res = 0;
    rep3(i, 1, (int)(1e6)+1) res += (ll)i * cnt[i];
    cout << res << endl;
    return 0;
}
