// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto dist = [&](int i, int j) {
        double dx = (x[i] - x[j]);
        double dy = (y[i] - y[j]);
        return sqrt(dx * dx + dy * dy);
    };
    vector<int> p(n);
    rep(i, n) p[i] = i;
    double len = 0.0;
    int cnt = 0;
    do {
        rep(i, n-1) len += dist(p[i], p[i+1]);
        ++cnt;
    } while (next_permutation(all(p)));
    double ans = len / cnt;
    printf("%.10f\n", ans);
    return 0;
}
