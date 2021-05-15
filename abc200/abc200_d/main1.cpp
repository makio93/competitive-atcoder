#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説を見てから実装、AC

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    n = min(n, 8);
    vector<vector<int>> bcnt(200), res(2);
    rep3(i, 1, (1<<n)) {
        vector<int> resi;
        int bmod = 0;
        rep(j, n) if ((i>>j)&1) {
            resi.push_back(j+1);
            bmod = (bmod + a[j]) % 200;
        }
        if (!bcnt[bmod].empty()) {
            res[0] = bcnt[bmod];
            res[1] = resi;
            break;
        }
        bcnt[bmod] = resi;
    }
    if (!res[0].empty()) {
        cout << "Yes" << endl;
        rep(i1, 2) {
            int len = res[i1].size();
            cout << len << ' ';
            rep(i, len) printf("%d%c", res[i1][i], (i<len-1?' ':'\n'));
        }
    }
    else cout << "No" << endl;
    return 0;
}
