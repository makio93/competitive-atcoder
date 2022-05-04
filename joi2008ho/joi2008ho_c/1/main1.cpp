// 学習1回目,解説AC

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
    vector<int> q(n2);
    rep(i, n+1) rep(j, n+1) q[(n+1)*i+j] = p[i] + p[j];
    sort(all(q));
    int ans = -INF;
    rep(i, n2) {
        int qi = q[i];
        auto itr = lower_bound(q.begin()+i, q.end(), m-qi+1);
        if (*(--itr) > m-qi) continue;
        ans = max(ans, *itr + qi);
    }
    cout << ans << endl;
    return 0;
}
