// 学習3回目,解説AC2

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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int bi = 0;
    rep(i, n) {
        if (i-1<0 || a[i-1]!=a[i]) bi = 0;
        if (a[i] == b[i]) {
            while (bi<n && (a[i]==b[bi] || a[bi]==a[i])) ++bi;
            if (bi == n) {
                cout << "No" << endl;
                return 0;
            }
            swap(b[bi], b[i]);
        }
    }
    cout << "Yes" << endl;
    rep(i, n) cout << b[i] << (i<n-1?' ':'\n');
    return 0;
}
