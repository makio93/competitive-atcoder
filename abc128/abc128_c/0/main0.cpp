// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int powi(int n, int p) {
    int ans = 1;
    rep(i, p) {
        ans *= n;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> k(m), p(m);
    vector<vector<int>> s(m);
    rep(i, m) {
        cin >> k[i];
        rep(j, k[i]) {
            int si;
            cin >> si;
            s[i].push_back(si);
        }
    }
    rep(i, m) cin >> p[i];
    int ans = 0;
    rep(i, powi(2, n)) {
        bool ok = true;
        rep(j, m) {
            int pa = 0;
            rep(j2, k[j]) {
                if (i&powi(2, s[j][j2]-1)) ++pa;
            }
            if (pa%2!=p[j]) ok = false;
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}
