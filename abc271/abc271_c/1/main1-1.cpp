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

const int INF = (int)(1.1e9);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> taked(n+1);
    int scnt = 0;
    rep(i, n) {
        if (a[i] <= n) {
            if (taked[a[i]]) ++scnt;
            else taked[a[i]] = true;
        }
        else ++scnt;
    }
    int li = 1, ri = n;
    while (li<=n && taked[li]) ++li;
    while (ri>=0 && !taked[ri]) --ri;
    while (li < ri) {
        if (scnt >= 2) {
            scnt -= 2;
            taked[li] = true;
            while (li<=n && taked[li]) ++li;
        }
        else {
            ++scnt;
            taked[ri] = false;
            --ri;
            while (ri>=0 && !taked[ri]) --ri;
        }
    }
    while (scnt >= 2) {
        taked[li] = true;
        ++li;
        scnt -= 2;
    }
    cout << (li-1) << endl;
    return 0;
}
