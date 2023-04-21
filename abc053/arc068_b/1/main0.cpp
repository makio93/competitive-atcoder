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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = *max_element(all(a));
    vector<int> acnt(mval+1);
    rep(i, n) acnt[a[i]]++;
    int val = 0, sub = 0;
    rep3(i, 1, mval+1) if (acnt[i] >= 2) {
        val += (acnt[i] - 1) / 2;
        if (acnt[i]%2 == 0) ++sub;
    }
    val += (sub+1) / 2;
    cout << (n-val*2) << endl;
    return 0;
}
