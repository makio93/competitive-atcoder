// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    p.push_back(0);
    int n2 = n*n+2*n+1;
    vector<int> p2(n2);
    rep(i, n+1) rep(j, n+1) p2[(n+1)*i+j] = p[i] + p[j];
    sort(all(p2));
    int ans = -INF;
    rep(i, n2) {
        int p2i = p2[i];
        auto itr = lower_bound(all(p2), m - p2i + 1);
        if (itr == p2.begin()) continue;
        ans = max(ans, *(--itr) + p2i);
    }
    cout << ans << endl;
    return 0;
}
