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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(b.rbegin(), b.rend());
    int li = n, ri = -1;
    bool res = true;
    rep(i, n) {
        if (a[i] == b[i]) {
            if (li == n) li = i;
        }
        else {
            if (li != n) {
                ri = i-1;
                break;
            }
        }
    }
    if (li!=n && ri==-1) ri = n-1;
    if (li != n) {
        int tli = ri + 1;
        if (tli%n == li) res = false;
        else {
            int sli = li;
            while (sli-1>=0 && (a[sli-1]==b[li]||b[sli-1]==b[li])) --sli;
            while (b[tli%n]==b[ri] || a[tli%n]==b[ri]) {
                ++tli;
                if (tli-n >= sli) {
                    res = false;
                    break;
                }
            }
            if (res) {
                if (tli+ri-li >= n) {
                    if ((tli+ri-li)%n >= sli) res = false;
                }
            }
        }
        if (res) {
            rep(i, ri-li+1) {
                swap(b[li+i], b[(tli+i)%n]);
            }
        }
    }
    if (res) {
        cout << "Yes" << endl;
        rep(i, n) printf("%d%c", b[i], (i<n-1?' ':'\n'));
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
