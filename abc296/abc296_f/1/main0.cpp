// 学習1回目,自力WA

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
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) {
        cin >> b[i];
        b[i]--;
    }
    auto ta = a, tb = b;
    sort(all(ta));
    sort(all(tb));
    if (ta != tb) {
        cout << "No" << endl;
        return 0;
    }
    dsu uf(n);
    rep(i, n) uf.merge(a[i], b[i]);
    auto glst = uf.groups();
    int val = glst.size() - 1;
    for (const auto& vi : glst) if ((int)(vi.size()) > 1) val += vi.size();
    if ((val>0 && val<3) || (val>0 && val%2==0)) cout << "No" << endl;
    else cout << "Yes" << endl; 
    return 0;
}
