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

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> p(n*2);
    rep(i, n*2) cin >> p[i];
    vector<int> x;
    rep(i, n*2-1) {
        if (i%2 == 0) {
            if (p[i+1] > p[i]) continue;
            if (i+2<n*2 && p[i+2]>p[i] && p[i+1]<p[i+2]) {
                x.push_back(i+2);
                swap(p[i+1], p[i+2]);
            }
            else {
                x.push_back(i+1);
                swap(p[i], p[i+1]);
            }
        }
        else {
            if (p[i+1] < p[i]) continue;
            if (i+2<n*2 && p[i+2]<p[i] && p[i+1]>p[i+2]) {
                x.push_back(i+2);
                swap(p[i+1], p[i+2]);
            }
            else {
                x.push_back(i+1);
                swap(p[i], p[i+1]);
            }
        }
    }
    int k = x.size();
    cout << k << endl;
    rep(i, k) cout << x[i] << (i<k-1?' ':'\n');
    return 0;
}
