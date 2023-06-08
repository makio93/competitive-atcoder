// 学習1回目,解説AC

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
    int n, a;
    cin >> n >> a;
    vector<int> w(n), x(n), v(n);
    rep(i, n) cin >> w[i] >> x[i] >> v[i];
    int res = 0;
    rep(i, n) {
        vector<tuple<double, bool, int>> tlst;
        rep(j, n) {
            if (v[j] == v[i]) { if (x[j]>=x[i] && x[j]<=x[i]+a) tlst.emplace_back(0.0, false, w[j]); }
            else {
                double t1 = (x[i]-x[j])/(double)(v[j]-v[i]), t2 = (x[i]+a-x[j])/(double)(v[j]-v[i]);
                if (t1 > t2) swap(t1, t2);
                if (t1<0 && t2<0) continue;
                if (t1 < 0) {
                    tlst.emplace_back(0.0, false, w[j]);
                    tlst.emplace_back(t2, true, -w[j]);
                }
                else {
                    tlst.emplace_back(t1, false, w[j]);
                    tlst.emplace_back(t2, true, -w[j]);
                }
            }
        }
        sort(all(tlst));
        int m = tlst.size(), val = 0;
        rep(i, m) {
            val += get<2>(tlst[i]);
            res = max(res, val);
        }
    }
    cout << res << endl;
    return 0;
}
