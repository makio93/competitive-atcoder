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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int pre = -1, id = -1;
    rep(i, n) {
        if (pre != a[i]) id = 0;
        if (a[i] == b[i]) {
            while (id<n && (a[i]==b[id]||a[id]==b[i])) ++id;
            if (id >= n) {
                cout << "No" << endl;
                return 0;
            }
            swap(b[id], b[i]);
            pre = a[i];
            ++id;
        }
        else pre = -1;
    }
    cout << "Yes" << endl;
    rep(i, n) printf("%d%c", b[i], (i<n-1?' ':'\n'));
    return 0;
}
